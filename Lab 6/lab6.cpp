#include <iostream>
#include <fstream>
//needed for formatting
#include <iomanip>

const int MAX_SIZE = 100;
int size;

//func prototypes
void readFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE]);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE]);
void addMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void multiplyMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subtractMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    std::cout << "Vivian Lara" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    readFile(matrixA, matrixB);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB);

    std::cout << "Matrix Sum (A + B):" << std::endl;
    addMatrix(matrixA, matrixB, result);
    printMatrix(result);

    std::cout << "Matrix Product (A * B):" << std::endl;
    multiplyMatrix(matrixA, matrixB, result);
    printMatrix(result);

    std::cout << "Matrix Difference (A - B):" << std::endl;
    subtractMatrix(matrixA, matrixB, result);
    printMatrix(result);

    return 0;
}


void readFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE])
{
    std::ifstream file("matrix_input.txt");
    //if it can't open the file
    if (!file)
    {
        std::cerr << "Error: Unable to open file " << std::endl;
        exit(1);
    }

    file >> size; //gets the size
    //matrixA
    //the size is the boundary
    for (int y = 0; y < (size); ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            //each row is an array inside the main array
            //y is rows
            //x is columns
            file >> matrixA[y][x];
        }
    }
    //matrixB
    for (int y = 0; y < (size); ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            file >> matrixB[y][x];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE])
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {                  //adds leading spaces to format ouput correctly (if less than 3 it will add spaces)
            std::cout << std::setw(3) << matrix[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    //goes thru adding all the nums
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            result[y][x] = matrixA[y][x] + matrixB[y][x];
        }
    }
}

void multiplyMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            //placeholder for result
            result[y][x] = 0;
            for (int k = 0; k < size; ++k)
            {
                //result = matrixA num * matrixBcorresponding num
                //       by rows          by collumns
                //ie. [1, 2, 3]  [3
                //                2
                //                1]
                // 1*3 + 2*2 + 3*1
                result[y][x] += matrixA[y][k] * matrixB[k][x];
            }
        }
    }
}

void subtractMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    //just goes thru subtracting the nums
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            result[y][x] = matrixA[y][x] - matrixB[y][x];
        }
    }
}
