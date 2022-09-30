#!/bin/bash
arr=( '.-$' '-...$' '-.-.$' '-..$' '.$' '..-.$' '--.$' '....$' '..$' '.---$' '-.-$' '.-..$' '--$' '-.$' '---$' '.--.$' '--.-$' '.-.$' '...$' '-$' '..-$' '...-$' '.--$' '-..-$' '-.--$' '--..$' )
bin=./morse

time ( for i in ${arr[@]} ; do diff <( $bin 0 $i ) <( $bin 1 $i ) ; done )
time ( for i in ${arr[@]} ; do diff <( $bin 0 $i ) <( $bin 2 $i ) ; done )
time ( for i in ${arr[@]} ; do diff <( $bin 0 $i ) <( $bin 3 $i ) ; done )
