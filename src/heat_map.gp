set terminal png 
set output "heat_map.png"
set pm3d interpolate 2,2
plot 'data.dat' matrix with image