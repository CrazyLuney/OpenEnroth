@echo off

SET GRAMMAR_FILE=monster-info-parser.grm
SET PROGRAM_TEMPLATE_FILE=monster-info-parser-template.pgt
SET PROGRAM_FILE=MonsterInfoParserGrammar.hpp
SET PROGRAM_FILE_DESTINATION=..\src\Engine\TextParsers\MonsterInfoParser

SET GOLD_BUILDER_TOOLS=c:\software\GOLD-Builder-5.2.0-Cmd\
SET GOLD_BUILD=%GOLD_BUILDER_TOOLS%GOLDbuild.exe
SET GOLD_PROGRAM=%GOLD_BUILDER_TOOLS%GOLDprog.exe

IF EXIST gold-temp (
    DEL /Q /F gold-temp\
) ELSE (
    MKDIR gold-temp
)

"%GOLD_BUILD%" +details "%GRAMMAR_FILE%" gold-temp\monster-info-parser.egt gold-temp\monster-info-parser.log
IF %ERRORLEVEL% NEQ 0 GOTO FAILED
"%GOLD_PROGRAM%" gold-temp\monster-info-parser.egt "%PROGRAM_TEMPLATE_FILE%" "gold-temp\%PROGRAM_FILE%"
IF %ERRORLEVEL% NEQ 0 GOTO FAILED
COPY /B /Y /V "gold-temp\%PROGRAM_FILE%" "%PROGRAM_FILE_DESTINATION%\"

:FAILED
