```bash
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_4$ cat q1.sh
#!/bin/bash
if [ -z "$1" ]; then
    echo "Pr0v1d3 with 1 4rg i.e the file to be duplicated!"
    exit 1
fi
ftd="$1"
if [ ! -f "$ftd" ]; then
    echo "Error: '$ftd' not found!"
    exit 1
fi
df="${ftd%.*}_copy.${ftd##*.}"
cp "$ftd" "$df"
if [ $? -eq 0 ]; then
    echo "File duplication was a massive success: '$df'"
else
    echo "Error!"
    exit 1
fi

student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_4$ cat q2.sh
#!/bin/bash
if [ $# -eq 0 ]; then
    echo "Pr0v1d3 with 1 or multiple 4rgs"
    exit 1
fi
for f in "$@"; do
    # Check if the file exists
    if [ -f "$f" ]; then
        echo -n "Wanna delete '$f'? (y/n): "
        read ans
        if [[ "$ans" == "y" || "$ans" == "Y" ]]; then
            rm "$f"
            if [ $? -eq 0 ]; then
                echo "'$f' deleted successfully."
            else
                echo "Couldn't delete '$f'."
            fi
        else
            echo "Skipped '$f'."
        fi
    else
        echo "File '$f' does not exist."
    fi
done
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_4$ cat q3.sh
#!/bin/bash
if [ $# -eq 0 ]; then
    echo "Pr0v1d3 with 1 or multiple 4rgs"
    exit 1
fi
sort_karo() {
    local arr=("$@")
    local n=${#arr[@]}

    for ((i = 0; i < n-1; i++)); do
        for ((j = 0; j < n-i-1; j++)); do
            if [[ "${arr[j]}" > "${arr[$((j+1))]}" ]]; then
                temp="${arr[j]}"
                arr[j]="${arr[$((j+1))]}"
                arr[$((j+1))]="$temp"
            fi
        done
    done
    echo "${arr[@]}"
}
fin=($(sort_karo "$@"))
echo "Sorted strings for thou milord:"
for str in "${fin[@]}"; do
    echo "\"$str\""
done
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_4$ cat q4.sh
#!/bin/bash
if [ $# -lt 2 ]; then
    echo "./q4.sh op4rg fil34rg"
    exit 1
fi
op="$1"
f="$2"
[ ! -f "$f" ] && echo "Error: File '$f' not found!" && exit 1
case "$op" in
    -linecount) wc -l < "$f" ;;
    -wordcount) wc -w < "$f" ;;
    -charcount) wc -m < "$f" ;;
    *) echo "Impossible, follow the format sire!" && exit 1 ;;
esac
student@MIT-ICT-LAB8-7:~/Suniket_230953372/LAB_4$ cat q5.sh
#!/bin/bash
if [ $# -lt 2 ]; then
    echo "Pr0v1d3 with 1 or multiple 4rgs"
    exit 1
fi
patterns=("${@:1:$#-1}") 
input_file="${@: -1}"      
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' not found!"
    exit 1
fi
search_patterns() {
    for pattern in "${patterns[@]}"; do
        echo "Lines containing pattern: '$pattern'"
        grep -n "$pattern" "$input_file" || echo "No match for '$pattern'."
    done
}
delete_patterns() {
    for pattern in "${patterns[@]}"; do
        sed -i "/$pattern/d" "$input_file"
    done
    echo "Patterns deleted."
}
while true; do
    echo -e "Menu:\n1. Search patterns\n2. Delete patterns\n3. Exit"
    read -p "Choose an option (1/2/3): " option
    case $option in
        1) search_patterns ;;
        2) delete_patterns ;;
        3) echo "Exiting."; exit 0 ;;
        *) echo "Invalid option." ;;
    esac
done
```
