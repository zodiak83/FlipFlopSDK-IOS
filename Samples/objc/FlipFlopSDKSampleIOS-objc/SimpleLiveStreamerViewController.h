//
//  SimpleLiveStreamerViewController.h
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/03.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SimpleLiveStreamerViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIView *preview;
@property (weak, nonatomic) IBOutlet UIButton *btnUserCount;
@property (weak, nonatomic) IBOutlet UILabel *viewOnAir;
@property (weak, nonatomic) IBOutlet UICollectionView *collectionGoods;
@property (weak, nonatomic) IBOutlet UITextView *textChatView;

@end

NS_ASSUME_NONNULL_END
