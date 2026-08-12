#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

#define MK_COLOR(r, g, b) ((long)((r) & 0xFF) | (((long)(g) & 0xFF) << 8) | (((long)(b) & 0xFF) << 16))
void color_ex() {
	ubyte r, g, b;
	printf("Enter red component (0-255): ");
	r = (ubyte)getNum();
	printf("Enter green component (0-255): ");
	g = (ubyte)getNum();
	printf("Enter blue component (0-255): ");
	b = (ubyte)getNum();
	long color = MK_COLOR(r, g, b);
	printf("The color value is: %ld\n", color);
}

#define GET_RED(color) ((ubyte)((color) & 0xFF))
#define GET_GREEN(color) ((ubyte)(((color) >> 8) & 0xFF))
#define GET_BLUE(color) ((ubyte)(((color) >> 16) & 0xFF))
void color_get_rgb_ex() {
	long color;
	printf("Enter a color value: ");
	color = getNum();
	ubyte r = GET_RED(color);
	ubyte g = GET_GREEN(color);
	ubyte b = GET_BLUE(color);
	printf("Red: %d, Green: %d, Blue: %d\n", r, g, b);
}

unsigned short swap_bytes(unsigned short i) {
	return (i << 8) | (i >> 8);
}
void swap_bytes_ex() {
	unsigned short i;
	printf("Enter a hexadecimal number (up to four digits): ");
	i = (unsigned short)getNum;
	unsigned short swapped = swap_bytes(i);
	printf("Number with bytes swapped: %04hx\n", swapped);
}

unsigned long long countBits(unsigned long long n) {
	unsigned long long count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}
void countBits_ex() {
	unsigned long long n;
	printf("Enter an unsigned long long number: ");
	n = getNum();
	unsigned long long count = countBits(n);
	printf("Number of 1 bits in %llu is: %llu\n", n, count);
}

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4
void modifierKeysCheck_ex() {
	int key_code;
	printf("Enter a key code (integer): ");
	key_code = getNum();
	if ((key_code & (1 | 2 | 4)) == 0) {
		printf("No modifier keys pressed\n");
	} else {
		printf("Modifier keys pressed\n");
	}
	printf("Explanation: The original statement didn't work because the bitwise AND operator (&) has lower precedence than the equality operator (==). It should be written as (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0\n");
}

unsigned short create_short(unsigned char high_byte, unsigned char low_byte) {
	return ((unsigned short)high_byte << 8) | (unsigned short)low_byte;
}
void create_short_ex() {
	unsigned char high_byte, low_byte;
	printf("Enter high byte (0-255): ");
	high_byte = (unsigned char)getNum();
	printf("Enter low byte (0-255): ");
	low_byte = (unsigned char)getNum();
	unsigned short result = create_short(high_byte, low_byte);
	printf("The combined unsigned short is: %hu\n", result);
	printf("Explanation: The original function didn't work because the addition operator (+) has higher precedence than the bitwise shift operator (<<). It should be written as ((unsigned short)high_byte << 8) | (unsigned short)low_byte to correctly combine the two bytes.\n");
}

void bitsExplanation_ea() {
	unsigned int n;
	printf("Enter an unsigned int number: ");
	n = getNum();
	printf("Original number: %u\n", n);
	n &= n - 1;
	printf("After executing n &= n - 1; the number becomes: %u\n", n);
	printf("Explanation: The statement n &= n - 1; clears the least significant set bit (1) in n. If executed multiple times, it will continue to clear the least significant set bit until n becomes 0.\n");
}

unsigned int extractBits_func(unsigned int i, int m, int n) {
	return (i >> (m + 1 - n)) & ~(~0 << n);
}
void extractBits_ex() {
	printf("Enter three integers: \n");
	unsigned int i = getNum();
	int m = getNum();
	int n = getNum();
	extractBits_func(i, m, n);
}

unsigned int lowestBitNumber(unsigned int n) {
	return n & (~n + 1);
}
void printBinary(unsigned int n) {
	if (n == 0) {
		printf("0");
		return;
	}
	unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
	while ((n & mask) == 0) {
		mask >>= 1;
	}
	while (mask != 0) {
		printf("%u", (n & mask) != 0);
		mask >>= 1;
	}
}
void lowestBitNumber_ex() {
	unsigned int values[] = {
		0b10010101,
		0b10010100,
		0b10010000
	};
	int count = sizeof(values) / sizeof(values[0]);
	for (int i = 0; i < count; i++) {
		unsigned int result = lowestBitNumber(values[i]);
		printf("Input: %u (binary ", values[i]);
		printBinary(values[i]);
		printf(")\n");
		printf("Output: %u (binary ", result);
		printBinary(result);
		printf(")\n\n");
	}
}

unsigned int toggleBit(unsigned int num, int n) {
	return num ^ (1u << n);
}
void toggleBit_ex() {
	unsigned int num;
	int n;
	printf("Enter a number: ");
	num = (unsigned int)getNum();
	printf("Enter bit position to toggle (0-31): ");
	n = getNum();

	if (n < 0 || n >= 32) {
		printf("Error: Bit position must be between 0 and 31\n");
		return;
	}
	unsigned int result = toggleBit(num, n);
	printf("\nOriginal number in base 10: %u\n", num);
	printf("Original number in base 2:  ");
	printBinary(num);
	printf("\n\nToggled bit at position %d\n\n", n);
	printf("Result in base 10: %u\n", result);
	printf("Result in base 2:  ");
	printBinary(result);
	printf("\n");
}

int bitwiseAdd(int a, int b) {
	while (b != 0) {
		int carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}
	return a;
}
void bitwiseAdd_ex() {
	int a, b;
	printf("Enter first number: ");
	a = getNum();
	printf("Enter second number: ");
	b = getNum();
	int result = bitwiseAdd(a, b);
	printf("Result of %d + %d using bitwise operations: %d\n", a, b, result);
}

int bitwiseSubtract(int a, int b) {
	return bitwiseAdd(a, bitwiseAdd(~b, 1));
}
void bitwiseSubtract_ex() {
	int a, b;
	printf("Enter first number: ");
	a = getNum();
	printf("Enter second number: ");
	b = getNum();
	int result = bitwiseSubtract(a, b);
	printf("Result of %d - %d using bitwise operations: %d\n", a, b, result);
}

int bitwiseMultiply(int a, int b) {
	int result = 0;
	int multiplier = b;
	while (multiplier != 0) {
		if (multiplier & 1) {
			result = bitwiseAdd(result, a);
		}
		a = a << 1;
		multiplier = multiplier >> 1;
	}
	return result;
}
void bitwiseMultiply_ex() {
	int a, b;
	printf("Enter first number: ");
	a = getNum();
	printf("Enter second number: ");
	b = getNum();
	int result = bitwiseMultiply(a, b);
	printf("Result of %d * %d using bitwise operations: %d\n", a, b, result);
}

int bitwiseDivide(int a, int b) {
	if (b == 0) {
		printf("Error: Division by zero\n");
		return 0;
	}
	int result = 0;
	int dividend = a;
	while (dividend >= b) {
		int quotient = 0;
		while ((b << (quotient + 1)) <= dividend) {
			quotient = quotient + 1;
		}
		result = bitwiseAdd(result, 1 << quotient);
		dividend = bitwiseSubtract(dividend, b << quotient);
	}
	return result;
}
void bitwiseDivide_ex() {
	int a, b;
	printf("Enter dividend: ");
	a = getNum();
	printf("Enter divisor: ");
	b = getNum();
	int result = bitwiseDivide(a, b);
	printf("Result of %d / %d using bitwise operations: %d\n", a, b, result);
}

int bitwiseModulo(int a, int b) {
	if (b == 0) {
		printf("Error: Modulo by zero\n");
		return 0;
	}
	return bitwiseSubtract(a, bitwiseMultiply(bitwiseDivide(a, b), b));
}
void bitwiseModulo_ex() {
	int a, b;
	printf("Enter dividend: ");
	a = getNum();
	printf("Enter divisor: ");
	b = getNum();
	int result = bitwiseModulo(a, b);
	printf("Result of %d %% %d using bitwise operations: %d\n", a, b, result);
}

unsigned int bitOff(unsigned int num) {
	return num & (num - 1);
}
void bitOff_ex() {
	unsigned int num;
	printf("Enter a number: ");
	num = (unsigned int)getNum();

	if (num == 0) {
		printf("Error: Cannot turn off lowest set bit in 0\n");
		return;
	}
	unsigned int result = bitOff(num);
	printf("\nOriginal number in base 10: %u\n", num);
	printf("Original number in base 2:  ");
	printBinary(num);
	printf("\n\nTurning off the lowest order set bit:\n\n");
	printf("Result in base 10: %u\n", result);
	printf("Result in base 2:  ");
	printBinary(result);
	printf("\n");
	printf("\nExplanation: The expression (num & (num - 1)) turns off the lowest order set bit.\n");
	printf("When you subtract 1 from a number, all bits after the lowest set bit flip,\n");
	printf("and the lowest set bit becomes 0. ANDing with the original clears that bit.\n");
}


void bitwiseops_main() {
	printf("Choose an exercise from bitwise ops: \n");
	printf("1 = Color Exercise\n");
	printf("2 = Get RGB Components\n");
	printf("3 = Swap Bytes\n");
	printf("4 = Count Bits\n");
	printf("5 = Modifier Keys Check\n");
	printf("6 = Create Short\n");
	printf("7 = Bit Exercise Error Analysis\n");
	printf("8 = Refunctioning\n");
	printf("9 = Print Binary\n");
	printf("10 = Toggle Bit N\n");
	printf("11 = Turn Off the Lowest Order Set Bit \n");
	printf("12 = +\n");
	printf("13 = -\n");
	printf("14 = *\n");
	printf("15 = /\n");
	printf("16 = %%\n");
	int ex = getNum();
	switch (ex) {
	case 1: color_ex(); break;
	case 2: color_get_rgb_ex(); break;
	case 3: swap_bytes_ex(); break;
	case 4: countBits_ex(); break;
	case 5: modifierKeysCheck_ex(); break;
	case 6: create_short_ex(); break;
	case 7: bitsExplanation_ea(); break;
	case 8: extractBits_ex(); break;
	case 9: lowestBitNumber_ex(); break;
	case 10: toggleBit_ex(); break;
	case 11: bitOff_ex(); break;
	case 12: bitwiseAdd_ex(); break;
	case 13: bitwiseSubtract_ex(); break;
	case 14: bitwiseMultiply_ex(); break;
	case 15: bitwiseDivide_ex(); break;
	case 16: bitwiseModulo_ex(); break;
	}
};