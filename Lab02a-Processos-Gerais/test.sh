#!/bin/bash

make
./main_stdout 10000 > stdout_test.txt
./main_stderr 10000 2> stderr_test.txt
