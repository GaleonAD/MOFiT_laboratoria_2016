set terminal postscript eps enhanced color 
set output "../../fig/MCvsLF.eps"
set ylabel "Magnetyzacja"
set xlabel "Nr kroku symulacji Monte Carlo"
set key right center
set xrange [0:150]
plot "../../data/MCvsL/F32" w l t 'L = 32' \
, "../../data/MCvsL/F64" w l t 'L = 64' \
, "../../data/MCvsL/F512" w l t 'L = 512' \
