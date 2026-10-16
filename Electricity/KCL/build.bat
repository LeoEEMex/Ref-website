@echo off
call "C:\Users\Home\emsdk\emsdk_env.bat"

emcc KCL.c -o KCL.js -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=callMain
echo.
echo Compilation complete!
pause