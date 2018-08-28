::this script was used to run the executable in question for the desired number of times while keeping the C code uncluttered
@echo off
for /l %%x in (1, 1, 200) do (
   AlgorithmTest.exe
   echo %%x/200 complete
)
pause
