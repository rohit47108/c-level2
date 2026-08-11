#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

int find_greatestSum_bruteforce(int *list, int n) {
	int max_sum = list[0];
	for (int i = 0; i < n; i++) {
		int current_sum = 0;
		for (int j = i; j < n; j++) {
			current_sum += list[j];
			if (current_sum > max_sum) {
				max_sum = current_sum;
			}
		}
	}
	return max_sum;
}


void find_greatestSum_bruteforce_ex() {
	int n;
	printf("Enter the number of elements in the array: ");
	n = getNum();
	int *list = (int *)malloc(n * sizeof(int));
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < n; i++) {
		list[i] = getNum();
	}
	int max_sum = find_greatestSum_bruteforce(list, n);
	printf("The greatest sum of a contiguous subarray is: %d\n", max_sum);
	free(list);
}

int find_greatestSum_optimized(int *list, int n) {
	int max_sum = list[0];
	int current_sum = list[0];
	for (int i = 1; i < n; i++) {
		current_sum = (list[i] > current_sum + list[i]) ? list[i] : current_sum + list[i];
		if (current_sum > max_sum) {
			max_sum = current_sum;
		}
	}
	return max_sum;
}
void find_greatestSum_optimized_ex() {
	int n;
	printf("Enter the number of elements in the array: ");
	n = getNum();
	int *list = (int *)malloc(n * sizeof(int));
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < n; i++) {
		list[i] = getNum();
	}
	int max_sum = find_greatestSum_optimized(list, n);
	printf("The greatest sum of a contiguous subarray is: %d\n", max_sum);
	free(list);
}

int find_greatestSum_optimized_expanded(int *list, int n, int *start_index, int *end_index) {
	int max_sum = list[0];
	int current_sum = list[0];
	*start_index = 0;	
	*end_index = 0;
	int temp_start = 0;
	for (int i = 1; i < n; i++) {
		if (list[i] > current_sum + list[i]) {
			current_sum = list[i];
			temp_start = i;
		} else {
			current_sum += list[i];
		}
		if (current_sum > max_sum) {
			max_sum = current_sum;
			*start_index = temp_start;
			*end_index = i;
		}
	}
	return max_sum;
}
void find_greatestSum_optimized_expanded_ex() {
	int n;
	printf("Enter the number of elements in the array: ");
	n = getNum();
	int *list = (int *)malloc(n * sizeof(int));
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < n; i++) {
		list[i] = getNum();
	}
	int start_index, end_index;
	int max_sum = find_greatestSum_optimized_expanded(list, n, &start_index, &end_index);
	printf("The greatest sum of a contiguous subarray is: %d\n", max_sum);
	printf("The subarray starts at index %d and ends at index %d\n", start_index, end_index);
	free(list);
}

char* lcs(char* p1, char* p2) {
	int m = strlen(p1);
	int n = strlen(p2);
	int** L = (int**)malloc((m + 1) * sizeof(int*));
	for (int i = 0; i <= m; i++) {
		L[i] = (int*)malloc((n + 1) * sizeof(int));
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				L[i][j] = 0;
			}
			else if (p1[i - 1] == p2[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else {
				L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
			}
		}
	}
	int index = L[m][n];
	char* lcs_str = (char*)malloc((index + 1) * sizeof(char));
	lcs_str[index] = '\0';
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (p1[i - 1] == p2[j - 1]) {
			lcs_str[index - 1] = p1[i - 1];
			i--;
			j--;
			index--;
		} else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}
	for (int k = 0; k <= m; k++) {
		free(L[k]);
	}
	free(L);
	return lcs_str;
}
void longest_common_subsequence_ex() {
	char str1[100], str2[100];
	printf("Enter first string: ");
	getString(str1, sizeof(str1));
	printf("Enter second string: ");
	getString(str2, sizeof(str2));
	char* lcs_str = lcs(str1, str2);
	printf("Longest Common Subsequence: %s\n", lcs_str);
	free(lcs_str);
}

int find_greatestSum_2D_bruteforce(int *list, int row, int col) {
	int max_sum = list[0];
	for (int i1 = 0; i1 < row; i1++) {
		for (int j1 = 0; j1 < col; j1++) {
			int current_sum = 0;
			for (int i2 = i1; i2 < row; i2++) {
				for (int j2 = j1; j2 < col; j2++) {
					current_sum += *(list + i2 * col + j2);
					if (current_sum > max_sum) {
						max_sum = current_sum;
					}
				}
			}
		}
	}
	return max_sum;
}
void find_greatestSum_2D_bruteforce_ex() {
	int row, col;
	printf("Enter the number of rows: ");
	row = getNum();
	printf("Enter the number of columns: ");
	col = getNum();
	int *list = NULL;
	if (row > 0 && col > 0) {
		list = (int *)malloc(row * col * sizeof(int));
	}
	if (list == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	printf("Enter the elements of the 2D array:\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("Element [%d][%d]: ", i, j);
			*(list + i * col + j) = getNum();
		}
	}
	int max_sum = find_greatestSum_2D_bruteforce(list, row, col);
	printf("The greatest sum of a contiguous subarray in the 2D array is: %d\n", max_sum);
	free(list);
}

void contiguoussubarraygreatestsum_main() {
	printf("Choose an exercise from contiguous sub-array with greatest sum: \n");
	printf("1 = 1D Array; Greatest Sum Subarray Identifier - Brute Force\n");
	printf("2 = 1D Array; Greatest Sum Subarray Identifier - Optimized\n");
	printf("3 = 1D Array; Greatest Sum Subarray Identifier - Optimized + Expanded\n");
	printf("4 = Longest Common Subsequence Identifier\n");
	printf("5 = 2D Array; Greatest Sum Subarray Identifier - Brute Force\n");
	int ex = getNum();
	switch (ex) {
	case 1: find_greatestSum_bruteforce_ex(); break;
	case 2: find_greatestSum_optimized_ex(); break;
	case 3: find_greatestSum_optimized_expanded_ex(); break;
	case 4: longest_common_subsequence_ex(); break;
	case 5: find_greatestSum_2D_bruteforce_ex(); break;
	}
};