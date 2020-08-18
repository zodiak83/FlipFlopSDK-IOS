//
//  PlayerCell.h
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/08/18.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FlipFlopSDK/FlipFlopSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface PlayerCell : UITableViewCell<PlayerDelegate>

@property (weak, nonatomic) IBOutlet UIView *playView;
@property FFAVPlayer *player;
@end

NS_ASSUME_NONNULL_END
