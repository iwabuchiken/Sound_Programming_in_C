@echo off

set temp="%1"

echo param is %temp%

REM REF http://answers.microsoft.com/en-us/windows/forum/windows_vista-windows_programs/batch-parameter-is-it-all-arguments-to-the-command/9f7484f3-819c-4c05-a4e9-a439043b18fa
if %temp%=="ch" (

	echo starting =^> chrome
	goto start_chrome

) else if %temp%=="ff" (

	echo starting =^> firefox
	goto start_ff

) else (

	echo ^<Usage^> b ch/ff

)

goto end

REM pushd "C:\Program Files (x86)\Google\Chrome\Application"


REM start chrome.exe http://localhost/Cake_NR5/articles
REM start chrome.exe http://benfranklin.chips.jp/cake_apps/Cake_NR5/articles
REM start chrome.exe "https://mysqladmin.lolipop.jp/pma/index.php?db=LAA0278957-cakevm&table=positions&target=sql.php&server=110&token=cb582dcc1a162a60fddda6c688b049f0"
REM start chrome.exe chrome-extension://ohbfkkmpnlpgbbfdflaiikoohbidaikj/app.html

REM start chrome.exe http://localhost/Cake_NR5/articles
REM start chrome.exe http://benfranklin.chips.jp/cake_apps/Cake_NR5/articles
REM start chrome.exe "https://mysqladmin.lolipop.jp/pma/index.php?db=LAA0278957-cakevm&table=positions&target=sql.php&server=110&token=cb582dcc1a162a60fddda6c688b049f0"
REM start chrome.exe chrome-extension://ohbfkkmpnlpgbbfdflaiikoohbidaikj/app.html
REM popd

pushd C:\WORKS\Programs\Firefox_33.0

REM start firefox.exe http://localhost/Cake_NR5/articles
REM start firefox.exe http://benfranklin.chips.jp/cake_apps/Cake_NR5/articles
REM start firefox.exe "https://mysqladmin.lolipop.jp/pma/index.php?db=LAA0278957-cakevm&table=positions&target=sql.php&server=110&token=cb582dcc1a162a60fddda6c688b049f0"

popd

:start_chrome

start chrome.exe http://localhost/Eclipse_Luna/Cake_IG/keywords
start chrome.exe http://benfranklin.chips.jp/cake_apps/Cake_IG/keywords
start chrome.exe "https://mysqladmin.lolipop.jp/pma/index.php?db=LAA0278957-cakevm&table=positions&target=sql.php&server=110&token=cb582dcc1a162a60fddda6c688b049f0"
start chrome.exe chrome-extension://ohbfkkmpnlpgbbfdflaiikoohbidaikj/app.html
start chrome.exe https://docs.google.com/spreadsheets/d/1GlMjFYCAdSc87V-BhGAM-sz-Kka6AlyxgS-0jqvPlPc/edit#gid=0

goto end

:start_ff

start firefox.exe http://localhost/Eclipse_Luna/Cake_IG/keywords
start firefox.exe http://benfranklin.chips.jp/cake_apps/Cake_IG/keywords
start firefox.exe "https://mysqladmin.lolipop.jp/pma/index.php?db=LAA0278957-cakevm&table=positions&target=sql.php&server=110&token=cb582dcc1a162a60fddda6c688b049f0"
start chrome.exe https://docs.google.com/spreadsheets/d/1GlMjFYCAdSc87V-BhGAM-sz-Kka6AlyxgS-0jqvPlPc/edit#gid=0

goto end

:end
