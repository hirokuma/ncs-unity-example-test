#!/bin/sh

west build -b native_posix_64 -t run -d ./build-tests $@ -- -DCACHED_CONF_FILE=./prj_test.conf
