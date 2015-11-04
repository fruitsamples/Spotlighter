/*
 AppController.h

 This is the main controller for the user interface. Most of the work is done by bindings.
 
*/

#import <Cocoa/Cocoa.h>

@interface AppController : NSObject
{
#ifdef OBJC_NEW_PROPERTIES
    NSMetadataQuery *query;
    NSString *searchKey;
    BOOL searchContent;
#endif
}

- (void)queryNote:(NSNotification *)note;

// Through the miracle of bindings, by exposing the query in the controller, we can bind to anything in the query with expressions such as "query.results". The NSArrayController in the nib file named "AllResults" binds to the query results in this matter.
#ifdef OBJC_NEW_PROPERTIES
@property(retain) NSMetadataQuery *query;
#else
@property(ivar) NSMetadataQuery *query;
#endif

// Expose searchKey so that the NSTextField for searching can easily be typed into and update the query as needed
#ifdef OBJC_NEW_PROPERTIES
@property(copy) NSString *searchKey;
#else
@property(ivar,bycopy) NSString *searchKey;
#endif

#ifdef OBJC_NEW_PROPERTIES
@property BOOL searchContent;
#else
@property(ivar) BOOL searchContent;
#endif

@end


