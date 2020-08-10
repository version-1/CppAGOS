#! /bin/bash
PRODUCTS_PATH=/Users/admin/Library/Developer/Xcode/DerivedData/CppAGOS-chpicopqxleupjfsxjmfhenpgqii/Build/Products/Debug
SUCCESS_FILE=success.tmp
FAIL_FILE=fail.tmp
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

:>$SUCCESS_FILE
:>$FAIL_FILE

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
      echo "$file: answer: ${result} time: ${time} ms" >> $SUCCESS_FILE

      success[$successCount]=$line
			((successCount++))
		else
      # echo $( basename $t );
      echo -en "\033[0;31mx\033[0;39m"
      echo "$file: expected:$expected got:$result" >> $FAIL_FILE
      ((failCount++))
		fi
	fi
done

total=$(( countSuccess + countFail ))

if [ $total > 0 ]; then
  echo ""
  echo ""
	echo "[[[Done]]]"
	echo "success=${successCount} fail=${failCount}"

  echo ""
  echo ""
  echo "[[[successes]]]"
  cat $SUCCESS_FILE

  echo ""
  echo ""
  echo "[[[fails]]]"
  cat $FAIL_FILE
fi
