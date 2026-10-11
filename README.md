# Redro Burger Engine

A custom lightweight 2D engine prototype and burger-restaurant game for Android.

## Rules
- No Godot, Unity, or ready-made game engine.
- Engine and gameplay systems are developed in this repository.
- SDL3 is used as a low-level platform, rendering, and input library.
- C++20 and CMake are used for the native project.
- Android packaging is planned; an APK has not yet been produced.

## Current prototype
- SDL3 window and renderer
- Basic 2D restaurant scene drawn with primitive shapes
- Mouse and touch event handling
- Ingredient selection and a basic burger order state
- Simple coin reward logic
- GitHub Actions Linux build workflow

## Build locally
Install CMake, a C++20 compiler, Git, and Ninja, then run:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 2
```

CMake fetches SDL3 as a dependency. SDL3 is a library, not a game engine.

## Roadmap
1. Validate the native build and improve the prototype UI.
2. Implement engine modules: timing, input abstraction, scene lifecycle, resources, sprites, animation, and collision.
3. Expand gameplay: customers, recipe matching, timers, upgrades, progression, and local saves.
4. Add an Android NativeActivity entry point and Android NDK build.
5. Produce and test an APK on a physical device.

## Status
Early prototype. The current scene uses placeholder geometric artwork. Android packaging and physical-device testing are not complete.
