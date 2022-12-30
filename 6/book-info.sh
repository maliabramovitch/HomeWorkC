#!/bin/bash

#Malka Abramovitch 314723586
#Rotem Levi  318845310

#cheack if the minimun argumants has passed
if [[ $# -eq 0 ]] ;  then
     exit 1
fi

#cheacks if files list exist in directory
if ! [[ -f $1 ]] ; then
  echo "File $1 not found"
  exit 1
fi

#cheacks if all the files in the list exist in directory
for file in $(cat $1) ; do
  if ! [[ -f $file ]] ; then
    echo "File $file not found"
    exit 1
  fi
done

echo "Enter: number / files / names / stats <chapter-name> / search <word>/ quit"

while read op arg  ; do
 
if [[ $op == number ]] ; then
  echo "$(wc -l < $1) chapters"
   
elif [[ $op == files ]] ; then
    	for line in $(cat $1) ; do
         echo "$(head -n1 < $line): $line"  >> sorted
     done
     sort sorted
     rm sorted
   
elif [[ $op == names ]] ; then
     	for line in $(cat $1) ; do
         echo "$(head -n1 < $line): $(sed -n '3p' < $line)" >> sorted
     done
     sort sorted
     rm sorted

elif [[ $op == stats ]] ; then
    if [[ -z "$arg" ]] ; then
      for chapter in $(cat $1) ; do
        echo "$(head -n1 < $chapter): $(tail -n +3 < $chapter | wc -l) lines, $(tail -n +3 < $chapter | wc -w) words" >> sorted
      done 
      sort sorted
      rm sorted
    else
      for chapter in $(cat $1) ; do
        if [[ $arg == $(head -n1 < $chapter) ]] ; then
          echo "$(head -n1 < $chapter): $(tail -n +3 < $chapter | wc -l) lines, $(tail -n +3 < $chapter | wc -w) words"
        fi
      done
    fi
             
elif [[ $op == search ]] ; then
    if [[ -z "$arg" ]] ; then
      exit 1
      fi
	 for chapter in $(cat $1) ; do
        echo "$(head -n1 < $chapter): $(grep -E -i -w $arg $chapter | wc -l)" | grep -v -w 0 >> sorted
   done
   sort sorted
   rm sorted


elif [[ $op == quit ]] ; then
  exit
	
else
  echo -e "illegal operation bitch\nsorry I got carried away...\nyou are not allowed to degrade me for cursing"

fi
     
  echo "Enter: number / files / names / stats <chapter-name> / search <word>/ quit"

done
exit