//
//  main.m
//  TestObjc
//
//  Created by bob on 2021/8/29.
//

#import <Foundation/Foundation.h>
#import "TestPerson.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        TestPerson *p = [[TestPerson alloc] init];
        NSLog(@"Hello, World! %p", p);
    }
    return 0;
}
