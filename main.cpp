#include <iostream>
#include <fstream>  //4 file input
#include <string>
#include "matrix.hpp"

int main() {
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename; //get the file name from user

    std::ifstream file(filename); //open the file
    if (!file.is_open()) { //check if it opened 
        std::cerr << "Could not open file.\n"; //display error message if nor
        return 1; //exit with error
    }

    int N, type_flag;
    file >> N >> type_flag; //read matrix size and type

    if (N <= 0 || (type_flag != 0 && type_flag != 1)) {
        std::cerr << "Invalid matrix size or type flag.\n"; //invalid data
        return 1; //exit prog
    }

    if (type_flag == 0) {
        //if int

        //read first matrix
        std::vector<std::vector<int>> m1_data(N, std::vector<int>(N)); //create 2D vector of ints
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!(file >> m1_data[i][j])) { //check if value is ok
                    std::cerr << "Error reading matrix 1 vals \n"; //error message
                    return 1; //exit prog
                }
            }
        }

        //read second matrix
        std::vector<std::vector<int>> m2_data(N, std::vector<int>(N)); //create 2D vector of ints
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!(file >> m2_data[i][j])) { //check if is ok
                    std::cerr << "Error reading matrix 2 vals \n"; //error message
                    return 1; //exit prog
                }
            }
        }

        Matrix<int> m1(m1_data); //create object from 1st matrix
        Matrix<int> m2(m2_data); //create object from 2nd matrix

        std::cout << "\nMatrix 1:\n";
        m1.print_matrix(); //print matrix1

        std::cout << "\nMatrix 2:\n";
        m2.print_matrix(); //print matrix2

        std::cout << "\nMatrix Addition:\n";
        try {
            (m1 + m2).print_matrix(); //try to add and print result
        } catch (const std::exception& e) {
            std::cerr << "Error adding matrices: " << e.what() << "\n"; //atch error if 
        }

        std::cout << "\nMatrix Multiplication:\n";
        try {
            (m1 * m2).print_matrix(); //try to multiply and print result
        } catch (const std::exception& e) {
            std::cerr << "Error multiplying matrices: " << e.what() << "\n"; //catch error 
        }

        std::cout << "\nSum of Major Diagonal: " << m1.sum_diagonal_major() << "\n"; //print major diagonal sum
        std::cout << "Sum of Minor Diagonal: " << m1.sum_diagonal_minor() << "\n"; //print minor diagonal sum

    } else {
        //if double

        //read first matrix
        std::vector<std::vector<double>> m1_data(N, std::vector<double>(N)); //create 2D vecor of doubles
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!(file >> m1_data[i][j])) { //check if value is ok
                    std::cerr << "Error reading matrix 1 values from file.\n"; //error message
                    return 1; //exit prog
                }
            }
        }

        //read second matrix
        std::vector<std::vector<double>> m2_data(N, std::vector<double>(N)); //create 2D vector of doubls
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!(file >> m2_data[i][j])) { //check if value is ok
                    std::cerr << "Error reading matrix 2 values from file.\n"; //error message
                    return 1; //exit prog
                }
            }
        }

        Matrix<double> m1(m1_data); //create object from matrix 1
        Matrix<double> m2(m2_data); //create object from matrix 2

        std::cout << "\nMatrix 1:\n";
        m1.print_matrix(); //print matrix 1

        std::cout << "\nMatrix 2:\n";
        m2.print_matrix(); //print matrix 2

        std::cout << "\nMatrix Addition:\n";
        try {
            (m1 + m2).print_matrix(); //try to add and print result
        } catch (const std::exception& e) {
            std::cerr << "Error adding matrices: " << e.what() << "\n"; //catch error 
        }

        std::cout << "\nMatrix Multiplication:\n";
        try {
            (m1 * m2).print_matrix(); //try to multiply and print result
        } catch (const std::exception& e) {
            std::cerr << "Error multiplying matrices: " << e.what() << "\n"; //catch error 
        }

        std::cout << "\nSum of Major Diagonal: " << m1.sum_diagonal_major() << "\n"; //print major diagonal sum
        std::cout << "Sum of Minor Diagonal: " << m1.sum_diagonal_minor() << "\n"; //print minor diagonal sum
    }

    file.close(); //close file
    return 0; //end prog
}