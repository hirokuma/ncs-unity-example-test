#!/bin/sh -eu

cd tests
cd uut; west build -b native_sim_64 -t run  $@; cd ..
cd foo; west build -b native_sim_64 -t run  $@; cd ..
cd ..
