//
//  ViewController.m
//  FlipFlopSDKSampleIOS-objc
//
//  Created by Jeon HyungGue on 2020/08/18.
//  Copyright © 2020 Jeon HyungGue. All rights reserved.
//

#import "ViewController.h"
#import <UIKit/UIKit.h>
@interface ViewController ()
{
    
}
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    switch (indexPath.item) {
        case 0:
        {
            UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"SimplePlayerViewController"];
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
        case 1:
        {
            UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"SimpleListPlayerViewController"];
            [self.navigationController pushViewController:vc animated:YES];
            break;
        }
        case 2:
        {
            UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"SimpleLiveStreamerViewController"];
            [self.navigationController pushViewController:vc animated:YES];
            break;
        }
        case 3:
        {
            UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"SimpleVideoListViewController"];
            [self.navigationController pushViewController:vc animated:YES];
            break;
        }
        default:
            break;
    }
}

@end
