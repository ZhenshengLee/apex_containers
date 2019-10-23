/// \copyright Copyright 2017-2018 Apex.AI, Inc.
/// All rights reserved.
/// \file
/// \brief This file provides visibility control for apex containers shared library

#ifndef CONTAINERS__VISIBILITY_CONTROL_HPP_
#define CONTAINERS__VISIBILITY_CONTROL_HPP_

#include <apexutils/apexdef.h>

////////////////////////////////////////////////////////////////////////////////
#if defined(APEX_WINDOWS)
  #if defined(APEXCPP_BUILDING_DLL) || defined(APEXCPP_EXPORTS)
    #define CONTAINERS_PUBLIC __declspec(dllexport)
    #define CONTAINERS_LOCAL
  #else  // defined(APEXCPP_BUILDING_DLL) || defined(APEXCPP_EXPORTS)
    #define CONTAINERS_PUBLIC __declspec(dllimport)
    #define CONTAINERS_LOCAL
  #endif  // defined(APEXCPP_BUILDING_DLL) || defined(APEXCPP_EXPORTS)
#elif defined(APEX_LINUX)
  #define CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#elif defined(APEX_OSX)
  #define CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#elif defined(APEX_QNX)
  #define CONTAINERS_PUBLIC __attribute__((visibility("default")))
  #define CONTAINERS_LOCAL __attribute__((visibility("hidden")))
#else  // defined(APEX_LINUX)
  #error "Unsupported Build Configuration"
#endif  // defined(APEX_WINDOWS)

#endif  // CONTAINERS__VISIBILITY_CONTROL_HPP_
