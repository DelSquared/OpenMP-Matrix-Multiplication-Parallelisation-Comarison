::This batch script was written to quickly recompile the C code and replace the new one without much hassle
del /f nonParallel.exe
gcc -fopenmp nonParallel.c
ren "a.exe" "nonParallel.exe"
pause
