#
# Copyright (c) 2019 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(uut_test)

# Generate runner for the test
test_runner_generate(src/uut_test.c)

set(ROOTDIR ../..)

# Create mocks
cmock_handle(${ROOTDIR}/src/foo/foo.h)
target_include_directories(app PRIVATE ${ROOTDIR}/src)
target_include_directories(app PRIVATE ${ROOTDIR}/src/foo)

# Include target sources
target_sources(app PRIVATE ${ROOTDIR}/src/uut/uut.c)
target_include_directories(app PRIVATE ${ROOTDIR}/src/uut)

# add test file
target_sources(app PRIVATE src/uut_test.c)

target_include_directories(app PRIVATE .)
target_include_directories(app PRIVATE src)

# Preinclude file to the module under test to redefine IS_ENABLED() macro
# which is used in the module.
set_property(SOURCE ${ROOTDIR}/src/uut/uut.c PROPERTY COMPILE_FLAGS
	"-include src/uut_test.h")
