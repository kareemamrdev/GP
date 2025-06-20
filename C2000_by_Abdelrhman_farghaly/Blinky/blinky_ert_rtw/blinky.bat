
cd .

if "%1"=="" ("G:\Matlab\Matlab\bin\win64\gmake"  DEPRULES=1 -j7  -f blinky.mk all) else ("G:\Matlab\Matlab\bin\win64\gmake"  DEPRULES=1 -j7  -f blinky.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1