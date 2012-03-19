#!/bin/bash

make clean

make -f Makefile_UnitTest

./unit_test
