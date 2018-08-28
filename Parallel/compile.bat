del /f Parallel.exe
gcc -fopenmp Parallel.c
ren "a.exe" "Parallel.exe"
pause