//
//  SimpleListPlayerViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/08/18.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "SimpleListPlayerViewController.h"
#import <AVFoundation/AVFoundation.h>
#import "PlayerCell.h"

@interface SimpleListPlayerViewController()
{
    FlipFlop *sdk;
    __weak IBOutlet UITableView *tableView;
}
@end
@implementation SimpleListPlayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    // 중복되지 않은 USER_ID를 입력하세요 (알파벳 + 숫자 조합)
    [FlipFlop authenticationWithUserID:@"1234" userName:@"" avatarProfileURL:@"" onSuccess:^(FlipFlop * sdk) {
        self->sdk = sdk;
        

        [self->tableView registerNib:[UINib nibWithNibName:@"PlayerCell" bundle:nil] forCellReuseIdentifier:@"PlayerCell"];
        [self->tableView setRowHeight:400];
        [self->tableView setDataSource:self];
        [self->tableView setDelegate:self];
        
    } onFailure:^(FFError *error) {
        NSLog(@"error : %@",[error message]);
    }];

}
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    for (FFAVPlayer *player in [SimpleListPlayerViewController players: sdk]) {
        [player reset];
    }
}
+ (NSArray*) players: (FlipFlop *)sdk {
    
    return [NSArray arrayWithObjects:
            
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/11246/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/11099/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/11098/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/11094/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/10967/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/10928/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/10936/vod.mp4"],
            [sdk getAVPlayerWithDataSourceURL:@"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/10905/vod.mp4"],
            
            nil];
}
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"willDisplayCell: %ld",indexPath.item);
    if ([[tableView indexPathsForVisibleRows] containsObject:indexPath]) {
        
        PlayerCell *c = (PlayerCell*)cell;
        c.player.isMuted = true;
        c.player.delegate = c;
        [c.player prepareWithView:c.playView];
        [c.player startImmediately];
    }
}
- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"didEndDisplayingCell: %ld",indexPath.item);
    PlayerCell *c = (PlayerCell*)cell;
    [c.player reset];
}
- (nonnull UITableViewCell *)tableView:(nonnull UITableView *)tableView cellForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    NSLog(@"cellForRowAtIndexPath: %ld",indexPath.item);
    PlayerCell *cell = (PlayerCell*)[tableView dequeueReusableCellWithIdentifier:@"PlayerCell" forIndexPath:indexPath];
    cell.player = [[SimpleListPlayerViewController players: sdk] objectAtIndex:indexPath.item];
    cell.tag = indexPath.item;
    return cell;
}

- (NSInteger)tableView:(nonnull UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [SimpleListPlayerViewController players: sdk].count;
}

@end
