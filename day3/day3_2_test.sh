#!/bin/bash

set -e

if [[ -nz "${TEST_SRCDIR}" ]]; then
	BIN="${TEST_SRCDIR}"/"${TEST_WORKSPACE}"/day3/day3_2
else
	BIN="$(dirname "$0")/day3_2"
fi

_failed=0
_out="$("${BIN}" 0)"
if [[ ${_out} != 1 ]] ; then
	echo "for input 0, expected = 1, got = ${_out}"
	_failed=1
fi

_out="$("${BIN}" 1)"
if [[ ${_out} != 2 ]] ; then
	echo "for input 1, expected = 2, got = ${_out}"
	_failed=1
fi

_out="$("${BIN}" 10)"
if [[ ${_out} != 11 ]] ; then
	echo "for input 10, expected = 11, got = ${_out}"
	_failed=1
fi

_out="$("${BIN}" 11)"
if [[ ${_out} != 23 ]] ; then
	echo "for input 11, expected = 13, got = ${_out}"
	_failed=1
fi


if [[ ${_failed} == 1 ]] ; then
	exit 1
fi

