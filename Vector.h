#pragma once
#include <iostream>
#include <math.h>

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size = 3, size_t startIndex = 0){// конструктор c размером и индексом    
        _size = size;
        _startIndex = startIndex;
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++){
            _array[i] = 0; 
        }
    }
    Vector(size_t size, T array[], size_t startIndex){// конструктор со статическим массивом
        _size = size;
        _startIndex = startIndex;
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }
    Vector(const Vector& vec){ // конструктор копирования
        _size = vec._size;
        _startIndex = vec._startIndex;
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
    }
    Vector(Vector&& vec){// конструктор переноса
        _size = vec._size;
        _startIndex = vec._startIndex;
        _array = vec._array;
        vec._array = nullptr;
    }
    ~Vector(){// деконструктор
        delete [] _array;
    }

    size_t GetSize() const{
        return _size;
    }
    size_t GetStartIndex() const{
        return _startIndex;
    }
    size_t GetVisibleSize() const{
        return _size + _startIndex;
    }

    T& operator[](size_t pos) const{
        return _array[pos];
    }

    Vector& operator=(const Vector& vec){
        if(this == &vec){
            return *this;
        }
        if(_size != vec._size){
            delete [] _array;
            _array = new T[vec._size];
        }
        _size = vec._size;
        _startIndex = vec._startIndex;
        for(size_t i = 0; i < _size; i++){
            _array[i] = vec[i];
        }
        return *this;
    }

    Vector operator+(const Vector& vec){
        if((_size != vec._size) && (_startIndex != vec._startIndex)){
            std::cout << "operator+ error: vectors of different sizes"<<std::endl;;
            return 0;
        }
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i++){
            res[i] = _array[i] + vec._array[i];
        }
        return res;
    }

    Vector operator-(const Vector& vec){
        if((_size != vec._size) && (_startIndex != vec._startIndex)){
            std::cout << "operator+ error: vectors of different sizes"<<std::endl;;
            return 0;
        }
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i++){
            res[i] = _array[i] - vec._array[i];
        }
        return res;
    }

    Vector operator*(const Vector& vec){ // скалярное произведение
        if((_size != vec._size) && (_startIndex != vec._startIndex)){
            std::cout << "operator+ error: vectors of different sizes"<<std::endl;;
            return 0;
        }
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i++){
            res[i] = _array[i] * vec._array[i];
        }
        return res;
    }

    Vector operator*(const int& num){
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size + _startIndex; i++){
            res[i] = _array[i] * num;
        }
        return res;
    };

    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){
        if(tmp._size == 0){
            return os;
        }
        size_t visibleSize = tmp._size + tmp._startIndex;
        os << "(";
        for(size_t i = 0; i < visibleSize; i++){
            if(i < tmp._startIndex){
                os<<"0";
            }else{
                os<<tmp._array[i - tmp._startIndex];
            }
            if(visibleSize - i - 1){
                os << " ";
            }
        }
        os << ")" << std::endl;
        return os;
    }

};