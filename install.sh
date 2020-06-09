#!/bin/bash
mkdir -p "$DESTDIR/usr/bin"
cp build/dtag "$DESTDIR/usr/bin/dtag"
cp script/drecent "$DESTDIR/usr/bin/drecent"
