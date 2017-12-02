#!/bin/bash

set -e

if [[ -nz "${TEST_SRCDIR}" ]]; then
	BIN="${TEST_SRCDIR}"/"${TEST_WORKSPACE}"/day1/day1
else
	BIN="$(dirname "$0")/day1"
fi

_failed=0
_out="$("${BIN}" <<< 1122)"
if [[ ${_out} != 3 ]] ; then
	echo "input 1122; expected = 3, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" <<< 1111)"
if [[ ${_out} != 4 ]] ; then
	echo "input 1111; expected = 4, got = ${_out}"
	_failed=1
fi

_out="$("${BIN}" <<< 1234)"
if [[ ${_out} != 0 ]] ; then
	echo "input 1234; expected = 0, got = ${_out}"
	_failed=1
fi

_out="$("${BIN}" <<< 91212129)"
if [[ ${_out} != 9 ]] ; then
	echo "input 91212129; expected = 9, got = ${_out}"
	_failed=1
fi

if [[ ${_failed} == 1 ]] ; then
	exit 1
fi

