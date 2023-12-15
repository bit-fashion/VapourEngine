/* ************************************************************************
 *
 * Copyright (C) 2022 Vincent Luo All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, e1ither express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/* Creates on 2022/9/14. */
#pragma once

#include <iostream>
#include <stdexcept>
#include <format>
#include <memory>

// in project
#include "Config.h"
#include "Typedef.h"

#define SPORTS_ENGINE_NAME "SportsEngine"

/* logger */
#define SPORTS_LOGGER_INFO(fmt, ...) printf("%s\n", std::format(fmt, ##__VA_ARGS__).c_str())
#define SPORTS_LOGGER_ERROR(fmt, ...) printf("%s\n", std::format(fmt, ##__VA_ARGS__).c_str())
#define SPORTS_THROW_ERROR(fmt, ...) throw std::runtime_error(std::format(fmt, ##__VA_ARGS__))

/* Get total byte size of array. */
#define ARRAY_TOTAL_SIZE(a) (sizeof(a[0]) * std::size(a))

#define SPORTS_MEMORY_INIT {}

/* define SPORTS_API export */
#if defined(_WIN32)
#  define SPORTS_API __stdcall
#elif
#  define SPORTS_API
#endif

#define SPORTS_ALWAYS_INLINE inline __attribute__((always_inline))