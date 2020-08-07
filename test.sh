#! /bin/bash
PRODUCTS_PATH=/Users/admin/Library/Developer/Xcode/DerivedData/CppAGOS-chpicopqxleupjfsxjmfhenpgqii/Build/Products/Debug
exec=$PRODUCTS_PATH/$1
cases=$2

if [[ $# != 2 ]];
then
	echo "Command need 2 argument = swift file and testCase directory"
	exit 1
fi

if [[ ! -x "$exec" ]]; then
	echo "Execution File not exists = $exec"
	exit 1
fi
if [[ ! -d "$cases" ]]; then
	echo "TestCase Directory not exists = $exec"
	exit 1
fi

fail=()

files=`ls "$cases"/*.in`
successCount=0
failCount=0
for t in $files ; do
  startTime=$(python -c 'from time import time; print int(round(time() * 1000))')
	$exec < "$t" > /dev/null
  result=$?
  endTime=$(python -c 'from time import time; print int(round(time() * 1000))')
	resultFile="${t/.in/.out}"
	if [ -r "${resultFile}" ]; then
		expected=`cat $resultFile`
    time=$(( $endTime - $startTime ))
    file=$( basename $t )
		if [[ $result == $expected ]]; then
      echo -en "\033[0;32m.\033[0;39m"
			((successCount++))
		else
      # echo $( basename $t );
      echo -en "\033[0;31mx\033[0;39m"
      line="$file:expected:$expected,got:$result"
      fail[$failCount]=$line
      ((failCount++))
		fi
	fi
done

total=$(( countSuccess + countFail ))

if [ $total > 0 ]; then
  echo ""
  echo ""
	echo "Finsihed"
	echo "Success=${successCount} Fail=${failCount}"

  echo ""
  echo ""

  for e in ${fail[@]}; do
    echo ${e}
    echo ""
  done
fi
