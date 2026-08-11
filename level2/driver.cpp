#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

int main() {
	printf("Choose a unit (1 - Recursions, 2 - Arrays, 3 - Contiguous Sub-Array with Greatest Sum, 4 - Pointers, "
		"5 - References, 6 - Error Checking, 7 - String Manipulation, 8 - Vectors, 9 - Bitwise Operations, 10 - More Recursions, "
		"11 - Preprocessor, 12 - Sort and Search Algorithms, or 13 - Introduction to File I/O): ");
	int unit = getNum();
	switch (unit) {
		case 1: recursions_main(); break;
		case 2: arrays_main(); break;
		case 3: contiguoussubarraygreatestsum_main(); break;
		case 4: pointers_main(); break;
		case 5: references_main(); break;
		case 6: errorchecking_main(); break;
		case 7: stringmanipulation_main(); break;
		case 8: vectors_main(); break;
		case 9: bitwiseops_main(); break;
		case 10: morerecursions_main(); break;
		case 11: preprocessor_main(); break;
		case 12: sortsearch_main(); break;
		case 13: fileIO_main(); break;
	}
	return 0;
}