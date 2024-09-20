#
# Copyright (c) 2019 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(foo_test)

# Generate runner for the test
test_runner_generate(src/foo_test.c)

set(ROOTDIR ../..)

# Include target sources
target_sources(app PRIVATE ${ROOTDIR}/src/foo/foo.c)
target_include_directories(app PRIVATE ${ROOTDIR}/src/foo)

# add test file
target_sources(app PRIVATE src/foo_test.c)

target_include_directories(app PRIVATE .)
target_include_directories(app PRIVATE src)
