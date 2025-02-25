# Setup in CLion on Windows

## Create IntelliSense

- Make sure to **build** the `godot-cpp` target

> [!IMPORTANT]
> Clicking on the button created by CLion in the markdown preview will try to run the project which fails without a
> selected executable to launch. Click the build button (hammer icon) instead!

## Change CMake Profile

- Change Toolchain to `Visual Studio` to avoid conflict in binary dependencies
    - to debug dependencies use `VC > Tools > MSVC > bin > dumpbin` with `dumpbin /dependents file.dll`
- Add `-DCMAKE_INSTALL_PREFIX="$CMakeProjectDir$/geoimportertest"` to CMake options
    - replace `geoimportertest` with the folder of the godot project used for testing

## Run Configurations

- Add godot executable as `Executable`
    - Leave `Program Arguments` empty to launch game running the specified default scene (see `Run Test Project`)
    - Add `-e` to `Program Arguments` to launch the project in the editor (see `Open Test Project`)
- Add `Install` task after `Build` task to `Befor launch` task list