#!/usr/bin/env bash

if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo "Usage: $0 <file> [namespace=ft]"
	exit 1
fi

source fct.sh
testedNamespace=$([[ -z "$2" ]] && echo "ft" || echo "$2")
output_file="a.out"

compile "$1" "${testedNamespace}" "${output_file}" && \
	./${output_file}
