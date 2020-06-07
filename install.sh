#!/bin/bash
echo "mkdir"
mkdir -p "$DESTDIR/usr/bin"
echo "mkdir done"
echo "cp"
cp build/dtag "$DESTDIR/usr/bin/dtag"
echo "cp done"
