#pragma once 
#include<iostream>
#include<vector>
#include <fstream>
#include"mesh.hpp"
template <typename T>
class Solver{
    public:
    void jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval);
    void swap(Mesh<T>& m, Mesh<T>& n);
};
/**
 * The solver
 */
template <typename T>
void Solver<T>::jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval){
    for (size_t t = 0; t < max_steps; t++)
    {
        for (size_t i = 1; i < m.size-1; i++)
    {
            for (size_t j = 1; j < m.size-1; j++)
            {
                m.new_field[i][j] = (1/4)*(m.current_field[i-1][j] + m.current_field[i+1][j] + m.current_field[i][j-1] + m.current_field[i][j+1])
            }
    }

    swap(m.new_field, m.current_field);
    t % 100 == 0?std::cout<<m<<std::endl; : continue;
    }
}
/**
 * Swap function 
 */
template <typename T>

void Solver<T>::swap(Mesh<T>& m, Mesh<T>&n){
    auto temp;
    temp = m; 
    m = n; 
    n = temp;
}