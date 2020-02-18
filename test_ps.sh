# !/bin/bash

make

echo "Start Test"

echo "Simple Version: 2 1 0"
echo "Need to be lesser or equal to 3"
ARG="2 1 0"
echo "ARGUMENTS:" $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG
echo ""

echo "Simple Version: 1 5 2 4 3"
echo "Need to be lesser or equal to 8"
ARG="1 5 2 4 3"
echo "ARGUMENTS:" $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
echo ""

echo "Simple Version: Random 5(10 times)"
echo "Need to be lesser than 12"
i=1
while [ $i -le 10 ]
do
	ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
	echo "ARGUMENTS:" $ARG
	./push_swap $ARG | ./checker $ARG
	./push_swap $ARG | wc -l
	((i++))
done
echo ""

echo "Middle Version: Random 100(5 times)"
echo "Need to be lesser than 700"
i=1
while [ $i -le 5 ]
do
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	./push_swap $ARG | ./checker $ARG
	./push_swap $ARG | wc -l
	((i++))
done
echo ""

echo "Advance Version: Random 500(3 times)"
echo "Need to be lesser than 5500"
i=1
while [ $i -le 3 ]
do
	ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	./push_swap $ARG | ./checker $ARG
	./push_swap $ARG | wc -l
	((i++))
done