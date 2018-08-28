::this script was used to run the executable in question for the desired number of times while keeping the C code uncluttered
@echo off
for /l %%x in (1, 1, 2000) do (
   Parallel.exe
   cls
   echo %%x/2000 complete
)
pause
