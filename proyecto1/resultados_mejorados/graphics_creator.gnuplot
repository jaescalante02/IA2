set title "Comportamiento de un perceptrón aprendiendo \nel operador OR con tasa estática de 0.5"
set xlabel "Número de iteraciones"
set ylabel "Error"
set term png
set output "perceptron_or_0.5.png"
plot "perceptron_or_0.5.out" using 1:2 with lines title "0.5"
