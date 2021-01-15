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
printf "#                        ###       ### ### ###                                   #\n"
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

do_test () {
	test_dir="$srcs/$1"
	test_files=`ls $test_dir`

	for file in ${test_files[@]}; do
		echo "Compiling $file..."
		rm -rf *.out
		compile "$test_dir/$file" "ft"; ft_ret=$?
		compile "$test_dir/$file" "std"; std_ret=$?

		#[ $ft_ret -eq $std_ret ] && echo "EQ" || echo "NE"

		if [ $ft_ret -eq 1 ]; then
			true;
		fi

		#a=$([ "$b" == 5 ] && echo "$c" || echo "$d")
	done
}


for container in ${containers[@]}; do
	do_test $container
done
