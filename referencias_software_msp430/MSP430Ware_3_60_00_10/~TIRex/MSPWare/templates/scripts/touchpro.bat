for /f %%i in ('where javaw.exe') do set VAR=%%i
cd %1
%VAR% -jar touchPro.jar