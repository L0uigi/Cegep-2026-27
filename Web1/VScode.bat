@echo off

:: Define variables
set "srcDir=V:\FTHERIAULT\00 - Logiciels de cours\VSCode\version 3"
set "destDir=C:\travail\VSCode\data\user-data\User"

if not exist "%destDir%\snippets" mkdir "%destDir%\snippets"

:: Copy snippet files
copy "%srcDir%\snippets\html.json" "%destDir%\snippets\" /Y
copy "%srcDir%\snippets\php.json" "%destDir%\snippets\" /Y
copy "%srcDir%\snippets\javascript.json" "%destDir%\snippets\" /Y
copy "%srcDir%\snippets\javascriptreact.json" "%destDir%\snippets\" /Y

:: Copy settings file
copy "%srcDir%\settings\settings.json" "%destDir%\" /Y

:: Launch VS Code and exit the terminal immediately
start "" C:\travail\VSCode\Code.exe
exit