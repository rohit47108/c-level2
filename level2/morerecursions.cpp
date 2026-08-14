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

void showBinary_helper(unsigned long long num, int bits, int currentBit) {
	if (currentBit < 0) {
		return;
	}
	printf("%llu", (num >> currentBit) & 1);
	showBinary_helper(num, bits, currentBit - 1);
}

void showBinary(char number) {
	unsigned char unum = (unsigned char)number;
	printf("Enter a char type number: %d\n", number);
	printf("Hex: %02hhx\n", unum);
	printf("Binary: ");
	showBinary_helper((unsigned long long)unum, sizeof(char), sizeof(char) * 8 - 1);
	printf("\n");
}
void showBinary(short number) {
	unsigned short unum = (unsigned short)number;
	printf("Enter a short type number: %d\n", number);
	printf("Hex: %04hx\n", unum);
	printf("Binary: ");
	showBinary_helper((unsigned long long)unum, sizeof(short), sizeof(short) * 8 - 1);
	printf("\n");
}
void showBinary(int number) {
	unsigned int unum = (unsigned int)number;
	printf("Enter an int type number: %d\n", number);
	printf("Hex: %08x\n", unum);
	printf("Binary: ");
	showBinary_helper((unsigned long long)unum, sizeof(int), sizeof(int) * 8 - 1);
	printf("\n");
}
void showBinary_ex() {
	int choice;
	printf("Choose a type to convert to binary:\n");
	printf("1 = char\n");
	printf("2 = short\n");
	printf("3 = int\n");
	choice = getNum();
	switch (choice) {
	case 1: {
		char num;
		printf("Enter a char type number: ");
		num = (char)getNum();
		showBinary(num);
		break;
	}
	case 2: {
		short num;
		printf("Enter a short type number: ");
		num = (short)getNum();
		showBinary(num);
		break;
	}
	case 3: {
		int num;
		printf("Enter an int type number: ");
		num = getNum();
		showBinary(num);
		break;
	}
	default:
		printf("Invalid choice\n");
	}
}

void convertToHex_helper(unsigned int num, int byteIndex) {
	if (byteIndex < 0) {
		return;
	}
	unsigned char byte = (num >> (byteIndex * 8)) & 0xFF;
	printf("%02x", byte);
	if (byteIndex > 0) {
		printf(" ");
	}
	convertToHex_helper(num, byteIndex - 1);
}
void convertToBinary_helper(unsigned int num, int bitIndex, int count) {
	if (bitIndex < 0) {
		return;
	}
	printf("%u", (num >> bitIndex) & 1);
	if ((bitIndex % 4 == 0) && (bitIndex > 0)) {
		printf(" ");
	}
	convertToBinary_helper(num, bitIndex - 1, count);
}
void convertNumber_ex() {
	unsigned int num;
	int choice;
	printf("Enter a base-10 number: ");
	num = (unsigned int)getNum();
	printf("Choose conversion format:\n");
	printf("1 = Hexadecimal\n");
	printf("2 = Binary\n");
	printf("3 = Both Hex and Binary\n");
	choice = getNum();
	switch (choice) {
	case 1:
		printf("hex: ");
		convertToHex_helper(num, 3);
		printf("\n");
		break;
	case 2:
		printf("binary: ");
		convertToBinary_helper(num, 31, 0);
		printf("\n");
		break;
	case 3:
		printf("hex: ");
		convertToHex_helper(num, 3);
		printf("\n");
		printf("binary: ");
		convertToBinary_helper(num, 31, 0);
		printf("\n");
		break;
	default:
		printf("Invalid choice\n");
	}
}

void reverseHelper(char* source, char* target, int index) {
	if (source[index] == '\0') {
		target[index] = '\0';
		return;
	}
	reverseHelper(source, target, index + 1);
	int len = index;
	while (source[len] != '\0') {
		len++;
	}
	target[len - index - 1] = source[index];
}
void reverse(char* sourceString) {
	if (sourceString == NULL) {
		return;
	}
	int len = 0;
	while (sourceString[len] != '\0') {
		len++;
	}
	char* temp = (char*)malloc((len + 1) * sizeof(char));
	if (temp == NULL) {
		printf("Error: Memory allocation failed\n");
		return;
	}
	reverseHelper(sourceString, temp, 0);
	for (int i = 0; i <= len; i++) {
		sourceString[i] = temp[i];
	}
	free(temp);
}
void reverse_ex() {
	char sourceString[256];
	printf("Enter a string to reverse: ");
	fgets(sourceString, sizeof(sourceString), stdin);
	int len = 0;
	while (sourceString[len] != '\0') {
		len++;
	}
	if (len > 0 && sourceString[len - 1] == '\n') {
		sourceString[len - 1] = '\0';
	}
	printf("Original string: %s\n", sourceString);
	reverse(sourceString);
	printf("Reversed string: %s\n", sourceString);
}

unsigned long long fibonacci(int n) {
	static unsigned long long array[100] = { 0 };
	static bool initialized = false;
	if (!initialized) {
		array[0] = 0;
		array[1] = 1;
		initialized = true;
	}
	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (array[n] != 0) {
		return array[n];
	}
	array[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return array[n];
}
void fibonacci_ex() {
	int n;
	printf("Enter a number to find its Fibonacci value (0-92): ");
	n = getNum();
	if (n < 0 || n > 92) {
		printf("Error: Please enter a number between 0 and 92\n");
		return;
	}
	unsigned long long result = fibonacci(n);
	printf("Fibonacci(%d) = %llu\n", n, result);
}



bool bal(char* p) {
	char str = '(';
	char str1 = ')';
	char str2 = '{';
	char str3 = '}';
	int j = 0, l = 0, n = 0, q = 0;
	for (int i = 0; i < sizeof(p); i++) {
		if (p[i] == str) {
			p[i] = '0';
			j++;
		}
		else if (p[i] == str1) {
			p[i] = '0';
			l++;
		}
		else if (p[i] == str2) {
			p[i] == '0';
			n++;
		}
		else if (p[i] == str3) {
			p[i] = '0';
			q++;
		}
	}
	if (j == l && n == q) {
		return true;
	}
	else {
		return false;
	}
}
void balance_ex() {
	char phrase[50];
	printf("Enter phrase: ");
	getString(phrase, sizeof(phrase));
	if (bal(phrase) == true) {
		printf("Result: Balanced\n");
	}
	else {
		printf("Result: Not balanced\n");
	}
	printf("%s", phrase);
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
	case 4: showBinary_ex(); break;
	case 5: convertNumber_ex(); break;
	case 6: reverse_ex(); break;
	case 7: fibonacci_ex(); break;
	case 8: balance_ex(); break;
	}
};
