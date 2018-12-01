#!/bin/bash

convert_eucjp_to_utf8() {
    pattern="$1"
    for f in $(find . -maxdepth 2 -name "$pattern")
    do
        echo iconv -f euc-jp -t utf-8 $f '>' ${f}.u8
        echo mv ${f}.u8 $f
        iconv -f euc-jp -t utf-8 $f > ${f}.u8
        mv ${f}.u8 $f
    done
}

convert_eucjp_to_utf8 "*.h"
convert_eucjp_to_utf8 "*.c"
convert_eucjp_to_utf8 "sample.*"
