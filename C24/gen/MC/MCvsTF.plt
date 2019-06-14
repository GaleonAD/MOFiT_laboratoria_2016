set terminal postscript eps enhanced color 
set output "../../fig/MCvsTF.eps"
set ylabel "Magnetyzacja"
set xlabel "Nr kroku symulacji Monte Carlo"
set key right center
set xrange [0:150]
plot "../../data/MCvsT/F_Td3" w l t 'k_BT = J/3' \
, "../../data/MCvsT/F_T1" w l t 'k_BT = J' \
, "../../data/MCvsT/F_T2" w l t 'k_BT = 2J' \
, "../../data/MCvsT/F_T4" w l t 'k_BT = 4J' \
