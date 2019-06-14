set terminal postscript eps enhanced color 
set output "../../fig/MvsTA2.eps"
set ylabel "Magnetyzacja"
set xlabel "kT/J"
set key left top
plot "../../data/MvsT/A005" u 2:3 w l t 'J = 0.05' \
, "../../data/MvsT/A01" u 2:3 w l t 'J = 0.1' \
, "../../data/MvsT/A015" u 2:3 w l t 'J = 0.15' \
