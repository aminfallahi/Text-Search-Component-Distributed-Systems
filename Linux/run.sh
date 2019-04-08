#!/bin/bash
set -f
if [ $# -lt 3 ]; then
    echo "    You should pass me 3 arguments using the following format:"
    echo ""
    echo "        ./run.sh path pattern regex"
    echo ""
    echo ""
    echo "    For now, I will run with the following configuration. It will search all .txt and .cpp files in testfiles directory for all correctly formatted email addresses:"
    echo ""
    echo "        ./run.sh ../testfiles \"*.txt\" \"^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$\"" 
    echo ""
	dir="../testfiles"
	pattern="*.txt,*.cpp"
	regex="^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$"
else
	dir=$1
	pattern=$2
	regex=$3
fi

echo "    Now, I am compiling! You can see the compile log in file compile.log"
echo ""
make clean &> /dev/null
make &> compile.log

echo "    to Continue press enter..."
read enter

cd dist
./Client $dir $pattern $regex
set +f
cd ..
