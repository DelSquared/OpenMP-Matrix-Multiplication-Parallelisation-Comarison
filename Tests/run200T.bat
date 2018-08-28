@echo off
for /l %%x in (1, 1, 200) do (
   AlgorithmTest.exe
   echo %%x/200 complete
)
pause