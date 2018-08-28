@echo off
for /l %%x in (1, 1, 2000) do (
   Parallel.exe
   cls
   echo %%x/2000 complete
)
pause