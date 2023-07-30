#!/usr/bin/bash

scons platform=windows arch=x86_64 target=editor  vsproj=yes dev_mode=yes dev_build=yes custom_modules=../DungeonARPGGame/engine_custom_modules 2>&1 | tee build.sh.log
scons platform=windows arch=x86_64 target=template_debug custom_modules=../DungeonARPGGame/engine_custom_modules 2>&1 | tee build_template_debug.sh.log
scons platform=windows arch=x86_64 target=template_release custom_modules=../DungeonARPGGame/engine_custom_modules 2>&1 | tee build_template_release.sh.log