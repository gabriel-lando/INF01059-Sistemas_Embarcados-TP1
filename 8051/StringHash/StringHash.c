#include <stdlib.h>
#include <string.h>

#define SIZE 100

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
	unsigned char str[SIZE] = "y7B0oYSqL6DrbDljgtrXENvpgqsX2WEofE6ohBcFQGA8bcLfDsYHIbk8qJTkyXSosaSqy4z5Go40FeEB6EW6BE41RyZARqTUHZmh";

	hash(str);
 
	return 0;
}
