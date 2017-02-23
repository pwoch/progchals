max=20
A=3
B=0
rm partyin.txt
echo "`expr $max + 1` $max $A $B">>partyin.txt
for i in `seq $max`
do
    echo "$i `expr $i + 1`">>partyin.txt
done

