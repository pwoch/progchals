n=5000
rm tmp;
echo "$n 2" >>tmp
for i in `seq $n`
do
    echo "-1" >>tmp;
    echo "1" >>tmp;
done

