@echo off
cd build
cmake .. 
cmake --build .

shooter.exe
cd ..