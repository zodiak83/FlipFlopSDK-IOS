//
//  SimpleLiveStreamerViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/09/03.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "SimpleLiveStreamerViewController.h"
#import <FlipFlopSDK/FlipFlopSDK.h>
#import "GoodsCell.h"

@interface SimpleLiveStreamerViewController ()<FFStreamerDelegate, UICollectionViewDataSource>
{
    FlipFlop *sdk;
    FFStreamer *streamer;
    NSArray *goods;
}
@end

@implementation SimpleLiveStreamerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    goods = [[self goodsList] objectForKey:@"goods_list"];
    [_collectionGoods registerNib:[UINib nibWithNibName:@"GoodsCell" bundle:NULL] forCellWithReuseIdentifier:@"GoodsCell"];
    [_collectionGoods setDataSource: self];
    [_collectionGoods reloadData];
     
}

- (NSDictionary*) goodsList {
    NSDictionary *goods = @{
        @"goods_list": @[
            @{
                @"id": @1,
                @"title": @"무드 레시피 레이스 블러쉬",
                @"thumbnail_url": @"https://shop-phinf.pstatic.net/20190115_111/skintoktalk_1547534269607gspMb_JPEG/70841429225391267_1684561795.jpg?type=m510",
                @"price": @11150
            },
            @{
                @"id": @2,
                @"title": @"해피바스 한장 샤워티슈",
                @"thumbnail_url": @"https://shop-phinf.pstatic.net/20190528_286/outrun_1559002838548CKVPz_JPEG/41721697397965005_925796858.jpg?type=m510",
                @"price": @4900
            },
            @{
                @"id": @3,
                @"title": @"[밀리마쥬] 무료배송 베스풀 블러셔",
                @"thumbnail_url": @"https://shop-phinf.pstatic.net/20180319_79/hcmnt01_1521432991594x1Rtm_JPEG/44740151216675877_466425841.jpg?type=m450",
                @"price": @12000
            },
            @{
                @"id": @4,
                @"title": @"려 자양윤모 트리트먼트 200ml",
                @"thumbnail_url": @"https://shop-phinf.pstatic.net/20190510_295/outrun_1557451917414UQYjN_JPEG/80758218041478328_924887128.jpg?type=m510",
                @"price": @5000
            },
            @{
                @"id": @5,
                @"title": @"[3CE] 벨벳 립 틴트 4g",
                @"thumbnail_url": @"https://shop-phinf.pstatic.net/20181228_46/skintoktalk_1545962390562vaoSw_JPEG/28593570204060548_313533979.jpg?type=m510",
                @"price": @9170
            }
        ]
    };
    return goods;
}
- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    CFAbsoluteTime timeInSeconds = CFAbsoluteTimeGetCurrent();
    NSString *userID = [NSString stringWithFormat:@"%.0f",timeInSeconds];
    [FlipFlop authenticationWithUserID:userID userName:@"" avatarProfileURL:@"" onSuccess:^(FlipFlop * sdk) {
        self->sdk = sdk;
        FFStreamer *streamer = [sdk getStreamer];
        self->streamer = streamer;
        [streamer setDelegate:self];
        [streamer prepareWithPreview:self->_preview config:NULL];
        
        [self showAlert];
    } onFailure:^(FFError *error) {
        NSLog(@"error : %@",[error message]);
    }];
}
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [streamer stop];
    [streamer reset];
}
- (void) startWithTitle: (NSString*) title content: (NSString*) content {
    
    
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject: [self goodsList] options:NSJSONWritingPrettyPrinted error:&error];
    if (error != NULL) {
        NSLog(@"error: %@",error);
        return;
    }
    NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    [streamer startWithTitle:title content:content jsonGoods: jsonString];
}
- (void) showAlert {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"" message:@"방송 제목과 내용을 입력해주세요" preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {

    }];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {

    }];

    UIAlertAction *closeAction = [UIAlertAction actionWithTitle:@"닫기" style:UIAlertActionStyleCancel handler:nil];

    UIAlertAction *startAction = [UIAlertAction actionWithTitle:@"시작" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {

        [self startWithTitle:alert.textFields[0].text content:alert.textFields[1].text];
    }];


    [alert addAction:closeAction];
    [alert addAction:startAction];

    

    [self presentViewController:alert animated:YES completion:nil];
}
- (void)onPrepared {




    
}
- (void)onStartedWithStreamName:(NSString *)streamName {
    NSLog(@"onStartedWithStreamName: %@\n", streamName);
    [_viewOnAir setHidden:NO];
}

- (void) onStopped {
    [_viewOnAir setHidden:YES];
}

- (void) onCompleted {
    
}
- (void)onErrorWithError:(FFError *)error {
    NSLog(@"error: %@\n",[error description]);
}
- (void)onChatStatReceivedWithStat:(FFStat *)stat {
    
}
- (void)onChatMessgeReceivedWithMessage:(FFMessage *)message {
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
@end
