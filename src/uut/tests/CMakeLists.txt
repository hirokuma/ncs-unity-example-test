find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# generate runner for the test
test_runner_generate(test_main.c)

# create mock for foo module. Add header to relative path 'foo'. That is to
# allow including header using <foo/foo.h>
cmock_handle(src/foo/foo.h foo)

# add test file
target_sources(app PRIVATE example_test.c)
target_include_directories(app PRIVATE .)
target_include_directories(app PRIVATE ..)
target_include_directories(app PRIVATE src/foo)

# Preinclude file to the module under test to redefine IS_ENABLED() macro
# which is used in the module.
set_property(SOURCE src/uut/uut.c PROPERTY COMPILE_FLAGS
	"-include example_test.h")
