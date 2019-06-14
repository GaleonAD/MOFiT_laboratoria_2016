set encoding utf8
set terminal postscript eps enhanced color 
set output "../../fig/MvsHA.eps"
set ylabel "Magnetyzacja"
set xlabel "Zewnetrzne pole H [1/μ_0]"
set key right bottom
#set yrange [-1.05:1.05]
set xrange [-1:1]
plot "../../data/MvsH/A005" u ((-1)*$2):1 w l t 'kT = J = -0.05, ' \
, "../../data/MvsH/A01" u ((-1)*$2):1 w l t 'kT = J = -0.1' \
, "../../data/MvsH/A005d3" u ((-1)*$2):1 w l t '3kT = J = -0.05' \
, "../../data/MvsH/A005m3" u ((-1)*$2):1 w l t 'kT/3 = J = -0.05' \
, "../../data/MvsH/A005m30" u ((-1)*$2):1 w l t 'kT/5 = J = -0.05' \
