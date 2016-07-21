REM .\build\forms_mean_daemon.exe --manual-index-process-url "ftp://ftp.sec.gov/edgar/daily-index/master.20160101.idx" --no-daemon 2>&1 | tee d.out
REM .\build\mongoc.exe find -uri "mongodb://127.0.0.1/" -db "forms_mean" -collection "forms" -query "{ \"accession_number\" : \"0001242648-14-000082\" }" 2>&1 | tee d.out
REM .\build\mongoc.exe find -uri "mongodb://127.0.0.1/" -db "forms_mean" -collection "forms" -query "{ }" 2>&1 | tee d.out
REM .\build\mongoc.exe insert -uri "mongodb://127.0.0.1/" -db "forms_mean" -collection "forms" -query "{ \"accession_number\" : \"0001242648-14-000085\" }" 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-index-process-url "file:///../edgar/daily-index/master.20141031.sample.idx" --no-daemon 2>&1 | tee d.out
REM .\build\mongoc.exe find -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -query "{ \"accession_number\" : \"0001242648-14-000081\" }" 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-form-process-url "file:///../edgar/data/1000180/0001242648-14-000081.txt" 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-form-process-url "ftp://ftp.sec.gov/edgar/data/1000180/0001242648-14-000081.txt" 2>&1 | tee d.out
REM .\build\ftpget.exe http://cnn.com 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-form-process-url "file:///../edgar/ftp.sec.gov--edgar--data--1066107--POSASR--has-a-gazillion-filers--0001047469-15-001027.txt" 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-form-process-url "file:///../edgar/ftp.sec.gov--edgar--data--1000180--SANDISK--issuer--reporting-owner--0001242648-14-000081.txt" 2>&1 | tee d.out
REM .\build\forms_mean_daemon.exe --manual-form-process-url "file:///../edgar/ftp.sec.gov--edgar--data--99359--breeze-eastern-corp--subject-company--filed-by--0001193125-15-399601.txt" 2>&1 | tee d.out
REM c:\cygwin\bin\echo "{ \"find\": \"forms\", \"filter\": { \"accession_number\": \"001242648-14-000082\" } }" 2>&1 | tee d.out
REM c:\cygwin\bin\echo "{ \"find\": \"forms\", \"filter\": { \"accession_number\": \"0001193125-14-390153\"} }" | .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command - 2>&1 | tee d.out
REM .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command "{ \"find\": \"forms\", \"filter\": { \"accession_number\": \"0001193125-14-390153\"} }" 2>&1 | tee d.out
REM > db.forms.runCommand({ find: "forms", filter: {}, limit: 3 });
REM .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command "{ \"find\": \"forms\", \"limit\": 3 }" 2>&1 | tee d.out
REM .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command "{ \"insert\": \"forms\", \"documents\": [ { \"name\": \"Larry\", \"accession_number\": 2, \"faux\": true } ] }" 2>&1 | tee d.out
REM .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command "{ \"find\": \"forms\", \"filter\": { \"name\": \"Moe\" } }" 2>&1 | tee d.out
REM .\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command - < view-1.js  2>&1 | tee d.out
.\build\mongoc.exe command -uri "mongodb://prnvf-jayne/" -db "forms_mean" -collection "forms" -command - < view-2.js  2>&1 | tee d.out

