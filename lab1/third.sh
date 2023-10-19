echo enter n
read n

num=0
sum=0

while [ $n -gt 0 ]
do
	num=$((num*10))
	
	k=$((n%10))
	
	num=$((num + k))
	
	n=$((n/10))
	
	sum=$((sum+k))
done


echo "Number : $num"

echo "SUM : $sum"
