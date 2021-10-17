echo "Enter 2 Numbers : "
read num
read num2
echo "Press 1 for addition"
echo "Press 2 for Substraction"
echo "Press 3 for Division"
echo "Press 4 for Multiplication"
echo "Press 5 for Remainder"
read sign
if  [[ $sign == [1-5] ]]
then
    case $sign in
        1) echo "Result of addition is : $(($num + $num2))";;
        2) echo "Result of Substraction is : $(($num - $num2))";;
        3) echo "Result of Division is : $(($num / $num2))";;
        4) echo "Result of Multiplication is : $(($num * $num2))";;
        5) echo "Reminder of division is : $(($num % $num2))";;
    esac
else
    echo "Do what is Mentioned , Bye"
fi
