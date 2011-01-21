//
//  PusherEventsAppDelegate.h
//  PusherEvents
//
//  Created by Luke Redpath on 22/03/2010.
//  Copyright LJR Software Limited 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PTPusherDelegate.h"
#import "PTPusherChannelDelegate.h"

@class PusherEventsViewController;
@class PTPusher;

@interface PusherEventsAppDelegate : NSObject <UIApplicationDelegate, PTPusherDelegate, PTPusherChannelDelegate> {
	UIWindow *window;
	UINavigationController *navigationController;
	PTPusher *pusher;
	IBOutlet PusherEventsViewController *eventsController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UINavigationController *navigationController;
@property (nonatomic, retain) IBOutlet PusherEventsViewController *eventsController;

@property (nonatomic, retain) PTPusher *pusher;
@end

