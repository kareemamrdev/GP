
cd .

if "%1"=="" ("G:\Matlab\Matlab\bin\win64\gmake"  DEPRULES=1 -j7  -f open_loop_inverter_model_badry_sus.mk all) else ("G:\Matlab\Matlab\bin\win64\gmake"  DEPRULES=1 -j7  -f open_loop_inverter_model_badry_sus.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1