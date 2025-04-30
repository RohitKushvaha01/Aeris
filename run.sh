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

# Run the program
WAYLAND_DISPLAY=wayland-99 ./aeris $@

