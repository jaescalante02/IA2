set ylabel "Errores"
set xlabel "Porcentaje de archivo de prueba"
set term png
set output "p.png"
set xrange [45:100]
set yrange [0:6]
plot "a.txt" using 1:2 with lines title "Errores vs. Porcentaje de archivo de prueba"
