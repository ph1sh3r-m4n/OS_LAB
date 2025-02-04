```bash
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q1.sh
#!/bin/sh
if [ -d $1 ]
then
        echo "DIRECTORY"
elif [ -f $1 ]
then
        echo "FILE"   
else
        echo "NEITHER"
fi
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q2.sh
#!/bin/sh
ls *$1*
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q3.sh
#!/bin/sh
find . -type f -name '*.txt' | while read FILE ; do
    newfile="$(echo ${FILE} |sed -e 's/txt/text/g')" ;
    mv "${FILE}" "${newfile}" ;
done 
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q4.sh
echo "Enter Basics"
read bas
echo "Enter TA"
read ta
echo "$bas + $ta + $bas*0.1" | bc -l > gs
echo "Gross Salary=" | cat gs
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q5.sh
echo "Enter string to copy="
read a
cp *$a new
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q6.sh
#!/bin/bash
for file in *; do
  if [ -f "$file" ]; then
    echo "Processing file: $file"
    sed -i.bak 's/\(^\|[[:space:]]\|\.\)[[:space:]]*ex:/\1Example:/g' "$file"
    echo "Modified occurrences in $file"
  fi
done
echo "File modifications completed."

student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_3$ cat q7.sh
file=$1
counter=0
 
out="oddfile.$$"
 
if [ $# -eq 0 ] 
then
	echo "$(basename $0) file"
	exit 1 
fi
 
if [ ! -f $file ]
then
	echo "$file not a file!"
	exit 2
fi
 
while read line
do
 
	isEvenNo=$( expr $counter % 2 )
 
	if [ $isEvenNo -eq 0 ] 
	then
		
		echo $line >> $out
	fi
	
	(( counter ++ ))
done < $file

/bin/rm -f $file
 
 
/bin/mv $out $file

```
