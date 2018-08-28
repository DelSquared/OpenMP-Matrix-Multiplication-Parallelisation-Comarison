::This batch script was written to quickly recompile the C code and replace the new one without much hassle
del /f Parallel.exe
gcc -fopenmp Parallel.c
ren "a.exe" "Parallel.exe"
pause
