@echo off
setlocal

:start_loop

IF EXIST build (
    echo Suppression du dossier build...
    rmdir /s /q build
    PAUSE
)

echo Creation du dossier build...
mkdir build

pushd build
IF %ERRORLEVEL% NEQ 0 (
    echo Erreur: Impossible d'entrer dans le dossier build.
    goto :end_script
)

echo Configuration CMake...
cmake .. -DCMAKE_BUILD_TYPE=Release
IF %ERRORLEVEL% NEQ 0 (
    echo Erreur de configuration CMake.
    popd
    goto :end_script
)

echo Compilation CMake...
cmake --build .
IF %ERRORLEVEL% NEQ 0 (
    echo Erreur de compilation CMake.
    popd
    goto :end_script
)

echo Installation CMake...
cmake --install .
IF %ERRORLEVEL% NEQ 0 (
    echo Erreur d'installation CMake.
    popd
    goto :end_script
)

popd

PAUSE
goto :start_loop

:end_script
PAUSE
endlocal