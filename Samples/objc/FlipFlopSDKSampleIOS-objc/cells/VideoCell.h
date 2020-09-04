//
//  VideoCell.h
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/04.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface VideoCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *imgVideoThumb;
@property (weak, nonatomic) IBOutlet UILabel *labelVideoDuration;
@property (weak, nonatomic) IBOutlet UILabel *labelLive;

@property (weak, nonatomic) IBOutlet UIImageView *imgUserProfile;
@property (weak, nonatomic) IBOutlet UILabel *labelUserID;
@property (weak, nonatomic) IBOutlet UILabel *labelUserName;

@property (weak, nonatomic) IBOutlet UILabel *labelVideoTitle;
@property (weak, nonatomic) IBOutlet UILabel *labelVideoContent;

@property (weak, nonatomic) IBOutlet UILabel *labelVideoViewCount;
@property (weak, nonatomic) IBOutlet UILabel *labelVideoCreated;

@end

NS_ASSUME_NONNULL_END
