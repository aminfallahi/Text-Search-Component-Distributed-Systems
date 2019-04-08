#.\Debug\CppClient.exe 1 2 3
If (-NOT  ($($args.Count) -eq 3)) {
    Write-Host "    You should pass me 3 arguments using the following format:"
    Write-Host ""
    Write-Host "        ./run.ps1 path pattern regex"
    Write-Host ""
    Write-Host ""
    Write-Host "    For now, I will run with the following configuration. It will search all .txt and .cpp files in testfiles directory for all correctly formatted email addresses:"
    Write-Host ""
    Write-Host "        ./run.ps1 ./testfiles *.txt ""^([a-zA-Z0-9]+)@([a-zA-Z0-9]+)\.([a-zA-Z]{2,5})$""" 
    Write-Host ""
    .\Debug\CppClient.exe ./testfiles *.txt,*.cpp "^([a-zA-Z0-9]+)@([a-zA-Z0-9]+)\.([a-zA-Z]{2,5})$"
} Else{
    .\Debug\CppClient.exe $args[0] $args[1] $args[2]
}