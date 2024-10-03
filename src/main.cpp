#include"mesh.hpp"
#include"solver.hpp"
#include<iostream>
#include<fstream>
template <typename T>
void boundary_conditions(std::vector<std::vector<T>> &field){
    // current_field(n, std::vector<int>(n, 0))
    T step = 0;
    T max_val{100.0}; 
    T n_steps = field.size(); // Number of steps 
    T step_size = max_val/(n_steps-1); // Step size, -1 to include 100.
    for(size_t i = 0; i < field.size(); i++) // Iterate over the rows 
    {  
        field[i][0] = step; // Update the value of the field.
        field[field.size()-1][i]=max_val; 
        step += step_size; // Update the value for next field.
        max_val -= step_size; 
    }   
    for (size_t i = 0; i < field.size()-1; i++)
    {
        field[0][i+1] = 0;
        
        field[i+1][field.size()-1] = 0;
    }
    
}

int main(){
    int n = 10;
    Mesh<float> mesh(n, boundary_conditions<float>);
    std::ofstream file;  
    file.open("data.dat");
    std::cout<<mesh<<std::endl;
    file<<mesh<<std::endl;
    return 0;
}