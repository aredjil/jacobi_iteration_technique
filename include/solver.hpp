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
class Solver{
    public:
    Solver(){};
    void jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval);
};
/**
 * The solver
 */
template <typename T>
void Solver<T>::jacobi(Mesh<T>& m, const size_t &max_steps, const size_t & print_interval){
    auto n = m.size;
    int counter =1;
    for (size_t k = 0; k < max_steps; k++)
    {
        for (size_t i = 1; i < n-1; i++)
        {
            for (size_t j = 1; j < n-1; j++)
            {
                m.new_field[i*n+j] = (1.0/4)*(m.current_field[(i-1)*n+j] + m.current_field[(i+1)*n+j]+m.current_field[i*n+j-1] + m.current_field[i*n+j+1]);
                
            }    
        }
        m.new_field.swap(m.current_field);
        // std::swap(m.current_field, m.new_field);
        
        if(k % print_interval == 0){
        const int width = 3;
        std::ostringstream file_name;
        file_name << "../gif/file_" << std::setw(width) <<std::setfill('0')<< counter << ".dat";
        counter++;
        std::ofstream file(file_name.str());
        if (file.is_open()) {
            file<<m<<std::endl;
            // file << "This is file number " << i << std::endl;  // Write some content to the file
            file.close();  // Close the file
            // std::cout << "Created: " << file_name.str() << std::endl;
        } else {
            std::cerr << "Error creating file: " << file_name.str() << std::endl;
        }
        }
        

    }
}
