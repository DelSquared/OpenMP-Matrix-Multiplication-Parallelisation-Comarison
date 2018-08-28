del /f nonParallel.exe
gcc -fopenmp nonParallel.c
ren "a.exe" "nonParallel.exe"
pause