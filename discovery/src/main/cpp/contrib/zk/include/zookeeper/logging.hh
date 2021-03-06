/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. The ASF
 * licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 *  the License.
 */
#ifndef LOGGING_H_
#define LOGGING_H_

#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/version.hpp>
#include <log4cxx/logger.h>
#include <string>

#define LOG_DEBUG(message) LOG4CXX_DEBUG(logger, message)
#define LOG_INFO(message) LOG4CXX_DEBUG(logger, message)
#define LOG_WARN(message) LOG4CXX_DEBUG(logger, message)
#define LOG_ERROR(message) LOG4CXX_DEBUG(logger, message)

#if BOOST_VERSION / 100 % 1000 >= 46
#define ENABLE_LOGGING static log4cxx::LoggerPtr logger(\
  log4cxx::Logger::getLogger(\
  boost::filesystem::path(__FILE__).filename().string()));
#else
#define ENABLE_LOGGING static log4cxx::LoggerPtr logger(\
  log4cxx::Logger::getLogger(\
  boost::filesystem::path(__FILE__).filename()));
#endif

#endif  // LOGGING_H_
