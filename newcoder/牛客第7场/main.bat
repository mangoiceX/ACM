@echo off 
:loop
rand_string > input.txt
String2 < input.txt > wa_output.txt
stringrt < input.txt > rt_output.txt
fc  wa_output.txt rt_output.txt
if not errorlevel 1 goto loop
pause