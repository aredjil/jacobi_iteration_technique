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
    std::vector<T> current_field;
    /**
     * New field at iteration t+1.
     */
    std::vector<T> new_field;
    /**
     * Class constructor to intialize boundary conditions.
     */
    template <typename F>
    Mesh(size_t n, F &boundary_conditions);
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
Mesh<T>::Mesh(size_t n, F &boundary_conditions):size(n), current_field(n*n, 0.5), new_field(n*n, 0.5){
        /**
         * Set the boundary conditions.
         */
            boundary_conditions(current_field);
            boundary_conditions(new_field);

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
            os<<" "<<m.current_field[i*m.size+j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}

