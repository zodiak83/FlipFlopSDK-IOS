//
//  SimpleLivePlayerViewController.h
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/04.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FlipFlopSDK/FlipFlopSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface SimpleLivePlayerViewController : UIViewController<FFPlayerDelegate>

@property (nonatomic) FFPlayer *player;
@property (nonatomic) FFVideoInfo *videoInfo;

@property (weak, nonatomic) IBOutlet UIView *viewPlayer;
@property (weak, nonatomic) IBOutlet UISlider *seekbar;
@property (weak, nonatomic) IBOutlet UIStackView *viewPlayerCommand;
@property (weak, nonatomic) IBOutlet UIButton *btnPlayAndPause;
@property (weak, nonatomic) IBOutlet UILabel *labelCurrentTime;
@property (weak, nonatomic) IBOutlet UILabel *labelDuration;
@property (weak, nonatomic) IBOutlet UIButton *viewOnAir;
@property (weak, nonatomic) IBOutlet UICollectionView *collectionGoods;
@property (weak, nonatomic) IBOutlet UIStackView *viewInputChat;
@property (weak, nonatomic) IBOutlet UITextField *textfieldInput;
@property (weak, nonatomic) IBOutlet UITextView *textChatView;

@end

NS_ASSUME_NONNULL_END
