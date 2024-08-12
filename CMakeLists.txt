cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# My settings
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")
set (CONFIG_DIR ${CMAKE_SOURCE_DIR}/Config)
set (BOOTUTIL_DIR ${CMAKE_SOURCE_DIR}/External/bootutil)
set (TINYCRYPT_DIR ${CMAKE_SOURCE_DIR}/External/tinycrypt/lib)
# set (MBEDTLS_DIR ${CMAKE_SOURCE_DIR}/External/mbedtls/include)
set(bootutil_srcs
    ${BOOTUTIL_DIR}/src/boot_record.c
    ${BOOTUTIL_DIR}/src/bootutil_misc.c
    ${BOOTUTIL_DIR}/src/bootutil_public.c
    ${BOOTUTIL_DIR}/src/caps.c
    ${BOOTUTIL_DIR}/src/encrypted.c
    ${BOOTUTIL_DIR}/src/fault_injection_hardening.c
    ${BOOTUTIL_DIR}/src/fault_injection_hardening_delay_rng_mbedtls.c
    ${BOOTUTIL_DIR}/src/image_ecdsa.c
    ${BOOTUTIL_DIR}/src/image_ed25519.c
    ${BOOTUTIL_DIR}/src/image_rsa.c
    ${BOOTUTIL_DIR}/src/image_validate.c
    ${BOOTUTIL_DIR}/src/loader.c
    ${BOOTUTIL_DIR}/src/swap_misc.c
    ${BOOTUTIL_DIR}/src/swap_move.c
    ${BOOTUTIL_DIR}/src/swap_scratch.c
    ${BOOTUTIL_DIR}/src/tlv.c
)
set(crypto_srcs
    ${TINYCRYPT_DIR}/source/sha256.c
    ${TINYCRYPT_DIR}/source/utils.c
)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME port)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${crypto_srcs}
    ${bootutil_srcs}
    ${MBEDTLS_DIR}
)

# # Add include paths to vscode
# include_directories(${CMAKE_PROJECT_NAME} PRIVATE
#     # Add user defined include paths
#     ${BOOTUTIL_DIR}/include
#     ${BOOTUTIL_DIR}/src
#     ${TINYCRYPT_DIR}/include
#     ${TINYCRYPT_DIR}/source
#     ${CONFIG_DIR}
# )

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ${BOOTUTIL_DIR}/include
    ${BOOTUTIL_DIR}/src
    ${TINYCRYPT_DIR}/include
    ${TINYCRYPT_DIR}/source
    ${CONFIG_DIR}
    ${MBEDTLS_DIR}
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
