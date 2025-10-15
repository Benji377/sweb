#!/bin/sh

# Get the directory where this script is located (the SWEB source)
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

mkdir -p /tmp/sweb; cd /tmp/sweb; cmake "$SCRIPT_DIR" -DCMAKE_POLICY_VERSION_MINIMUM=3.5; make -j; make qemu;

# Added `timeout 0` to utils/images/menu.lst -> Skips screen resolution selection
