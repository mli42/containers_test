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

compile () {
	echo "Compiling $1..."
	$mli_cc $mli_cflags -I./$incl_path $1 2>/dev/null 1>&2
	return $?
}

do_test () {
	test_files=`ls $srcs/$1`

	for file in ${test_files[@]}; do
		rm -rf *.out
		compile $file
		#a=$([ "$b" == 5 ] && echo "$c" || echo "$d")
	done
}


for container in ${containers[@]}; do
	do_test $container
done
