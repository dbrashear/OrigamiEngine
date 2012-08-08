//
//  ORGMCommonProtocols.h
//  OrigamiEngine
//
//  Created by ap4y on 8/8/12.
//
//

@protocol ORGMEngineObject <NSObject>
+ (NSArray*)fileTypes;
- (NSString*)mimeType;
@end

@protocol ORGMSource <ORGMEngineObject>
+ (NSArray*)schemes;

- (NSURL*)url;
- (long)size;

- (BOOL)open:(NSURL*)url;
- (BOOL)seekable;
- (BOOL)seek:(long)position whence:(int)whence;
- (long)tell;
- (int)read:(void*)buffer amount:(int)amount;
- (void)close;
@end

@protocol ORMGContainer <ORGMEngineObject>
+ (NSArray*)urlsForContainerURL:(NSURL*)url;
@end

@protocol ORGMDecoder <ORGMEngineObject>
@required
- (NSDictionary*)properties;

- (int)readAudio:(void*)buffer frames:(UInt32)frames;
- (BOOL)open:(id<ORGMSource>)source;
- (long)seek:(long)frame;
- (void)close;
@end

@protocol ORGMMetadataReader <ORGMEngineObject>
+ (NSDictionary *)metadataForURL:(NSURL *)url;
@end