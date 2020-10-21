@echo off
cl src\main.cpp /EHsc /link /out:render.exe
del main.obj
