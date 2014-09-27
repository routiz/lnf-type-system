#!/bin/bash

mkdir -p m4
autoreconf --install
./configure
make
