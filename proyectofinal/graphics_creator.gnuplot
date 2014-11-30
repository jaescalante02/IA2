#set title "A"
#set xlabel "B"
#set ylabel "C"
set term png
set output "goog/result.png"
plot "goog/cresult.txt" using 1:2 with lines title "" 
#, "nc_goog/cresult.txt" using 1:2 with lines title "incompletos"
