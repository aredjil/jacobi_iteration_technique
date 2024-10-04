#pragma once 
#include<iostream>
#include<vector>
#include <fstream>
#include<cmath>
#include"mesh.hpp"
#include <iomanip>  
#include <fstream>  
#include <string>
template <typename T>
/**
 * This calss solves the Laplace equation in 2 D using Jacobi iteration technique.  
 */
class Solver{
    public:
    /**
     * Constructor of the solver class
     */
    Solver(){};
    /**
     * Solver method.
     * @param Mesh<T>& m: grid instance.
     * @param const size_t &max_steps: Number of iterations. 
     * @param const size_t & print_interval: interval for a snapshot of the grid. used to generating the GIF. 
     */
    void jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval);
    private: 
    /**
     * Print results to a files 
     */
    void print_results(Mesh<T> &m, size_t &counter);
};
/**
 * The solver
 */
template <typename T>
void Solver<T>::jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval){
    auto n = m.size;
    size_t counter =1;
    for (size_t k = 0; k < max_steps; k++) // Iterate over the total number of steps 
    {
        for (size_t i = 1; i < n-1; i++) // Iterate the rows.
        {
            for (size_t j = 1; j < n-1; j++)// Iterate the columns.
            {
                // Update rule.
                m.new_field[i*n+j] = (1.0/4)*(m.current_field[(i-1)*n+j] + m.current_field[(i+1)*n+j]+m.current_field[i*n+j-1] + m.current_field[i*n+j+1]);
                
            }    
        }
        // Swap the current field values with the new field values before the next iteration
        m.new_field.swap(m.current_field);        
        if(k % print_interval == 0){
        print_results(m, counter);
        }
        

    }
}
template <typename T>
void Solver<T>::print_results(Mesh<T> &m, size_t &counter){
    const int width = 3;
        std::ostringstream file_name;
        file_name << "../gif/file_" << std::setw(width) <<std::setfill('0')<< counter << ".dat";
        counter++;
        std::ofstream file(file_name.str());
        if (file.is_open()) {
            file<<m<<std::endl;
            file.close();  // Close the file
        } else {
            std::cerr << "Error creating file: " << file_name.str() << std::endl;
        }
}
