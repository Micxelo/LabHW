#include "matrix.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	int n, m, k;
	std::cin >> n >> m >> k;
	Matrix matrix(n, m);
	matrix.Read();

	std::cout << matrix.Filter(k) << std::endl;
	matrix.PrintFiltered(k);

	return 0;
}

