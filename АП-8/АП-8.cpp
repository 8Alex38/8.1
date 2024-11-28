#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void GenerateMatrix(int** matrix, int rows, int cols, int minValue, int maxValue) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = minValue + rand() % (maxValue - minValue + 1);
        }
    }
}

void CountAndSumElements(int** matrix, int rows, int cols, int criterion, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > criterion) {
                count++;
                sum += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

void SortMatrixRows(int** matrix, int rows, int cols, const std::vector<int>& order) {
    std::vector<std::vector<int>> tempMatrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tempMatrix[i][j] = matrix[order[i]][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

void SortMatrixColumns(int** matrix, int rows, int cols, const std::vector<int>& order) {
    std::vector<std::vector<int>> tempMatrix(rows, std::vector<int>(cols));
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            tempMatrix[i][j] = matrix[i][order[j]];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int rows = 3;
    int cols = 3;
    int minValue = 1;
    int maxValue = 10;
    int criterion = 5;

    // Динамічне виділення пам'яті
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    GenerateMatrix(matrix, rows, cols, minValue, maxValue);
    std::cout << "Generated Matrix:" << std::endl;
    PrintMatrix(matrix, rows, cols);

    int count = 0, sum = 0;
    CountAndSumElements(matrix, rows, cols, criterion, count, sum);
    std::cout << "Elements > " << criterion << ": " << count << std::endl;
    std::cout << "Sum > " << criterion << ": " << sum << std::endl;
    std::cout << "zeroing:" << std::endl;
    PrintMatrix(matrix, rows, cols);

   
    std::vector<int> rowOrder = { 2, 0, 1 };
    SortMatrixRows(matrix, rows, cols, rowOrder);
    std::cout << "Sorting Strings:" << std::endl;
    PrintMatrix(matrix, rows, cols);

  
    std::vector<int> colOrder = { 1, 2, 0 };
    SortMatrixColumns(matrix, rows, cols, colOrder);
    std::cout << "Sorting columns:" << std::endl;
    PrintMatrix(matrix, rows, cols);

    // Звільнення пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
