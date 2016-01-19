#!/usr/bin/env bash

{
	echo test_case,actual,expected
	echo 10?=10,$(./without_comparisons 10 10),true
	echo 10?=9,$(./without_comparisons 10 9),false
	echo -10?=-10,$(./without_comparisons -10 -10),true
	echo -10?=-9,$(./without_comparisons -10 -9),false
	
	# echo the DFFFFFFF
	max_int=2147483647
	max_intm1=2147483646
	echo $max_int?=$max_int,$(./without_comparisons $max_int $max_int),true
	echo $max_int?=$max_intm1,$(./without_comparisons $max_int $max_intm1),false
	echo $max_intm1?=$max_int,$(./without_comparisons $max_intm1 $max_int),false

	# echo the FFFFFFFF case
	min_int=-2147483648
	min_intp1=-2147483647
	echo $min_int?=$min_int,$(./without_comparisons $min_int $min_int),true
	echo $min_int?=$min_intp1,$(./without_comparisons $min_int $min_intp1),false
	echo $min_intp1?=$min_int,$(./without_comparisons $min_intp1 $min_int),false
	for i in $( seq 1 10); do
		diff1=$RANDOM
		diff2=$RANDOM
		echo $diff1?=$diff2,$(./without_comparisons $diff1 $diff2),$(./uses_comparisons $diff1 $diff2)
		same=$RANDOM
		echo $same?=$same,$(./without_comparisons $same $same),$(./uses_comparisons $same $same)
	done
} | column -t -s ,
