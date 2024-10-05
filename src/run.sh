#!/bin/bash
make clean 
make 
./mesh.x
gnuplot "heat_map.gp"
