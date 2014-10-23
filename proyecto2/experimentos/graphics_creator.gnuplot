set size ratio -1
set xrange [0:20]
set yrange [0:20]
set trange [0:2*pi]

set parametric

# Radius
r = 7.0
#set arrow from 0,0 to sqrt(r/2),sqrt(r/2) nohead ls 2
#set label 'r' at 0.28,0.45 textcolor ls 2

fx(t) = r*cos(t)
fy(t) = r*sin(t)

gx(t) = fx(t)+10
gy(t) = fy(t)+10

set style line 1 lc rgb 'blue' pt 5   # square
set style line 2 lc rgb 'green' pt 7   # circle

set term png
set output "p.png"
plot gx(t),gy(t),  "Abad.txt" using 1:2 with points title "Abad", "Bbad.txt" using 1:2 with points title "Bbad"
#, "Agood.txt" using 1:2 with points title "Agood",  "Bgood.txt" using 1:2 with points title "Bgood"

