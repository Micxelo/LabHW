#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
	char input[200 + 10];

	fgets(input, sizeof(input), stdin);
	process_input(input);

	return 0;
}
