set terminal postscript eps enhanced color 
set output "../../fig/MCvsLA.eps"
set ylabel "Magnetyzacja"
set xlabel "Nr kroku symulacji Monte Carlo"
set key right top
set xrange [0:150]
plot "../../data/MCvsL/A32" w l t 'L = 32' \
, "../../data/MCvsL/A64" w l t 'L = 64' \
, "../../data/MCvsL/A512" w l t 'L = 512' \
