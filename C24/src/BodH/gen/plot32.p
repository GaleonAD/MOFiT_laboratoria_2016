set term latex
set out 'table32.tex'

set view map scale 1
set xrange [-0.5:31.5]
set yrange [-0.5:31.5]

splot '../output.dat' matrix with image
