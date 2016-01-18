#import <UIKit/UIKit.h>
#import "MenuItemSourceTextBar.h"
#import "MenuItemSourceOptionView.h"

@class MenuItem;

@protocol MenuItemSourceViewDelegate;

@interface MenuItemSourceView : UIView <MenuItemSourceTextBarDelegate, UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, weak) id <MenuItemSourceViewDelegate> delegate;
@property (nonatomic, strong) MenuItem *item;

/* A stackView for adding any views that aren't cells before the tableView, Ex. searchBar, label, design
 */
@property (nonatomic, strong, readonly) UIStackView *stackView;

/* A tableView for inserting cells of data relating to the source
 */
@property (nonatomic, strong, readonly) UITableView *tableView;

@property (nonatomic, strong) MenuItemSourceTextBar *searchBar;
@property (nonatomic, strong, readonly) NSMutableArray *sourceOptions;

- (void)insertSearchBarIfNeeded;
- (void)insertSourceOption:(MenuItemSourceOption *)option;

@end

@protocol MenuItemSourceViewDelegate <NSObject>

- (void)sourceViewDidBeginEditingWithKeyBoard:(MenuItemSourceView *)sourceView;
- (void)sourceViewDidEndEditingWithKeyboard:(MenuItemSourceView *)sourceView;

@end