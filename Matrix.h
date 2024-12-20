#pragma once
#include "Vector.h"

template <class T>
class Matrix : public Vector<Vector<T>>{
public:
    Matrix(size_t size = 3): Vector<Vector<T>>(size){ // конструктор на размере
        for(size_t i = 0; i < size; i++){
            this->_array[i] = Vector<T>(size-i, i);
        }
    }

    Matrix(const Matrix& mat): Vector<Vector<T>>(mat){}; // конструктор копирования
    Matrix(const Vector<Vector<T>>& vec): Vector<Vector<T>>(vec){};
    
    Matrix& operator=(const Matrix& mat){
        return Vector<Vector<T>>::operator=(mat);
    }

    Matrix operator+(const Matrix& mat){
        return Vector<Vector<T>>::operator+(mat);
    }

    Matrix operator-(const Matrix& mat){
        return Vector<Vector<T>>::operator-(mat);
    }

    Matrix operator*(const Matrix& mat){
        Matrix res(this->_size);
        for(size_t i = 0; i < this->_size; i++){
            for(size_t j = 0; j < this->_size; j++){
                for(size_t k = 0; k < this->_size; k++){
                    if ((k < this->_array[i].GetStartIndex()) || (mat._array[k].GetStartIndex() > j)){
                        continue;
                    }
                    res[i][j-mat[i].GetStartIndex()] += this->_array[i][k-mat[i].GetStartIndex()] * (mat._array[k][j-mat[k].GetStartIndex()]);
                }
            }
        }
        return res;
    }

    // Matrix operator*(const Matrix& mat){
        
    // }

    Vector<T> operator*(const Vector<T>& vec){ // матрица х вектор
        if(this->_size != vec.GetSize() + vec.GetStartIndex()){
            std::cout << "methodMV error: vectors and matrix of different sizes";
            Vector<T> res;
            return res;
        }
        Vector<T> res(this->_size);
        for(size_t i = 0; i < this->_size; i++){
            res[i] = this->_array[i] * vec;
        }
        return res;
    }

    Vector<T> multipVM(const Vector<T>& vec){
        if(this->_size != vec.GetSize() + vec.GetStartIndex()){
            std::cout << "methodVM error: vectors and matrix of different sizes";
            Vector<T> res;
            return res;
        }
        Vector<T> res(this->_size);
        size_t count = 1;
        for(size_t i = 0; i < this->_size; i++){
            for(size_t j = 0; j<count; j++){
                if((j >= vec.GetStartIndex())){
                    res[i] += this->_array[j][i-this->_array[j].GetStartIndex()] * vec[j-vec.GetStartIndex()];
                }
            }
            count++;
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat){
        for(size_t i = 0; i < mat._size; i++){
            os << mat[i];
        }
        return os;
    }
};