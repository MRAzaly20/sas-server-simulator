@echo off
REM ============================================================
REM  launch_all.bat — Start all 18 IED processes
REM  GI 150kV — Distributed IED Simulation Suite
REM  Run from build_ied/ directory (where .exe files are built)
REM  Requires: Administrator privileges (for Npcap/GOOSE)
REM ============================================================

echo.
echo =====================================================
echo  GI 150kV — Launching 18 IED Servers
echo =====================================================
echo.

REM --- Configuration base path ---
set CFG=..\config

REM --- Transformer Bay E01 ---
start "E01_BCU"  E01_BCU.exe  %CFG%\E01_TRF1\config\E01_BCU.json
start "E01_P643" E01_P643.exe %CFG%\E01_TRF1\config\E01_P643.json
start "E01_P142" E01_P142.exe %CFG%\E01_TRF1\config\E01_P142.json

REM --- Transformer Bay E02 ---
start "E02_BCU"  E02_BCU.exe  %CFG%\E02_TRF2\config\E02_BCU.json
start "E02_P643" E02_P643.exe %CFG%\E02_TRF2\config\E02_P643.json
start "E02_P142" E02_P142.exe %CFG%\E02_TRF2\config\E02_P142.json

REM --- Transformer Bay E03 ---
start "E03_BCU"  E03_BCU.exe  %CFG%\E03_TRF3\config\E03_BCU.json
start "E03_P643" E03_P643.exe %CFG%\E03_TRF3\config\E03_P643.json
start "E03_P142" E03_P142.exe %CFG%\E03_TRF3\config\E03_P142.json

REM --- Coupler Bay E04 ---
start "E04_BCU"  E04_BCU.exe  %CFG%\E04_COUPLER\config\E04_BCU.json
start "E04_P143" E04_P143.exe %CFG%\E04_COUPLER\config\E04_P143.json

REM --- Line-1 Bay E05 ---
start "E05_BCU"  E05_BCU.exe  %CFG%\E05_LINE1\config\E05_BCU.json
start "E05_P543" E05_P543.exe %CFG%\E05_LINE1\config\E05_P543.json
start "E05_P142" E05_P142.exe %CFG%\E05_LINE1\config\E05_P142.json

REM --- Line-2 Bay E06 ---
start "E06_BCU"  E06_BCU.exe  %CFG%\E06_LINE2\config\E06_BCU.json
start "E06_P543" E06_P543.exe %CFG%\E06_LINE2\config\E06_P543.json
start "E06_P142" E06_P142.exe %CFG%\E06_LINE2\config\E06_P142.json

REM --- Busbar Protection E00 ---
start "E00_P746" E00_P746.exe %CFG%\E00_BUSBAR\config\E00_P746.json

echo.
echo All 18 IED processes launched.
echo Each IED runs in its own console window.
echo Press Ctrl-C in any window to stop that IED.
echo.
pause
