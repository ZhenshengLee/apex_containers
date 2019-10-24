// Copyright 2017-2019 Apex.AI, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef APEX_CONTAINERS__VISIBILITY_CONTROL_H_
#define APEX_CONTAINERS__VISIBILITY_CONTROL_H_


////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(APEX_CONTAINERS_BUILDING_DLL) || defined(APEX_CONTAINERS_EXPORTS)
    #define APEX_CONTAINERS_PUBLIC __declspec(dllexport)
    #define APEX_CONTAINERS_LOCAL
  #else  // defined(APEX_CONTAINERS_BUILDING_DLL) || defined(APEX_CONTAINERS_EXPORTS)
    #define APEX_CONTAINERS_PUBLIC __declspec(dllimport)
    #define APEX_CONTAINERS_LOCAL
  #endif  // defined(APEX_CONTAINERS_BUILDING_DLL) || defined(APEX_CONTAINERS_EXPORTS)
#elif defined(__linux__)
  #define APEX_CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define APEX_CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define APEX_CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define APEX_CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#elif defined(QNX)
  #define APEX_CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define APEX_CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#else  // defined(__linux__)
  #error "Unsupported Build Configuration"
#endif  // defined(__WIN32)
#endif  // APEX_CONTAINERS__VISIBILITY_CONTROL_H_
