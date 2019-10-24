// Copyright 2019 Apex.AI, Inc.
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

#ifndef APEX_CONTAINERS__APEXDEF_H_
#define APEX_CONTAINERS__APEXDEF_H_

#include <stdint.h>

// typedef bool bool;
typedef char char8_t;
typedef float float32_t;
typedef double float64_t;
typedef uint64_t size64_t;

typedef int32_t apex_ret_t;

/// \def APEX_RET_OK
/// \brief Define OK return status
#define APEX_RET_OK (0)

/// \def APEX_RET_ERROR
/// \brief Define error return status (!= 0)
#define APEX_RET_ERROR (-1)

/// \def APEX_STRING_SIZE
/// \brief Define Apex.OS fixed size string
#define APEX_STRING_SIZE (256ULL)

#endif  // APEX_CONTAINERS__APEXDEF_H_
