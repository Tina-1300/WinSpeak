@echo off
IF EXIST build (
    echo Suppression du dossier build...
    rmdir /s /q build
    exit
)


echo Creation du dossier build...
mkdir build

cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
cmake --install .
