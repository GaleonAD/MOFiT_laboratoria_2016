set term latex

set view map scale 1
set xrange [-0.5:511.5]
set yrange [-0.5:511.5]

splot '../output.dat' matrix with image
