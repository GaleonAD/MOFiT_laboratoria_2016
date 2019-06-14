set terminal postscript eps enhanced color 
set output "../../fig/MvsTF2.eps"
set ylabel "Magnetyzacja"
set xlabel "kT/J"
set key right top
plot "../../data/MvsT/F005" u 2:3 w l t 'J = 0.05' \
, "../../data/MvsT/F01" u 2:3 w l t 'J = 0.1' \
, "../../data/MvsT/F015" u 2:3 w l t 'J = 0.15' \
