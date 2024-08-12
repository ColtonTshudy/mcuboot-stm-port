// TODO implement printf for stm

#pragma once

#include "mcuboot_config.h"

#define MCUBOOT_LOG_LEVEL_OFF 0
#define MCUBOOT_LOG_LEVEL_ERROR 1
#define MCUBOOT_LOG_LEVEL_WARNING 2
#define MCUBOOT_LOG_LEVEL_INFO 3
#define MCUBOOT_LOG_LEVEL_DEBUG 4

#ifndef MCUBOOT_LOG_LEVEL
#define MCUBOOT_LOG_LEVEL MCUBOOT_LOG_LEVEL_INFO
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_ERROR
#define MCUBOOT_LOG_ERR(_fmt, ...) \
    do                             \
    {                              \
        ;                          \
    } while (0)

// implement a command like this: uart_printf(TARGET " [ERR] " _fmt "\n\r", ##__VA_ARGS__);
#else
#define MCUBOOT_LOG_ERR(_fmt, ...)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_WARNING
#define MCUBOOT_LOG_WRN(_fmt, ...) \
    do                             \
    {                              \
        ;                          \
    } while (0)
#else
#define MCUBOOT_LOG_WRN(_fmt, ...)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_INFO
#define MCUBOOT_LOG_INF(_fmt, ...) \
    do                             \
    {                              \
        ;                          \
    } while (0)
#else
#define MCUBOOT_LOG_INF(_fmt, ...)
#endif

#if MCUBOOT_LOG_LEVEL >= MCUBOOT_LOG_LEVEL_DEBUG
#define MCUBOOT_LOG_DBG(_fmt, ...) \
    do                             \
    {                              \
        ;                          \
    } while (0)
#else
#define MCUBOOT_LOG_DBG(_fmt, ...)
#endif

// #define MCUBOOT_LOG_MODULE_DECLARE(...)
// #define MCUBOOT_LOG_MODULE_REGISTER(...)

// This definition gets rid of annoying compiler warnings
#define MCUBOOT_LOG_MODULE_DECLARE(module) extern int dummy_##module
#define MCUBOOT_LOG_MODULE_REGISTER(module) extern int dummy_##module