#!/bin/bash
#assignment 1
filedir=$1
searchstr=$2

if [ $# != 2 ]
   then 
        echo "Expected 2 args but $#  args passed"
        exit 1
elif [ $# -eq 2 ]
 then
   if [ -d $filedir ];
     then
   	echo "$filedir is a path"       
        echo "The number of files are `ls $filedir | wc -l` and the number of matching lines are `cat * | grep -Rnwch --no-ignore-case $filedir -e $searchstr | paste -sd+ | bc`"
   else
        echo "$filedir is not a path"
        exit 1
    fi
fi
