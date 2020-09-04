//
//  SimpleVideoListViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/04.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "SimpleVideoListViewController.h"
#import "VideoCell.h"
#import "SimpleLivePlayerViewController.h"
#import <FlipFlopSDK/FlipFlopSDK.h>

@interface SimpleVideoListViewController ()
{
    FlipFlop *sdk;
    __weak IBOutlet UITableView *tableView;
    NSArray *videos;
    FFVideoListLoader *videoListLoader;
    NSDateComponentsFormatter *timeFormatter;
    NSDateFormatter *dateFormatter;
}
@end

@implementation SimpleVideoListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    timeFormatter = [[NSDateComponentsFormatter alloc] init];
    dateFormatter = [[NSDateFormatter alloc] init];
    
    [timeFormatter setAllowedUnits:(NSCalendarUnitMinute | NSCalendarUnitSecond)];
    [timeFormatter setZeroFormattingBehavior:NSDateComponentsFormatterZeroFormattingBehaviorPad];
    
    [dateFormatter setLocale: [NSLocale currentLocale]];
    [dateFormatter setDateStyle: NSDateFormatterMediumStyle];
    [dateFormatter setTimeStyle: NSDateFormatterMediumStyle];
    
    
    [self->tableView registerNib:[UINib nibWithNibName:@"VideoCell" bundle:nil] forCellReuseIdentifier:@"VideoCell"];
    [self->tableView setRowHeight:200];
    [self->tableView setDataSource:self];
    [self->tableView setDelegate:self];
    
    CFAbsoluteTime timeInSeconds = CFAbsoluteTimeGetCurrent();
    NSString *userID = [NSString stringWithFormat:@"%.0f",timeInSeconds];
    [FlipFlop authenticationWithUserID:userID userName:@"" avatarProfileURL:@"" onSuccess:^(FlipFlop * sdk) {
        self->sdk = sdk;
        self->videoListLoader = [sdk getVideoListLoaderWithCursor:NULL count:20 userID:NULL type:NULL state:NULL];
        
        [self->videoListLoader nextOnSuccess:^(NSArray* videos) {
            
            self->videos = videos;
            
            [self->tableView reloadData];
            
            
        } onFailure:^(NSError * error) {
            NSLog(@"error: %@",[error description]);
        }];
    } onFailure:^(FFError *error) {
        NSLog(@"error : %@",[error message]);
    }];
}

- (nonnull UITableViewCell *)tableView:(nonnull UITableView *)tableView cellForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    VideoCell *cell = (VideoCell*)[tableView dequeueReusableCellWithIdentifier:@"VideoCell" forIndexPath:indexPath];
    FFVideoInfo *video = videos[indexPath.item];
    if ([video.state isEqualToString:@"VOD"]) {
        [cell.labelLive setHidden: YES];
        cell.labelVideoViewCount.text = [[NSString alloc] initWithFormat:@"%llu", video.view_count];
    } else {
        [cell.labelLive setHidden: NO];
        cell.labelVideoViewCount.text = [[NSString alloc] initWithFormat:@"%llu", video.watch_count];
    }
    
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
            
        NSData *data = [[NSData alloc] initWithContentsOfURL:[NSURL URLWithString: video.thumbnail_url]];
        UIImage *img = [UIImage imageWithData:data];
        dispatch_queue_t mainQueue = dispatch_get_main_queue();
        dispatch_async(mainQueue, ^{
            cell.imgVideoThumb.image = img;
        });

    });
    cell.labelUserID.text = video.user_id;
    cell.labelUserName.text = video.user_name;
    
    cell.labelVideoTitle.text = video.title;
    cell.labelVideoContent.text = video.content;
    
    cell.labelVideoDuration.text = [timeFormatter stringFromTimeInterval: video.duration / 1000];
    
    cell.labelVideoCreated.text = [dateFormatter stringFromDate: [[NSDate alloc] initWithTimeIntervalSince1970:video.created_at / 1000]];
    cell.tag = indexPath.item;
    return cell;
}

- (NSInteger)tableView:(nonnull UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [videos count];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    FFVideoInfo *video = videos[indexPath.item];
    SimpleLivePlayerViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:@"SimpleLivePlayerViewController"];
    vc.videoInfo = video;
    vc.player = [sdk getPlayerWithVideo_key:video.video_key];
    [self.navigationController pushViewController:vc animated:YES];
}

@end

