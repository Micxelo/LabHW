#pragma once

class Matrix
{
private:
	int rows;
	int cols;
	int** data;
public:
	Matrix(int r, int c);
	~Matrix();
	void Read();
	int RowSum(int row);
	void PrintRow(int row);
	int Filter(int k);
	void PrintFiltered(int k);
};
