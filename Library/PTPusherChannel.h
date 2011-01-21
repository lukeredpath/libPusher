//
//  PTPusherClient.h
//  libPusher
//
//  Created by Luke Redpath on 23/04/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PTPusher.h"
#import "PTPusherDelegate.h"
#import "PTPusherChannelDelegate.h"

#define kPrivateChannelPrefix @"private-"
#define kPresenseChannelPrefix @"presence-"

@interface PTPusherChannel : NSObject <PTPusherChannelProtocol> {
	NSString *name;
	NSURL *authPoint;

	NSOperationQueue *operationQueue;
	PTPusher *pusher;
	
	BOOL isPrivate;
	BOOL isPresence;
	
	id <PTPusherDelegate, PTPusherChannelDelegate> delegate;
}
@property (nonatomic, readonly)		NSString *name;
@property (nonatomic, retain)		NSURL *authPoint;
@property (nonatomic, readonly)		PTPusher *pusher;
@property (nonatomic, readonly)		BOOL isPrivate;
@property (nonatomic, readonly)		BOOL isPresence;

@property (nonatomic, assign)		id <PTPusherDelegate, PTPusherChannelDelegate> delegate;

- (id)initWithName:(NSString *)_name pusher:(PTPusher *)_pusher;

- (NSData *)authenticateWithSocketID:(NSString *)_socketID;

- (void)triggerEvent:(NSString *)name data:(id)data;
@end

@interface PTPusherClientOperation : NSOperation {
	NSURL *url;
	NSString *body;
	PTPusherChannel *channel;
	id<PTPusherChannelDelegate> delegate;
}
@property (nonatomic, assign) id <PTPusherChannelDelegate> delegate;
@property (nonatomic, retain) PTPusherChannel *channel;

- (id)initWithURL:(NSURL *)_url JSONString:(NSString *)json;
@end

