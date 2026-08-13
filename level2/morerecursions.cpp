#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

int findmin(int* list, int n) {
	if (n == 1) {
		return list[0];
	}
	int minOfRest = findmin(list, n - 1);
	return (list[n - 1] < minOfRest) ? list[n - 1] : minOfRest;
}
void findmin_ex() {
	int size;
	printf("Enter the size of the array: ");
	size = getNum();
	if (size <= 0) {
		printf("Error: Array size must be greater than 0\n");
		return;
	}
	int* list = (int*)malloc(size * sizeof(int));
	if (list == NULL) {
		printf("Error: Memory allocation failed\n");
		return;
	}
	printf("Enter %d elements:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Element %d: ", i + 1);
		list[i] = getNum();
	}
	int minimum = findmin(list, size);
	printf("\nThe minimum element in the array is: %d\n", minimum);
	free(list);
}

int findsum(int* list, int n) {
	if (n == 0) {
		return 0;
	}
	return findsum(list, n - 1) + list[n - 1];
}
void findsum_ex() {
	int size;
	printf("Enter the size of the array: ");
	size = getNum();
	if (size <= 0) {
		printf("Error: Array size must be greater than 0\n");
		return;
	}
	int* list = (int*)malloc(size * sizeof(int));
	if (list == NULL) {
		printf("Error: Memory allocation failed\n");
		return;
	}
	printf("Enter %d elements:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Element %d: ", i + 1);
		list[i] = getNum();
	}
	int sum = findsum(list, size);
	printf("\nThe sum of all elements in the array is: %d\n", sum);
	free(list);
}

bool ispalindrome1(char* start, char* end) {
	if (start >= end) {
		return true;
	}
	if (*start != *end) {
		return false;
	}
	return ispalindrome1(start + 1, end - 1);
}
bool ispalindrome(char* str) {
	if (str == NULL) {
		return false;
	}
	int len = strlen(str);
	return ispalindrome1(str, str + len - 1);
}
void ispalindrome_ex() {
	char str[256];
	printf("Enter a string to check if it's a palindrome: ");
	fgets(str, sizeof(str), stdin);
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	bool result = ispalindrome(str);
	printf("The string \"%s\" is ", str);
	if (result) {
		printf("a palindrome.\n");
	} 
	else {
		printf("not a palindrome.\n");
	}
}

void morerecursions_main() {
	printf("Choose an exercise from more recursions: \n");
	printf("1 = Smallest Value in an Array Recursive Function\n");
	printf("2 = Sum of All Values in an Array Recursive Function\n");
	printf("3 = Palindrome Identifier; Array Recursive Function\n");
	printf("4 = Binary Printer; Different Types Recursive Functions\n");
	printf("5 = Int to Hex or Binary Recursive Function\n");
	printf("6 = String Copy Reversal Recursive Function\n");
	printf("7 = Fibonacci Recursive Function; Dynamic Programming\n");
	printf("8 = Nesting Evaluator Recursive Function\n");
	int ex = getNum();
	switch (ex) {
	case 1: findmin_ex(); break;
	case 2: findsum_ex(); break;
	case 3: ispalindrome_ex(); break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: break;
	case 8: break;
	}
};
