#!/bin/bash

set -e

if [[ -nz "${TEST_SRCDIR}" ]]; then
	BIN="${TEST_SRCDIR}"/"${TEST_WORKSPACE}"/day3/day3
else
	BIN="$(dirname "$0")/day3"
fi

_failed=0
_out="$("${BIN}" 1)"
if [[ ${_out} != 0 ]] ; then
	echo "for input 1, expected = 0, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" 9)"
if [[ ${_out} != 2 ]] ; then
	echo "for input 9, expected = 2, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" 10)"
if [[ ${_out} != 3 ]] ; then
	echo "for input 10, expected = 3, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" 11)"
if [[ ${_out} != 2 ]] ; then
	echo "for input 11, expected = 2, got = ${_out}"
	_failed=1	
fi




_out="$("${BIN}" 12)"
if [[ ${_out} != 3 ]] ; then
	echo "for input 12, expected = 3, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" 23)"
if [[ ${_out} != 2 ]] ; then
	echo "for input 23, expected = 2, got = ${_out}"
	_failed=1	
fi

_out="$("${BIN}" 1024)"
if [[ ${_out} != 31 ]] ; then
	echo "for input 1024, expected = 31, got = ${_out}"
	_failed=1	
fi


if [[ ${_failed} == 1 ]] ; then
	exit 1
fi

