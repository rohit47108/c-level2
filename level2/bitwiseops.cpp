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
	printf("9 = \n");
	printf("10 = \n");
	printf("11 = \n");
	printf("12 = \n");
	printf("13 = \n");
	printf("14 = \n");
	printf("15 = \n");
	int ex = getNum();
	switch (ex) {
	case 1: color_ex(); break;
	case 2: color_get_rgb_ex(); break;
	case 3: swap_bytes_ex(); break;
	case 4: countBits_ex(); break;
	case 5: modifierKeysCheck_ex(); break;
	case 6: create_short_ex(); break;
	case 7: bitsExplanation_ea(); break;
	case 8: break;
	case 9: break;
	case 10: break;
	case 11: break;
	case 12: break;
	case 13: break;
	case 14: break;
	case 15	: break;
	}
};