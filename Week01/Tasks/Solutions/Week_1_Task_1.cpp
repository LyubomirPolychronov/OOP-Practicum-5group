#include <iostream>

namespace MatrixNS {
	int** allocateMatrix(int n, int m) {
		int** matrix = new int* [n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[m];
		}
		return matrix;
	}

	void freeMemory(int n, int** matrix) {
		for (int i = 0; i < n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	void readMatrix(int n, int m, int** matrix) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> matrix[i][j];
			}
		}
	}

	void printMatrix(int n, int m, int** matrix) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	int** transpondMatrix(int n, int m, int** matrix) {
		int** transMatrix =allocateMatrix(m, n);
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				transMatrix[i][j] = matrix[j][i];
			}
		}
		return transMatrix;
	}

	void swapRows(int** matrix, int rowOne, int rowTwo) {
		int* temp = matrix[rowOne];
		matrix[rowOne] = matrix[rowTwo];
		matrix[rowTwo] = temp;
	}
}

int main()
{

	
	using namespace MatrixNS;
	int** matrix;
	int n,m;
	std::cin >> n >> m;
	matrix = allocateMatrix(n, m);
	readMatrix(n, m, matrix);
	std::cout << std::endl;
	int** transMatrix = transpondMatrix(n, m, matrix);
	printMatrix(m, n, transMatrix);
	freeMemory(m, transMatrix);
	std::cout << std::endl;
	if (n > 1)
	{
		swapRows(matrix, n - 1, n - 2);
		printMatrix(n, m, matrix);
	}
	freeMemory(n, matrix);
}
