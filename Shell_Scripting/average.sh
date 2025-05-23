echo "enter  three numbers "
read a b c
sum=$((a+b+c))
avg=$(echo "scale=2; $sum/3" | bc)
echo "Avg of $a $b $c is $avg"
