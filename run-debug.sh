#!/bin/bash

set -e
# Find the directory where this script is located
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Always build inside a 'build' folder
mkdir -p "$PROJECT_ROOT/build"
cd "$PROJECT_ROOT/build"

# Configure and build
cmake ..
make


XPWD=$PWD
cd $PROJECT_ROOT/shell
flutter build linux --debug
cd $XPWD
echo "WAYLAND_DISPLAY=wayland-99"
WAYLAND_DISPLAY=wayland-99 ./aeris --component $PROJECT_ROOT/shell/build/linux/x64/release/bundle/shell $@
