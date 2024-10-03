#pragma once
#include<iostream>
#include<vector>
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
    Mesh(size_t n);
    /**
     * Printing the mesh
     */
    template <typename R>
    friend std::ostream& operator<<(std::ostream& os, const Mesh<R>& m);
    /**
     * A function that sets the boundary conditons and returns the field.
     */
};
/**
 * Constructor definition to intilize the mesh using the boundary conditions using the function.
 */
template <typename T>
Mesh<T>::Mesh(size_t n):size(n), current_field(n , std::vector<T>(n, 0)){
        /**
         * Set the boundary conditions.
         */
    // current_field(n, std::vector<int>(n, 0))
    T max_val{100.0}; 
    T n_steps = size; // Number of steps 
    T step_size = max_val/n_steps; // Step size
    for(size_t i = 0; i < size; i++) // Iterate over the rows 
    {
        current_field[i][0] = max_val; // Update the value of the field. 
        max_val -= step_size; // Update the value for next field. 
    }
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
            os<<"\t"<<m.current_field[i][j]<<"\t";
        }
        os<<std::endl;
        
    }
    return os;
}
