Programmiersprachen: Aufgabenblatt 3
====================================

[![Build Linux](../../actions/workflows/build-linux.yml/badge.svg)](../../actions/workflows/build-linux.yml)
[![Build macOS](../../actions/workflows/build-macos.yml/badge.svg)](../../actions/workflows/build-macos.yml)
[![Build Windows](../../actions/workflows/build-windows.yml/badge.svg)](../../actions/workflows/build-windows.yml)
[![Doctest](../../actions/workflows/doctest.yml/badge.svg)](../../actions/workflows/doctest.yml)

Repository template for **Assignment 3** of the Programming Languages course (*Programmiersprachen*).
This assignment covers function templates, class templates, and sequential STL containers.

## Build

```bash
cmake -B build
cmake --build build

# run the starter application
# Windows with Visual Studio generator:
.\build\source\Debug\main.exe

# Linux/macOS or single-config generators:
# ./build/source/main

# run the unit tests
# Windows with Visual Studio generator:
ctest --test-dir build -C Debug

# Linux/macOS or single-config generators:
# ctest --test-dir build
```

Add your exercise programs and headers in the `source` directory. Register new
programs in `source/CMakeLists.txt` as described in the task sheet.
