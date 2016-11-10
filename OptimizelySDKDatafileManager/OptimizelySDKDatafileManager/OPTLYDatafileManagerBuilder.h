/****************************************************************************
 * Copyright 2016, Optimizely, Inc. and contributors                        *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *    http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ***************************************************************************/

#import <Foundation/Foundation.h>

@class OPTLYDatafileManagerBuilder;

/// This is a block that takes the biulder values
typedef void (^OPTLYDatafileManagerBuilderBlock)(OPTLYDatafileManagerBuilder * _Nullable builder);

@interface OPTLYDatafileManagerBuilder : NSObject

/// The time interval to regularly fetch the datafile.
@property (nonatomic, readwrite) NSTimeInterval datafileFetchInterval;

/// Create an Optimizely Datafile Manager Builder object.
+ (nullable instancetype)builderWithBlock:(nonnull OPTLYDatafileManagerBuilderBlock)block;

@end