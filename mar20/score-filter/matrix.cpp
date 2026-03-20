#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
	data = new int*[rows];
	for (int i = 0; i < rows; ++i)
		data[i] = new int[cols];
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i)
		delete[] data[i];
	delete[] data;
}

void Matrix::Read()
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			std::cin >> data[i][j];
}

int Matrix::RowSum(int row)
{
	int sum = 0;
	for (int j = 0; j < cols; ++j)
		sum += data[row][j];
	return sum;
}

void Matrix::PrintRow(int row)
{
	for (int j = 0; j < cols; ++j)
		std::cout << data[row][j] << " ";
	std::cout << std::endl;
}

int Matrix::Filter(int k)
{
	int count = 0;
	for (int i = 0; i < rows; ++i)
		if (RowSum(i) >= k * cols)
			count++;
	return count;
}

void Matrix::PrintFiltered(int k)
{
	bool printed = false;
	for (int i = 0; i < rows; ++i) {
		int sum = RowSum(i);
		if (sum >= k * cols) {
			std::cout << sum << " ";
			PrintRow(i);
			printed = true;
		}
	}
	if (!printed)
		std::cout << "EMPTY" << std::endl;
}
