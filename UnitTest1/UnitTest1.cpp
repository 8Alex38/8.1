#include "pch.h"
#include "CppUnitTest.h"
#include "../АП-8/АП-8.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
    TEST_CLASS(MatrixTest)
    {
    public:

        TEST_METHOD(GenerateMatrixTest)
        {
            int rows = 3;
            int cols = 3;
            int minValue = 1;
            int maxValue = 10;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            GenerateMatrix(matrix, rows, cols, minValue, maxValue);

            bool valid = true;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (matrix[i][j] < minValue || matrix[i][j] > maxValue) {
                        valid = false;
                        break;
                    }
                }
            }

            Assert::IsTrue(valid);

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(CountAndSumElementsTest)
        {
            int rows = 3;
            int cols = 3;
            int minValue = 1;
            int maxValue = 10;
            int criterion = 5;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            GenerateMatrix(matrix, rows, cols, minValue, maxValue);

            int count = 0, sum = 0;
            CountAndSumElements(matrix, rows, cols, criterion, count, sum);

            bool valid = true;
            int expectedCount = 0, expectedSum = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (matrix[i][j] > criterion) {
                        expectedCount++;
                        expectedSum += matrix[i][j];
                    }
                }
            }

            if (count != expectedCount || sum != expectedSum) {
                valid = false;
            }

            Assert::IsTrue(valid);

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(SortMatrixRowsTest)
        {
            int rows = 3;
            int cols = 3;
            int minValue = 1;
            int maxValue = 10;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            GenerateMatrix(matrix, rows, cols, minValue, maxValue);

            std::vector<int> rowOrder = { 2, 0, 1 };
            SortMatrixRows(matrix, rows, cols, rowOrder);

            bool valid = true;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (matrix[i][j] != matrix[rowOrder[i]][j]) {
                        valid = false;
                        break;
                    }
                }
            }

            Assert::IsTrue(valid);

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(SortMatrixColumnsTest)
        {
            int rows = 3;
            int cols = 3;
            int minValue = 1;
            int maxValue = 10;

            int** matrix = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            GenerateMatrix(matrix, rows, cols, minValue, maxValue);

            std::vector<int> colOrder = { 1, 2, 0 };
            SortMatrixColumns(matrix, rows, cols, colOrder);

            bool valid = true;
            for (int j = 0; j < cols; ++j) {
                for (int i = 0; i < rows; ++i) {
                    if (matrix[i][j] != matrix[i][colOrder[j]]) {
                        valid = false;
                        break;
                    }
                }
            }

            Assert::IsTrue(valid);

            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

    };
}
