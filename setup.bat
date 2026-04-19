@echo off
echo ===================================================
echo  SakuraProject - Visual Studio 2022 Solution Setup
echo ===================================================

cmake -B build -S . -G "Visual Studio 17 2022" -A x64

echo.
echo ===================================================
echo  Setup Complete! 
echo ===================================================
pause