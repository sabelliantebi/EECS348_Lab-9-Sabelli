#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <vector>
#include <iomanip> //to format matrix output
#include <stdexcept> //to exception handling

//define a class template so it works for both int and double
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix; //store the matrix info

public:
    //start an empty NxN matrix with all zeros
    Matrix(std::size_t N) {
        matrix.resize(N, std::vector<T>(N, 0)); //create NxN matrix filled with zeros
    }

    //start a matrix from an existing 2D vector
    Matrix(std::vector<std::vector<T>> nums) {
        matrix = nums; //copy the 2D vector to the class 
    }

    //add two matrices and return the result
    Matrix operator+(const Matrix &rhs) const {
        size_t N = matrix.size(); //get the size of the matrix
        Matrix result(N); //create result matrix of same size

        for (size_t i = 0; i < N; ++i) { //go through every element to add their values
            for (size_t j = 0; j < N; ++j) {
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j]; //addition of matrixes
            }
        }
        return result; //return the sum matrix
    }

    //matrixes multiplication
    Matrix operator*(const Matrix &rhs) const {
        size_t N = matrix.size(); //get the size of the matrix
        Matrix result(N); //create result matrix of same size

        for (size_t i = 0; i < N; ++i) { //do matrix multiplication using the formula
            for (size_t j = 0; j < N; ++j) {
                for (size_t k = 0; k < N; ++k) {
                    result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j]; //multiply and add
                }
            }
        }
        return result; //return the product matrix
    }

    //set the value at row i, column j to n
    void set_value(std::size_t i, std::size_t j, T n) {
        if (i >= matrix.size() || j >= matrix[i].size()) {
            throw std::out_of_range("Index out of range"); //throw error if not valid
        }
        matrix[i][j] = n; //update the value
    }

    //return the value at that position
    T get_value(std::size_t i, std::size_t j) const {
        if (i >= matrix.size() || j >= matrix[i].size()) {
            throw std::out_of_range("Index out of range"); //throw error if out of bounds
        }
        return matrix[i][j]; //get the value from pos
    }

    //return how many rows
    int get_size() const {
        return matrix.size(); //square matrix so only need one dimension
    }

    //sum all elements from the main diagonal from the top left to the bottom right
    T sum_diagonal_major() const {
        T sum = 0;
        for (size_t i = 0; i < matrix.size(); ++i) {
            sum += matrix[i][i]; //add each element on diagonal
        }
        return sum; //return total
    }

    //sum all elements from the other diagonal, so other way around, top right to bottom left
    T sum_diagonal_minor() const {
        T sum = 0;
        size_t N = matrix.size();
        for (size_t i = 0; i < N; ++i) {
            sum += matrix[i][N - 1 - i]; //add each element on the secondary diagonal
        }
        return sum; //return the total
    }

    //swap two rows if indx are valid
    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 >= matrix.size() || r2 >= matrix.size()) {
            throw std::out_of_range("Row index out of range"); //check for valid input
        }
        std::swap(matrix[r1], matrix[r2]); //swap the entire row vectors
    }

    //swap columns if index are valid
    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 >= matrix.size() || c2 >= matrix.size()) {
            throw std::out_of_range("Column index out of range"); //check for valid input
        }
        for (size_t i = 0; i < matrix.size(); ++i) {
            std::swap(matrix[i][c1], matrix[i][c2]); //swap each element in column 
        }
    }

    //print the matrix with nice formatting
    void print_matrix() const {
        for (const auto& row : matrix) { //go through each row
            for (const auto& value : row) { //go through each column in the row
                std::cout << std::setw(6) << value; //print each value with 6 char spacing
            }
            std::cout << '\n'; //move to next line after each row
        }
    }
};

#endif // __MATRIX_HPP__