#!/usr/bin/bash

scons platform=windows arch=x86_64 vsproj=yes target=editor dev_mode=yes dev_build=yes custom_modules=../godot_custom_modules 2>&1 | tee build.sh.log
