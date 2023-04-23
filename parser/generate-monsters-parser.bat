@echo off

SET GRAMMAR_FILE=monsters-parser.grm
SET PROGRAM_TEMPLATE_FILE=monsters-parser-min-template.pgt
SET PROGRAM_FILE=monsters_parser_grammar.hpp
SET PROGRAM_FILE_DESTINATION=C:\Users\Kirill\source\repos\mm7-monsters-parser\mm7-monsters-parser

SET GOLD_BUILDER_TOOLS=c:\software\GOLD-Builder-5.2.0-Cmd\
SET GOLD_BUILD=%GOLD_BUILDER_TOOLS%GOLDbuild.exe
SET GOLD_PROGRAM=%GOLD_BUILDER_TOOLS%GOLDprog.exe

IF EXIST gold-temp (
    DEL /Q /F gold-temp\
) ELSE (
    MKDIR gold-temp
)

"%GOLD_BUILD%" +details "%GRAMMAR_FILE%" gold-temp\monsters-parser.egt gold-temp\log.txt
IF %ERRORLEVEL% NEQ 0 GOTO FAILED
"%GOLD_PROGRAM%" gold-temp\monsters-parser.egt "%PROGRAM_TEMPLATE_FILE%" "gold-temp\%PROGRAM_FILE%"
IF %ERRORLEVEL% NEQ 0 GOTO FAILED
COPY /B /Y /V "gold-temp\%PROGRAM_FILE%" "%PROGRAM_FILE_DESTINATION%\"

:FAILED
