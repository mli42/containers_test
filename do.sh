#!/usr/bin/env bash

tested_path="../"
incl_path="$tested_path"
srcs='./srcs'

mli_cc="clang++"
mli_cflags="-Wall -Wextra -Werror -std=c++98"

if false; then
	mli_cflags+=" -fsanitize=address -g3"
fi

printf "\e[0;1;94m"
printf "# ****************************************************************************** #\n"
printf "#                                                                                #\n"
printf "#                                :::   :::   :::                                 #\n"
printf "#                              :+:+: :+:+:  :+: :+:                              #\n"
printf "#                            +:+ +:+:+ +:+ +:+                                   #\n"
printf "#                           +#+  +:+  +#+ +#+ +#+                                #\n"
printf "#                          +#+       +#+ +#+ #+#                                 #\n"
printf "#                         #+#       #+# #+# #+#                                  #\n"
printf "#                        ###       ### ### ###  containers_test                  #\n"
printf "#                                                                                #\n"
printf "# ****************************************************************************** #\n\n"
printf "\e[0m"

containers=(vector)
if [ $# -ne 0 ]; then
	containers=($@);
fi

compile () {
	# 1=file 2=define used {ft/std}
	$mli_cc $mli_cflags -o "$2.out" -I./$incl_path -DTESTED_NAMESPACE=$2 $1 2>/dev/null 1>&2
	return $?
}

printRes () {
	# 1=file 2=compile 3=bin 4=output 5=std_compile
	b[0]="\e[1;92m✅\e[m"; b[1]="\e[1;91m❌\e[m";
	s_bool[0]="Y"; s_bool[1]="N";
	printf "%-35s: COMPILE: ${b[$2]} | RET: ${b[$3]} | OUT: ${b[$4]} | STD: [${s_bool[$5]}]\n" $1
}

isEq () {
	[ $1 -eq $2 ] && echo 0 || echo 1
}

do_test () {
	test_dir="$srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`

	for file in ${test_files[@]}; do
		compile "$test_dir/$file" "ft"; ft_ret=$?
		compile "$test_dir/$file" "std"; std_ret=$?
		same_compilation=$(isEq $ft_ret $std_ret)
		std_compile=$std_ret

		> ft.txt; > std.txt;
		if [ $ft_ret -eq 0 ]; then
			./ft.out &>ft.txt; ft_ret=$?
		fi
		if [ $std_ret -eq 0 ]; then
			./std.out &>std.txt; std_ret=$?
		fi
		same_bin=$(isEq $ft_ret $std_ret)

		deepthought="deepthought/$1_$file.txt"
		diff std.txt ft.txt 2>/dev/null 1>"$deepthought";
		same_output=$?

		rm -f {ft,std}.{txt,out}
		[ -s "$deepthought" ] || rm -f $deepthought &>/dev/null

		printRes "$1/$file" $same_compilation $same_bin $same_output $std_compile
	done
}

mkdir -p deepthought
for container in ${containers[@]}; do
	printf "%40s\n" $container
	do_test $container 2>/dev/null
done
rmdir deepthought &>/dev/null
