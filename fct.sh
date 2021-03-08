#!/usr/bin/env bash

tested_path="../"
incl_path="$tested_path"
srcs="srcs"

CC="clang++"
CFLAGS="-Wall -Wextra -Werror -std=c++98"

if false; then
	CFLAGS+=" -fsanitize=address -g3"
fi

function pheader () {
printf "\e[0;1;94m\
# ****************************************************************************** #
#                                                                                #
#                                :::   :::   :::                                 #
#                              :+:+: :+:+:  :+: :+:                              #
#                            +:+ +:+:+ +:+ +:+                                   #
#                           +#+  +:+  +#+ +#+ +#+                                #
#                          +#+       +#+ +#+ #+#                                 #
#                         #+#       #+# #+# #+#                                  #
#                        ###       ### ### ###  containers_test                  #
#                                                                                #
# ****************************************************************************** #
\e[0m"
}

compile () {
	# 1=file 2=define used {ft/std} 3=output_file
	$CC $CFLAGS -o "$3" -I./$incl_path -DTESTED_NAMESPACE=$2 $1 2>/dev/null 1>&2
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

cmp_one () {
	# 1=path/to/file

	container=$(echo $1 | cut -d "/" -f 2)
	file=$(echo $1 | cut -d "/" -f 3)
	ft_bin="ft.$container.out"; ft_txt="ft.$container.txt"
	std_bin="std.$container.out"; std_txt="std.$container.txt"
	mkdir -p deepthought

	compile "$1" "ft"  "$ft_bin";  ft_ret=$?
	compile "$1" "std" "$std_bin"; std_ret=$?
	same_compilation=$(isEq $ft_ret $std_ret)
	std_compile=$std_ret

	> $ft_txt; > $std_txt;
	if [ $ft_ret -eq 0 ]; then
		./$ft_bin &>$ft_txt; ft_ret=$?
	fi
	if [ $std_ret -eq 0 ]; then
		./$std_bin &>$std_txt; std_ret=$?
	fi
	same_bin=$(isEq $ft_ret $std_ret)

	deepthought=$(echo "deepthought/$file" | sed s/cpp/$container.diff/)
	diff $std_txt $ft_txt 2>/dev/null 1>"$deepthought";
	same_output=$?

	rm -f $ft_bin $ft_txt $std_bin $std_txt
	[ -s "$deepthought" ] || rm -f $deepthought &>/dev/null

	printRes "$container/$file" $same_compilation $same_bin $same_output $std_compile
	rmdir deepthought &>/dev/null
}

do_test () {
	# 1=container_name
	test_dir="$srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`

	for file in ${test_files[@]}; do
		cmp_one "$test_dir/$file"
	done
}

function main () {
	pheader
	containers=(vector list map stack queue)
	if [ $# -ne 0 ]; then
		containers=($@);
	fi

	for container in ${containers[@]}; do
		printf "%40s\n" $container
		do_test $container 2>/dev/null
	done
}
