read string1
read string2

echo $string1
echo $string2

if [ -z "$string1" ];
then
    echo "String 1 : empty."
else
    echo "String 1 : not empty."
fi

if [ -z "$string2" ];
then
    echo "String 2 : empty."
else
    echo "String 2 : not empty."
fi

if [ $string1 == $string2 ]
then
    echo "Equal"
else
    echo "Un-Equal"
fi
