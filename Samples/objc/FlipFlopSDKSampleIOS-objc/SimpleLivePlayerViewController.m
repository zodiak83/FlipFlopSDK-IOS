//
//  SimpleLivePlayerViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/04.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "SimpleLivePlayerViewController.h"
#import "GoodsCell.h"

@interface SimpleLivePlayerViewController ()<UICollectionViewDataSource, UITextFieldDelegate>
{
    BOOL isPlaybackCompleted;
    NSDateComponentsFormatter *timeFormatter;
    NSArray *goods;
}

@end

@implementation SimpleLivePlayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Video List";
    // Do any additional setup after loading the view.
    [_player setDelegate:self];
    
    [_textfieldInput setDelegate: self];
    timeFormatter = [[NSDateComponentsFormatter alloc] init];
    [timeFormatter setAllowedUnits:(NSCalendarUnitMinute | NSCalendarUnitSecond)];
    [timeFormatter setZeroFormattingBehavior:NSDateComponentsFormatterZeroFormattingBehaviorPad];
    
    [_labelDuration setText: [timeFormatter stringFromTimeInterval:_videoInfo.duration / 1000]];
    NSString *videoGoods = [_videoInfo getGoods];
    
    NSError *error;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:[videoGoods dataUsingEncoding:NSUTF8StringEncoding] options:0 error:&error];
    
    if (error != NULL) {
        NSLog(@"error: %@", [error description]);
    }
    goods = [dic objectForKey:@"goods_list"];
    [_collectionGoods registerNib:[UINib nibWithNibName:@"GoodsCell" bundle:NULL] forCellWithReuseIdentifier:@"GoodsCell"];
    [_collectionGoods setDataSource: self];
    [_collectionGoods reloadData];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [_player prepareWithView: _viewPlayer];
    if ([_videoInfo.state isEqualToString:@"LIVE"]) {
        [_viewPlayerCommand setHidden: YES];
        [_viewInputChat setHidden:NO];
    } else {
        [_viewPlayerCommand setHidden: NO];
        [_viewInputChat setHidden:YES];
    }
}
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear: animated];
    [_player reset];
}
- (IBAction)onSend:(id)sender {
    NSString *text = [_textfieldInput text];
    [_player sendMessageWithText:text data:NULL customType:NULL];
    [_textfieldInput resignFirstResponder];
    [_textfieldInput setText:@""];
}
- (IBAction)onPlayAndPause:(UIButton*)sender {
    if ([_btnPlayAndPause isSelected]) {
        [_player pause];
    } else {
        if (isPlaybackCompleted) {
            isPlaybackCompleted = NO;
            [_player start];
        } else {
            [_player resume];
        }
    }
    
}
- (IBAction)onSeekValueChanged:(UISlider*)slider forEvent:(UIEvent*)event {
    UITouch *touch = [[[event allTouches] allObjects] firstObject];
    switch (touch.phase) {
        case UITouchPhaseBegan:
            [_player pause];
            break;
        case UITouchPhaseMoved:
            break;
        case UITouchPhaseEnded:
        {
            float value = slider.value;
            if (value >= 0.99) {
                value = 0.999999;
            }
            [_player seekToPercent:value];
            break;
        }
            
        default:
            break;
    }
}

- (void)onPreparedWithPlayer:(FFPlayer *)player {
    [player start];
}
- (void)onStartedWithPlayer:(FFPlayer *)player {
    if ([_videoInfo.state isEqualToString:@"LIVE"]) {
        
        [_viewOnAir setHidden:NO];
    }
    [_btnPlayAndPause setSelected:YES];
}

- (void)onPausedWithPlayer:(FFPlayer *)player {
    [_btnPlayAndPause setSelected:NO];
}
- (void)onResumedWithPlayer:(FFPlayer *)player {
    [_btnPlayAndPause setSelected:YES];
}
- (void)onStoppedWithPlayer:(FFPlayer *)player {
    [_btnPlayAndPause setSelected:NO];
    [_viewOnAir setHidden:YES];
}
- (void)onCompletedWithPlayer:(FFPlayer *)player {
    [_btnPlayAndPause setSelected:NO];
    isPlaybackCompleted = YES;
    NSLog(@"onCompletedWithPlayer");
}
- (void)onProgressUpdatedWithPlayer:(FFPlayer *)player mSec:(uint64_t)mSec {
    float percent = (float)mSec / (float)player.duration;
    [_seekbar setValue:percent];
    
    [_labelCurrentTime setText:[timeFormatter stringFromTimeInterval:(mSec / 1000)]];
}
- (void)onSeekCompletedWithPlayer:(FFPlayer *)player mSec:(uint64_t)mSec {
    
    float percent = (float)mSec / (float)player.duration;
    [_seekbar setValue:percent];
    [player resume];
    
}
- (void)onChatMessgeReceivedWithPlayer:(FFPlayer *)player message:(FFMessage *)message {
    switch (message.type) {
        case FFMessageTypeJoin:
        {
            [_textChatView insertText:[NSString stringWithFormat:@"%@ joined\n", message.userID]];
        }
            break;
        case FFMessageTypeLeave:
        {
            [_textChatView insertText:[NSString stringWithFormat:@"%@ leaved\n", message.userID]];
        }
            
            break;
        case FFMessageTypeMsg:
        {
            [_textChatView insertText:[NSString stringWithFormat:@"message: %@ from %@\n", message.message, message.userID]];
        }
            break;
        default:
            break;
    }
}
- (void)onChatStatReceivedWithPlayer:(FFPlayer *)player stat:(FFStat *)stat {
    
}

- (void)onErrorWithPlayer:(FFPlayer *)player error:(FFError *)error {
    NSLog(@"error: %@\n",[error description]);
}

- (void)onBackgroundWithPlayer:(FFPlayer * _Nonnull)player {
    
}


- (void)onForegroundWithPlayer:(FFPlayer * _Nonnull)player {
    
}


- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return [goods count];
}
- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    GoodsCell *cell = (GoodsCell *)[collectionView dequeueReusableCellWithReuseIdentifier:@"GoodsCell" forIndexPath:indexPath];

    NSDictionary *dic = [goods objectAtIndex:indexPath.item];
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
            
        NSData *data = [[NSData alloc] initWithContentsOfURL:[NSURL URLWithString: dic[@"thumbnail_url"]]];
        UIImage *img = [UIImage imageWithData:data];
        dispatch_queue_t mainQueue = dispatch_get_main_queue();
        dispatch_async(mainQueue, ^{
            cell.imgThumbnail.image = img;
        });

    });
    
    return cell;
}
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [self onSend:textField];
    return YES;
}
@end
