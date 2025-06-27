#!/bin/bash

set -e  # Stop script on any error

echo "🛠️  Running Poryscript..."
tools/poryscript/poryscript.exe

echo "📦 Building ROM with make..."
make -j"$(nproc)" 2>&1 | tee build.log