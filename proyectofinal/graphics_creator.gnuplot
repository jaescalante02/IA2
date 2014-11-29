set title "A"
set xlabel "B"
set ylabel "C"
set term png
set output "a.png"
plot [:][-50:50] "t.txt" using 1:5 with lines title "0.5"
