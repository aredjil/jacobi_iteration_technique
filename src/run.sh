#!/bin/bash
make clean 
make 
./mesh.x
gnuplot "../gif/heat_map.gp"
