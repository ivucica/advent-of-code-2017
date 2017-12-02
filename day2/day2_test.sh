#!/bin/bash

set -e

if [[ -nz "${TEST_SRCDIR}" ]]; then
	BIN="${TEST_SRCDIR}"/"${TEST_WORKSPACE}"/day2/day2
else
	BIN="$(dirname "$0")/day2"
fi

_failed=0
_out="$("${BIN}" << _EOF
5 1 9 5
7 5 3
2 4 6 8)"
if [[ ${_out} != 18 ]] ; then
	echo "expected = 18, got = ${_out}"
	_failed=1	
fi

if [[ ${_failed} == 1 ]] ; then
	exit 1
fi

