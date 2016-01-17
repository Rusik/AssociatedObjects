//
//  NSObject+AssociatedObjects.h
//
//  Created by Ruslan Kavetsky.
//  Copyright (c) 2014 Ruslan Kavetsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AssociatedObjects)

#define AssociatedObjectKey(key) @selector(key)

- (void)setAssociatedObject:(id)object forKey:(void *)key;
- (void)setAssociatedWeekObject:(id)object forKey:(void *)key;
- (void)removeAssociatedObjectForKey:(void *)key;
- (id)associatedObjectForKey:(void *)key;

@end
