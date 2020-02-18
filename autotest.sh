make
 echo "" > test_result
ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..6).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..7).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..8).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..9).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..10).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..11).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..12).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..13).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..14).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..15).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..16).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..17).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..18).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..19).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..20).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..21).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..22).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..23).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..24).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..25).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..26).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..27).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..28).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..29).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..30).to_a.shuffle.join(' ')"`
echo "ARGUMENTS:" $ARG >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..50).to_a.shuffle.join(' ')"`
echo "ARGUMENTS: 50" >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
echo "ARGUMENTS: 100" >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..200).to_a.shuffle.join(' ')"`
echo "ARGUMENTS: 200" >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
echo "ARGUMENTS: 500" >> test_result
./push_swap $ARG | ./checker $ARG >> test_result

ARG=`ruby -e "puts (0..1000).to_a.shuffle.join(' ')"`
echo "ARGUMENTS: 1000" >> test_result
./push_swap $ARG | ./checker $ARG >> test_result
