#include"mesh.hpp"
#include"solver.hpp"
#include<iostream>
#include<fstream>
#include <iomanip>  
#include <fstream>  
#include <string>
#include<cmath>
template <typename T>
void boundary_conditions(std::vector<T> &field){
    // current_field(n, std::vector<int>(n, 0))
    auto n = std::sqrt(field.size());
    T step = 0; // Initial step 
    T max_val{100.0}; // maximum value of the oundary condditions
    T n_steps = field.size(); // Total numbr of steps 
    T step_size = max_val / (n-1); // Step size 
    for (size_t i = 0; i < n; i++)
    {
        field[i*n] = step; // Updating the left side of the grid field values 
        field[i] = 0; // Updating the upper grid field values.
        step += step_size; // incremenet the step.
    }
    for (size_t i = 0; i < n; i++)
    {
        step -= step_size; 
        field[i+n*(n-1)] = step; // Update the values of the field at the right side of the mesh
        field[i*n+n-1] = 0; // Update the values of the fieldd in at the down side of the mesh..
        }   
}

int main(){
    int n = 100;
    int max_steps = 10000;  
    int print_interval = 5;
    Mesh<float> mesh(n, boundary_conditions<float>);
    Solver<float> solver;
    solver.jacobi(mesh, max_steps, print_interval);
    return 0;
}