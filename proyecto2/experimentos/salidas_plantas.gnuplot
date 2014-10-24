set xlabel "Número de iteraciones"
set ylabel "Error"
set term png
set output "p.png"
set xrange [0:5000]
set yrange [0:50]
plot "a.txt" using 1:2 with lines title "Error vs. Iteración"
