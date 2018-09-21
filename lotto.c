#include <stdio.h>
#include <string.h>

static int matched (int * drawn, int * bought)
{
	int matched = 0;

	while (*drawn && *bought) {
		if (*bought)
			while (*drawn && *drawn < *bought)
				drawn++;
		if (*drawn)
			while (*bought && *bought < *drawn)
				bought++;
		if (*drawn && *bought)
			if (*bought == *drawn)
				matched++, bought++, drawn++;
	}
	return matched;
}

int main(int argc, char **argv)
{
	int d[7] = { 0 };
	int b[7] = { 0 };
	int n = -1;

	while (*++argv) {
			if (sscanf(*argv, "%u %u %u %u %u %u",
			    b+0, b+1, b+2, b+3, b+4, b+5) != 6)
				printf("Insufficient numbers\n");
			else if (!++n)
				memcpy(d, b, sizeof(d));
			else
				printf("set %d: matching = %d\n",
				    n, matched(d, b));
	}
	return 0;
}

