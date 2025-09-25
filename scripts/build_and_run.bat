@echo off
setlocal EnableDelayedExpansion
set "SCRIPT_DIR=%~dp0"
pushd "%SCRIPT_DIR%.."

set "PREFERRED_CXX="
for %%C in (g++ clang++) do (
    for /f "usebackq tokens=*" %%P in (`where %%C 2^>nul`) do (
        set "PREFERRED_CXX=%%P"
        goto :compiler_found
    )
)

set "MSYS2_GPP=C:\msys64\mingw64\bin\g++.exe"
if exist "%MSYS2_GPP%" (
    set "PREFERRED_CXX=%MSYS2_GPP%"
    goto :compiler_found
)

set "LLVM_CLANG=C:\Program Files\LLVM\bin\clang++.exe"
if exist "%LLVM_CLANG%" (
    set "PREFERRED_CXX=%LLVM_CLANG%"
    goto :compiler_found
)

set "CODEBLOCKS_GPP=C:\Program Files\CodeBlocks\MinGW\bin\g++.exe"
if exist "%CODEBLOCKS_GPP%" (
    set "PREFERRED_CXX=%CODEBLOCKS_GPP%"
    goto :compiler_found
)

echo [ERROR] No se encontro ni g++ ni clang++. Ajusta tu PATH o actualiza el script con la ruta directa.
set "RUN_EXIT=1"
goto :epilogue

:compiler_found
echo [INFO] Compilador detectado: %PREFERRED_CXX%

set "RESTORE_PATH=%PATH%"
if /I "%PREFERRED_CXX%"=="%MSYS2_GPP%" (
    for /f "usebackq delims=" %%I in (`"%PREFERRED_CXX%" -print-file-name=cc1plus 2^>nul`) do (
        set "_CC1_DIR=%%~dpI"
    )
    if defined _CC1_DIR (
        set "PATH=!_CC1_DIR!;C:\msys64\mingw64\bin;!PATH!"
    ) else (
        set "PATH=C:\msys64\mingw64\bin;!PATH!"
    )
)

set "OUTPUT_DIR=bin"
set "OUTPUT=%OUTPUT_DIR%\sailor_duck_renderer.exe"
if not exist "%OUTPUT_DIR%" mkdir "%OUTPUT_DIR%"

set "EXTRA_FLAGS="
if /I "!PREFERRED_CXX:~-11!"=="clang++.exe" (
    set "EXTRA_FLAGS=-fuse-ld=lld"
)

"%PREFERRED_CXX%" -std=c++17 -Wall -Wextra -pedantic -Isrc -Iinclude -Ivendor/miniwin src/ColorPalette.cpp src/Sprite.cpp src/SpriteRenderer.cpp src/SailorDuckSprite.cpp src/main.cpp vendor/miniwin/miniwin.cpp -luser32 -lgdi32 %EXTRA_FLAGS% -o "%OUTPUT%"
set "RUN_EXIT=%errorlevel%"
if not "%RUN_EXIT%"=="0" goto :build_failed

echo [INFO] Ejecucion de %OUTPUT%
"%OUTPUT%"
set "RUN_EXIT=%errorlevel%"
goto :epilogue

:build_failed
echo [ERROR] Fallo la compilacion.

:epilogue
set "PATH=%RESTORE_PATH%"
popd
exit /b %RUN_EXIT%
