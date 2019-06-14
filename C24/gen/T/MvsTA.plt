set terminal postscript eps enhanced color 
set output "../../fig/MvsTA.eps"
set ylabel "Magnetyzacja"
set xlabel "Temperatura [K]"
set key right top
plot "../../data/MvsT/A005" u 1:3 w l t 'J = 0.05' \
, "../../data/MvsT/A01" u 1:3 w l t 'J = 0.1' \
, "../../data/MvsT/A015" u 1:3 w l t 'J = 0.15' \
