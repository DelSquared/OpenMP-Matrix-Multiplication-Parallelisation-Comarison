::This batch script was written to quickly recompile the C code and replace the new one without much hassle
del /f AlgorithmTest.exe
gcc -fopenmp AlgorithmTest.c
ren "a.exe" "AlgorithmTest.exe"
pause
