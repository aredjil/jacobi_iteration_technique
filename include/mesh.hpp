#pragma once
#include<iostream>
#include<vector>
#include <fstream>
template <typename T>
/**
 * This class store th grid used 
 * for solving Laplace equation 
 * using Jacobi iteration technique
 */
class Mesh{
    public:
    /**
     * Size of the square grid.
     */
    size_t size;
    /**
     * Current field at iteration t.
     */
    std::vector<std::vector<T>> current_field;
    /**
     * New field at iteration t+1.
     */
    std::vector<std::vector<T>> new_field;
    /**
     * Class constructor to intialize boundary conditions.
     */
    template <typename F>
    Mesh(size_t n, F boundary_conditions);
    /**
     * Printing the mesh
     */
    template <typename R>
    friend std::ostream& operator<<(std::ostream& os, const Mesh<R>& m);
};
/**
 * Constructor definition to intilize the mesh using the boundary conditions using the function.
 */
template <typename T>
template <typename F>
Mesh<T>::Mesh(size_t n, F boundary_conditions):size(n), current_field(n, std::vector<T>(n, 0.5)){
        /**
         * Set the boundary conditions.
         */
    // // current_field(n, std::vector<int>(n, 0))
    // T step = 0;
    // T max_val{100.0}; 
    // T n_steps = size; // Number of steps 
    // T step_size = max_val/(n_steps-1); // Step size, -1 to include 100.
    // for(size_t i = 0; i < size; i++) // Iterate over the rows 
    // {
    //     current_field[i][0] = step; // Update the value of the field. 
    //     step += step_size; // Update the value for next field. 
    // }
    boundary_conditions(current_field);
}
/**
 * Definition of the print functionality of the mesh calss
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Mesh<T>& m){
    os<<std::endl;
    for (size_t i = 0; i < m.size; i++)
    {
        for (size_t j = 0; j < m.size; j++)
        {
            // os<<" "<< m.current_field[i][j] <<" ";
            os<<" "<<m.current_field[i][j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}