gcc.exe -c "./src/*.c" "./src/lib/*.c";
gcc.exe -Wall -Wextra -o "./output.exe" "*.o";
remove-item "*.o";
& .\output.exe;

Write-Host "`n++ not part of the program ++";
Write-Host "last exit code = $($LASTEXITCODE)";
