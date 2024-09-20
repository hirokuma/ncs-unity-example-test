#
# Copyright (c) 2019 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(example)

# add module foo
target_sources(app PRIVATE src/foo/foo.c)
target_include_directories(app PRIVATE src)

# add module uut
target_sources(app PRIVATE src/uut/uut.c)
target_include_directories(app PRIVATE ./src/uut)

# add main
target_sources(app PRIVATE src/main.c)
