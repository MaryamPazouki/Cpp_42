#!/usr/bin/env bash

# overrides
quiet=1
go="go"

if [[ $# -gt 0 ]] && [[ "$1" = "go" || "$2" = "go" || "$3" == "go"  ]]; then
	go="go"
fi

if [[ $# -gt 0 ]] && [[ "$1" = "quick" || "$2" = "quick" || "$3" == "quick"  ]]; then
	quick="quick"
fi


function maketest() {
	if [ $quiet = 0 ]; then
		echo "$@"
	fi

	echo -n "n = $(printf "%5d" $(echo "$@" | wc -w)) -> "
	tmpInput=$(mktemp)
	echo $@ | sed 's/ /\n/g' | sort -n > $tmpInput
	tmpPmerge=$(mktemp)
	PmergeOneLine="$(./PmergeMe $@ | grep "After:" | sed -e 's/After: //')"
	echo $PmergeOneLine | sed 's/ /\n/g' > $tmpPmerge

	test_success=1

	if [ $quiet = 0 ]; then
		echo "------------------"
		echo ">>> diff:"
	fi 
	if ! diff -q $tmpPmerge $tmpInput > /dev/null; then
		if [ $quiet = 0 ]; then
			diff $tmpPmerge $tmpInput
		fi
		test_success=0
	else
		if [ $quiet = 0 ]; then
			echo ">>> cool!"
		fi
	fi
	if [ $quiet = 0 ]; then
		echo "------------------"
		echo ">>> PmergeMe-Out:"
		sed -z -i 's/\n/ /g' $tmpPmerge
		cat $tmpPmerge
		echo
		echo "------------------"
		echo ">>> Sort-Out:"
		sed -z -i 's/\n/ /g' $tmpInput
		cat $tmpInput
		echo
		echo "------------------"
	fi
	rm $tmpPmerge
	rm $tmpInput
	if [ $test_success -eq 0 ]; then
		echo -e "\e[31mKO: test_failed\e[0m"
		exit 1
	else
		echo -e "\e[32mOK: test_success\e[0m"
	fi
}

function optimalNumberTest() {
	echo -e "-----=[ \e[36mTesting optimal number of comparisons...\e[0m ]=-----\n"
	if [ -n "$quick" ]; then
		testNum=50
	else
		testNum=200
	fi

	declare optimalNumbers=(0 1 3 5 7 10 13 16 19 22 26 30 34 38 42 46 50	54 58 62 66 71 76 81 86 91 96 101 106 111 116 121 126)
	declare -a optimalArr
	for ((n=0; n < ${#optimalNumbers[@]}; n++)); do
		optimalArr[n+1]=${optimalNumbers[n]}
	done
	for key in ${!optimalArr[@]}; do
		echo -n "Testing for n = $key, should be <= ${optimalArr[key]} "
		for ((i=1; i < $testNum; i++)); do
			res=$(./PmergeMe `shuf -i 1-100 -n $key | tr "\n" " "` | grep "Comparisons" | cut -d " " -f 2)
			# echo "res: $res" 
			# echo "optimalArr[key]: ${optimalArr[key]}" 
			if [ $res -gt ${optimalArr[key]} ]; then
				echo -e "\n----------------=[ \e[31mKO\e[0m ]=----------------\n"
				exit 1
			fi
			if [[ "$((i % 10))" = "0" ]]; then
				echo -n "."
			fi
		done
		echo
	done
	echo -e "\n----------------=[ \e[32mOK\e[0m ]=----------------\n"
}

function sortingTest() {
	echo -e "-----=[ \e[36mTesting correctness of sorting...\e[0m ]=-----\n"
	if [ -n "$quick" ]; then
		maketest `shuf -i 1-100000 -n 4000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 3000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5103 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 7077 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5002 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5005 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5555 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 1 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 2 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 3 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 7 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 8 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 9 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 11 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 12 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 13 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 300 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 301 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 371 | tr "\n" " "`
	else

		# my special test-cases which where somehow special in the development
		# process
		maketest 7 1 5 2 3 4
		maketest 8 41 26 5 24 14 12 6 33 21 9
		maketest 64 82 59 66 32 85 95 23 81 89 50 38 100
		# used to cause duplications
		maketest 3 4 2 5 6 7 23 8 21 8990
		maketest 860 3425 4068 2783 633 383 1146 4347 4090 3890 1468 1604 2679 361 472 4369 4952 180 179 2858 2646 2042 3521 1644 1635 455 2436 1551 1959 2528 718 1065 463 1616 4544 3199 3157 4698 4315 2508 1052 4976 424 4057 1009 2431 976 4800 3435 2387 4743 3881 1701 3138 2881 3795 870 1406 2962 2361 635 174 1493 4614 3524 4059 4954 212 2036 2126 1900 623 4571 3430 2462 2920 1443 2283 2947 246 1015 4584 512 89 3585 2346 1692 2184 2475 1734 203 2076 2922 2422 493 256 4203 2301 1047 1181 922 2274 3957 868 1755 4938 2622 2196 3696 2035 4654 2995 3212 3692 587 2377 1193 1652 3526 1618 520 3827 2146 4140 1006 4916 3928 371 4753 2306 2592 1834 272 4597 1958 1194 741 3999 4256 1752 1426 3233 1995 4427 812 1221 1668 359 3256 345 1023 2021 925 744 1210 2951 3542 697 3272 826 1336 4076 29 4892 3012 4061 158 4805 1903 677 2870 1929 3151 1856 4766 3589 1715 595 4833 2074 4142 4955 2275 3715 1811 3552 3507 2345 4996 435 189 1022 2317 3359 2665 44 2800 504 2287 1472
		maketest 30 66 234 269 223 82 63 57 168 270 232 117 258 193 24 298 29 156 266 25 163 12 280 235 27 5 73 195 96 206 22 231 296 259 151 174 28 35 182 114 219 294 61 282 253 136 154 118 80 265 121 65 155 244 140 215 277 196 204 9 227 220 53 10 79 267 245 67 111 254 75 92 175 160 153 112 297 52 47 252 198 49 284 224 237 74 173 240 276 77 129 189 44 218 288 176 126 68 181 272 33 192 292 274 87 123 55 132 2 54 56 217 183 213 146 4 8 99 228 256 115 289 18 85 116 247 233 59 46 210 170 190 257 62 255 113 138 145 124 281 295 241 14 159 90 43 162 249 144 6 11 60 91 214 1 165 152 178 242 222 142 300 100 271 225 179 125 105 273 226 207 120 106 108 71 141 15 216 287 261 167 81 148 158 260 279 72 263 150 13 64 131 171 7 251 278 194 135 262 41
		maketest 9 109 50 216 41 116 20 170 60 35 108 190 24 59 267 168 102 120 220 26 125 92 1 45 240 135 86 100 162 90 181 10 16 286

		# just a couple of random cases
		maketest `shuf -i 1-100000 -n 1 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 2 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 2 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 2 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 3 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 3 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 3 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 4 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 6 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 7 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 8 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 9 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 11 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 12 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 13 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 23 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 34 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 42 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 100 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 101 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 142 | tr "\n" " "`
		maketest `shuf -i 1-300 -n 200 | tr "\n" " "`
		maketest `shuf -i 1-1000 -n 300 | tr "\n" " "`
		maketest `shuf -i 1-10000 -n 1000 | tr "\n" " "`
		maketest `shuf -i 1-10000 -n 1001 | tr "\n" " "`
		maketest `shuf -i 1-10000 -n 5000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5001 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5002 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5005 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5007 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5103 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 5555 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 7077 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 10000 | tr "\n" " "`
		maketest `shuf -i 1-100000 -n 15000 | tr "\n" " "`
	fi
	echo -e "\n----------------=[ \e[32mOK\e[0m ]=----------------\n"
}

echo
# if [[ -z "$go" ]]; then
# 	echo -e "-----=[ \e[36mProceed with optimal comp tests? [y/*]\e[0m ]=-----"
# 	read -r answer
# 	if [[ "$answer" = "y" ]]; then
# 		optimalNumberTest
# 	fi
# else
# 	optimalNumberTest
# fi

if [ ! -e ./PmergeMe ]; then
	echo -en "\e[031mExecutable './PmergeMe' not found! Plz rename or compile it!\e[0m"
	exit 1
fi

if [[ -z "$go" ]]; then
	echo -e "-----=[ \e[36mProceed with sorting tests? [y/*]\e[0m ]=-----"
	read -r answer
	if [[ "$answer" = "y"  || -n "$go" ]]; then
		sortingTest
	fi
else
	sortingTest
fi

echo -e "\n\e[33m----------------=[ \e[32mGood job 8) \e[33m]=----------------\e[0m\n"
