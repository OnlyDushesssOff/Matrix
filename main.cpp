#pragma once
#include "Matrix.h"

int main(){

    int arr1[5] = {1,2,3,4,5};
    Vector<int> vec1 = Vector<int>(2,arr1,1);
    std::cout << vec1 << std::endl;
    // std::cout << vec1 * vec1 << std::endl;
    // Vector<int> vec2 = Vector<int>(vec1);
    // Vector<int> vec3 = Vector<int>(5,arr1,1);

    Vector<Vector<int>> vec = Vector<Vector<int>>(3);
    for(int i = 0; i < 3; i++){
        vec[i] = Vector<int>(3-i,arr1,i);
    }
    Matrix<int> mat = Matrix(vec);
    std::cout << mat <<std::endl;
    // std::cout << mat+mat << std::endl;
    // std::cout << mat-mat << std::endl;
    // std::cout << mat*mat << std::endl;
    std::cout << "M x V = "<<mat * vec1 << std::endl;
    std::cout << "V x M = "<<vec1 * mat << std::endl;
}