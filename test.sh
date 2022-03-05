#!/bin/zsh
# test script for canons a 3,
# ./test.sh <type: 0, 1, 2, 3> <number of notes: 1, ...> <number of tests: 1,...>
#
d=$(date "+%s") 
mkdir test_series/$d
for ((i=1;i<=$3;i++)); do
    ./sketch $1 $2
    lilypond.sh transcription.ly
    c=$(printf "%03d" $i)
    pdf="ca3.$d.$1$2.$c.pdf"
    lyl="ca3.$d.$1$2.$c.ly"
    mid="ca3.$d.$1$2.$c.midi"
    cp transcription.pdf test_series/$d/$pdf
    cp transcription.ly test_series/$d/$lyl
    cp transcription.midi test_series/$d/$mid
    echo $d
done

pdfunite $(ls test_series/$d/*.pdf | sort -n) test_series/$d/output.pdf
