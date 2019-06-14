set terminal postscript eps enhanced color 
set output "../../fig/MCvsTA.eps"
set ylabel "Magnetyzacja"
set xlabel "Nr kroku symulacji Monte Carlo"
set key right bottom
set xrange [0:150]
plot "../../data/MCvsT/F_Ad3" w l t 'k_BT = J/3' \
, "../../data/MCvsT/F_A1" w l t 'k_BT = J' \
, "../../data/MCvsT/F_A2" w l t 'k_BT = 2J' \
, "../../data/MCvsT/F_A4" w l t 'k_BT = 4J' \
