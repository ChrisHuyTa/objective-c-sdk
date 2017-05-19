/****************************************************************************
 * Copyright 2017, Optimizely, Inc. and contributors                        *
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

#import <JSONModel/JSONModel.h>

@class OPTLYExperiment, OPTLYVariation;

@interface OPTLYDecisionService : JSONModel

/**
 * Initializer for the Decision Service.
 *
 * @param config The project configuration
 * @param bucketer The bucketer.
 * @return An instance of the decision service.
 */
- (nullable instancetype)initWithProjectConfig:(nonnull OPTLYProjectConfig *)config
                                      bucketer:(nonnull id<OPTLYBucketer>)bucketer;

/**
 * Gets a variation based on the following rules:
 *
 * 1. Experiments not running will return a nil variation.
 * 2. If the user is whitelisted for a particular variation, 
 *    then that variation will be returned.
 * 3. If a valid variation is found in the user profile service, 
 *    then that variation will be returned.
 * 4. If the user falls through #1-3, than the user will be bucketed
 *    if the user fulfills these criteria:
 *      a. Does the user pass audience targeting?
 *      b. Is the experiment that the user bucketed into NOT mutually excluded?
 *      c. Does traffic allocation exclude the user?
 *
 * @param userId The ID of the user.
 * @param experiment The experiment in which to bucket the user.
 * @return The variation assigned to the specified user ID for an experiment.
 */
- (nullable OPTLYVariation *)getVariation:(nonnull NSString *)userId
                               experiment:(nonnull OPTLYExperiment *)experiment
                               attributes:(nullable NSDictionary *)attributes;

/**
 * Saves an experiment bucket information for a user.
 *
 * @param userId The ID of the user.
 * @param experiment The experiment in which to bucket the user.
 * @param variation The variation assigned to the specified user for an experiment.
 */
- (void)saveVariation:(nonnull OPTLYVariation *)variation
           experiment:(nonnull OPTLYExperiment *)experiment
               userId:(nonnull NSString *)userId;
@end