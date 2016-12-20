//
//  NSObject+AssociatedObjects.h
//
//  Created by Ruslan Kavetsky.
//  Copyright (c) 2014 Ruslan Kavetsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AssociatedObjects)

#define AssociatedObjects_Key(key) @selector(key)

#define AssociatedObjects_generateObjectGetter(type, getter)\
- (type)getter {                                          \
    return [self associatedObjectForKey:AssociatedObjects_Key(getter)]; \
}                                                           \

#define AssociatedObjects_generateObjectSetter(type, getter, setter)\
- (void)setter:(type)v {                                  \
    [self setAssociatedObject:v forKey:AssociatedObjects_Key(getter)];  \
}                                                           \

#define AssociatedObjects_generatePrimitiveGetter(type, getter, unwrapMethod)\
- (type)getter {                                                    \
    return [[self associatedObjectForKey:AssociatedObjects_Key(getter)] unwrapMethod];  \
}                                                                   \

#define AssociatedObjects_generatePrimitiveSetter(type, getter, setter)\
- (void)setter:(type)v {                                        \
    [self setAssociatedObject:@(v) forKey:AssociatedObjects_Key(getter)];   \
}                                                               \

#define AssociatedObjects_generateForObject(type, getter, setter)\
AssociatedObjects_generateObjectGetter(type, getter)\
AssociatedObjects_generateObjectSetter(type, getter, setter)\

#define AssociatedObjects_generateForPrimitive(type, getter, setter, unwrapMethod)\
AssociatedObjects_generatePrimitiveGetter(type, getter, unwrapMethod)\
AssociatedObjects_generatePrimitiveSetter(type, getter, setter)

- (void)setAssociatedObject:(id)object forKey:(void *)key;
- (void)setAssociatedWeekObject:(id)object forKey:(void *)key;
- (void)removeAssociatedObjectForKey:(void *)key;
- (id)associatedObjectForKey:(void *)key;

@end
