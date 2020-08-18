//
//  SimplePlayerViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/08/18.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "SimplePlayerViewController.h"
#import <AVFoundation/AVFoundation.h>

NSString *url = @"https://s3.ap-northeast-2.amazonaws.com/flipflop-prod/9z27htVnKe/videos/11246/vod.mp4";

@implementation SimplePlayerViewController
{
    FFAVPlayer *_player;
    __weak IBOutlet UIButton *btnStartAndStop;
    __weak IBOutlet UIButton *btnVideoGravity;
    __weak IBOutlet UILabel *labelDuration;
    __weak IBOutlet UIButton *btnMute;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // 중복되지 않은 USER_ID를 입력하세요 (알파벳 + 숫자 조합)
    [FlipFlop authenticationWithUserID:@"1234" userName:@"" avatarProfileURL:@"" onSuccess:^(FlipFlop * sdk) {
        self->_player = [sdk getAVPlayerWithDataSourceURL: url];
        self->_player.delegate = self;
        self->_player.isRepeat = YES;
        [self->_player prepareWithView:self.view];
    } onFailure:^(FFError *error) {
        NSLog(@"error : %@",[error message]);
    }];
}
- (IBAction)onStartAndStop:(id)sender {
    if ([btnStartAndStop isSelected]) {
        [_player stop];

        [btnStartAndStop setSelected:NO];
    } else {
        [_player start];
    }
    
}
- (IBAction)onMute:(id)sender {
    if ([btnMute isSelected]) {
        [_player setIsMuted:NO];
    } else {
        [_player setIsMuted:YES];
    }
    [btnMute setSelected:![btnMute isSelected]];
}
- (IBAction)onVideoGravity:(id)sender {
    if ([btnVideoGravity isSelected]) {
        [_player setVideoGravity:AVLayerVideoGravityResizeAspectFill];
    } else {
        [_player setVideoGravity:AVLayerVideoGravityResizeAspect];
    }
    
    [btnVideoGravity setSelected:![btnVideoGravity isSelected]];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [_player reset];
    _player = nil;
}
- (void)onBufferingEndedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onBufferingStartedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onCompletedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onErrorWithPlayer:(id<Player> _Nonnull)player error:(enum PlayerError)error {
    
}


- (void)onPausedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onPlaybackDownloadUpdatedWithPlayer:(id<Player> _Nonnull)player percent:(double)percent {
    
}


- (void)onProgressUpdatedWithPlayer:(id<Player> _Nonnull)player percent:(double)percent mSec:(uint64_t)mSec {
    
}


- (void)onResumedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onSeekCompletedWithPlayer:(id<Player> _Nonnull)player percent:(double)percent mSec:(uint64_t)mSec {
    
}

- (void)onPreparedWithPlayer:(id<Player>)player {
    
    [labelDuration setText: [[NSString alloc] initWithFormat:@"%.2f초",player.duration]];
    [player start];
}

- (void)onStartedWithPlayer:(id<Player> _Nonnull)player {
    [btnStartAndStop setSelected:YES];
}


- (void)onStoppedWithPlayer:(id<Player> _Nonnull)player {
    
}


- (void)onVideoResolutionSizeWithPlayer:(id<Player> _Nonnull)player size:(CGSize)size {
    
}

@end
