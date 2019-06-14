set terminal postscript eps enhanced color 
set output "../../fig/MvsTF.eps"
set ylabel "Magnetyzacja"
set xlabel "Temperatura [K]"
set key right top
set xrange [0:6000]
plot "../../data/MvsT/F005" u 1:3 w l t 'J = 0.05' \
, "../../data/MvsT/F01" u 1:3 w l t 'J = 0.1' \
, "../../data/MvsT/F015" u 1:3 w l t 'J = 0.15' \
