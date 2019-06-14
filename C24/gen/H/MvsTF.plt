set encoding utf8
set terminal postscript eps enhanced color 
set output "../../fig/MvsHF.eps"
set ylabel "Magnetyzacja"
set xlabel "Zewnetrzne pole H [1/μ_0]"
set key right bottom
set yrange [-1.05:1.05]
set xrange [-0.2:0.2]
plot "../../data/MvsH/F005" u ((-1)*$2):1 w l t 'kT = J = 0.05, ' \
, "../../data/MvsH/F01" u ((-1)*$2):1 w l t 'kT = J = 0.1' \
, "../../data/MvsH/F005d3" u ((-1)*$2):1 w l t '3kT = J = 0.05' \
, "../../data/MvsH/F005m3" u ((-1)*$2):1 w l t 'kT/3 = J = 0.05' \
, "../../data/MvsH/F005m30" u ((-1)*$2):1 w l t 'kT/30 = J = 0.05' \
