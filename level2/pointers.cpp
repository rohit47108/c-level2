#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

void pointerAlias_ex() {
	printf("If i is a variable and p points to i, which of the following expressions are aliases for i?\n");
	printf("Options:\n(a) *p\n(b) &p\n(c) *&p\n(d) &*p\n(e) *i\n(f) &i\n(g) *&i\n(h) &*i\nAnswer: Options a and g");
}

void pointerIntegerLegality_ex() {
	printf("If i is an int variable and p and q are pointers to int, which of the following assignments are legal?\n");
	printf("Options:\n(a) p = i;\n(b) *p = &i;\n(c) &p = q;\n(d) p = &q;\n(e) p = *&q;\n(f) p = q;;\n(g) p = *q;\n(h) *p = q;\n(i) *p = *q;\nAnswer: Options e, f, & i");
}

void arrayAveragePointer_ea() {
	printf("Given Code:\n");
	printf("double avg_sum(int *a, int n) {\n");
	printf("    double sum;\n");
	printf("    for (int i = 0; i < n; i++) {\n");
	printf("        sum += a[i];\n");
	printf("    }\n");
	printf("    return sum / n;\n");
	printf("}\n");
	printf("Errors:\n");
	printf("1. var sum is used before being initialized. this makes things that are undefined.\n");
	printf("2. pointer arithmetic would be better.\n");
	printf("Corrected:\n");
	printf("double avg_sum(int *a, int n) {\n");
	printf("    double sum = 0.0;\n");
	printf("    for (int i = 0; i < n; i++) {\n");
	printf("        sum += *(a + i);\n");
	printf("    }\n");
	printf("    return sum / n;\n");
	printf("}\n");
}

void pointerSwapFunction_ex() {
	int a = 5, b = 10;
	int *p = &a, *q = &b;
	printf("Before swap: a = %d, b = %d\n", a, b);
	int c = *p;
	*p = *q;
	*q = c;
	printf("After swap: a = %d, b = %d\n", a, b);
}

void pointerTimeStorageFunction_ex() {
	printf("Enter an amount of seconds: ");
	long total_sec = getNum();
	int hr, min, sec;
	int* p_hr = &hr;
	int* p_min = &min;
	int* p_sec = &sec;
	*p_hr = total_sec / 3600;
	*p_min = (total_sec % 3600) / 60;
	*p_sec = total_sec % 60;
	printf("%ld seconds = %d hour(s), %d minute(s), %d second(s)\n", total_sec, hr, min, sec);
}

void arrayLargestAndLargeStorageFunction_ex() {
	printf("Enter the number of elements in the array: ");
	int n = getNum();
	if (n < 2) {
		printf("Array must have at least two elements.\n");
		return;
	}
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	printf("Enter %d integers:\n", n);
	for (int i = 0; i < n; i++) {
		arr[i] = getNum();
	}
	int largest = arr[0], second = arr[0];
	int* p_largest = &largest;
	int* p_second = &second;
	for (int i = 1; i < n; i++) {
		if (arr[i] > *p_largest) {
			*p_second = *p_largest;
			*p_largest = arr[i];
		}
		else if (arr[i] > *p_second && arr[i] != *p_largest) {
			*p_second = arr[i];
		}
	}
	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nLargest: %d\nSecond Largest: %d\n", *p_largest, *p_second);
	free(arr);
}

void dayInMonthInYearPointerFunction_ex() {
	printf("Enter day: ");
	int day = getNum();
	printf("Enter month (1-12): ");
	int month = getNum();
	printf("Enter year: ");
	int year = getNum();
	int* p_day = &day;
	int* p_month = &month;
	int* p_year = &year;
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((*p_year % 4 == 0 && *p_year % 100 != 0) || (*p_year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (*p_month < 1 || *p_month > 12 || *p_day < 1 || *p_day > days_in_month[*p_month - 1]) {
		printf("Invalid date.\n");
		return;
	}
	int day_of_year = *p_day;
	for (int i = 0; i < *p_month - 1; i++) {
		day_of_year += *(days_in_month + i);
	}
	printf("Date: %02d/%02d/%d is day number %d of the year.\n", *p_day, *p_month, *p_year, day_of_year);
}

int* find_largest(int a[], int n) {
	if (n <= 0) return NULL;
	int* largest = a;
	for (int i = 1; i < n; i++) {
		if (*(a + i) > *largest) {
			largest = a + i;
		}
	}
	return largest;
}
void arrayLargestElementPointerFunction_ex() {
	int n;
	printf("Enter the number of elements in the array: ");
	n = getNum();
	if (n <= 0) {
		printf("Array size must be positive.\n");
		return;
	}
	int* arr = (int*)malloc(n * sizeof(int));
	if (!arr) {
		printf("Memory allocation didn't work.\n");
		return;
	}
	printf("Enter %d integers:\n", n);
	for (int i = 0; i < n; i++) {
		arr[i] = getNum();
	}
	int* p_largest = find_largest(arr, n);
	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	if (p_largest) {
		printf("\nLargest element: %d\n", *p_largest);
	}
	else {
		printf("\nNo largest element found.\n");
	}
	free(arr);
}

void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones) {
	*twenties = dollars / 20;
	dollars %= 20;
	*tens = dollars / 10;
	dollars %= 10;
	*fives = dollars / 5;
	dollars %= 5;
	*ones = dollars;
}
void billAmtFunc_prjct(int amt) {
	int twenties, tens, fives, ones;
	int* p_twenty = &twenties;
	int* p_ten = &tens;
	int* p_five = &fives;
	int* p_one = &ones;
	pay_amount(amt, p_twenty, p_ten, p_five, p_one);
	printf("$20 bills: %d\n", *p_twenty);
	printf("$10 bills: %d\n", *p_ten);
	printf("$5 bills: %d\n", *p_five);
	printf("$1 bills: %d\n", *p_one);
}

void expressions_ea() {
	printf("given code:\n");
	printf("1. char foo[] = 'OJoy to the World!!';\n");
	printf("2. char *p = \"Santa Claus is one cool dude.\";\n");
	printf("3. foo[ sizeof(p) ] == '!'\n");
	printf("4. foo[ sizeof(foo) ] == '!'\n");
	printf("5. const char **dp = &p;\n");
	printf("6. (*dp)[1] == 'a';\n");
	printf("7. *dp[1] == 'a';\n");
	printf("8. *((*dp)+1) == 'a';\n\n");
	printf("answer:\n");
	printf("1. wrong: Uses single quotes for a string. Should use double quotes.\n");
	printf("   Correct: char foo[] = \"OJoy to the World!!\";\n");
	printf("2. Valid string pointer declaration.\n");
	printf("3. wrong: sizeof(p) gives size of pointer, not length of string. Index may be out of bounds.\n");
	printf("   Use strlen(p)\n");
	printf("4. wrong: sizeof(foo) gives total size of array, not valid index. Index may be out of bounds.\n");
	printf("   Use strlen(foo).\n");
	printf("5. valid declaration of pointer to pointer.\n");
	printf("6. (*dp)[1] goes to second character of string pointed to by dp.\n");
	printf("7. wrong: *dp[1] is invalid: dp[1] is not defined.\n");
	printf("   Use (*dp)[1] or *((*dp)+1)\n");
	printf("8. *((*dp)+1) is a valid way to access second character.\n");
}

void swapFunction_ea() {
	printf("given code:\n");
	printf("int x = 10;\n"); 
	printf("int y = 20;\n");
	printf("const int *p1 = &x;\n");
	printf("*p1 = y; - wrong: cannot assign to a const int\n");
	printf("p1 = &x; - right: changing pointer target is allowed\n");
	printf("\nerrors and problems\n");
	printf("1. `const int *p1` means you cannot change the value pointed to by p1.\n");
	printf("2. `*p1 = y;` is illegal because it tries to modify a const value.\n");
	printf("3. `p1 = &x;` is legal because youre just redirecting the pointer.\n");
	printf("\ncorrected code:\n");
	printf("int x = 10;\n");
	printf("int y = 20;\n");
	printf("const int *p1 = &x;\n");
	printf("// *p1 = y; -  removed or commented out\n");
	printf("p1 = &y;  - Now points to another const int\n");
}

void constPointerTarget_ea() {
	printf("given code:\n");
	printf("int x = 10;\n");
	printf("int y = 20;\n");
	printf("int * const p2 = &y;\n");
	printf("p2 = &x; - wrong: cannot change a constant pointer\n");
	printf("*p2 = 50; -right: can modify the value pointed to\n");
	printf("\errors and problems:\n");
	printf("1. `int * const p2` means the pointer itself is constant, but the value it points to can change\n");
	printf("2. `p2 = &x;` is illegal because it tries to reassign a constant pointer.\n");
	printf("3. `*p2 = 50;` is legal because it changes the value at the pointed location.\n");
	printf("\ncorrected code:\n");
	printf("int x = 10;\n");
	printf("int y = 20;\n");
	printf("int * const p2 = &y;\n");
	printf("*p2 = 50; - changes y to 50\n");
	printf("printf(\"*p2 = %%d; y = %%d\\n\", *p2, y);\n");
}

void illegalPrintStatement_ea() {
	printf("Given the following declarations, figure out which one of the printf statements is illegal. Why?\n");
	printf("char str[100] = 'abc;\nconst char* x = 'abc';\nchar* x2 = str;\n");
	printf("\nprintf('%%s/n', ++x)\nprintf('%%s/n', ++str);\nprintf('%%s', ++x2);\n");
	printf("printf('%%s/n', ++x); is illegal because x is a constant pointer and this print statement is attempting to change the value of it which can't happen.");
}

void integerSizeOf_ea() {
	printf("Figure this out without using your computer first. Test them out using sizeof:\n");
	printf("given: int x[10][2];\n");
	printf("\nIs the following legal or not:\n");
	printf("p2 = x[2];\n");
	printf("\nAnswer:\n");
	printf("1. `x[2]` refers to the third row of the array, which is `int[2]`.\n");
	printf("2. In this, `x[2]` goes down to a pointer to its first element: type `int*`.\n");
	printf("3. So the assignment `p2 = x[2];` is legal IF `p2` is declared as `int*`.\n");
	printf("\nCorrected:\n");
	printf("int *p2;\n");
	printf("p2 = x[2]; - this is legal: p2 now points to x[2][0]\n");
	printf("\nyou can now access elements like:\n");
	printf("p2[0] which is the same as x[2][0]\n");
	printf("p2[1] which is the same as x[2][1]\n");
}

void codeSnipperCapacityLegality_ex() {
	printf("Declaration 1:\n");
	printf("int* p1[10];\n");
	printf("- p1 is an array of 10 pointers to int.\n");
	printf("- cap is 10 pointer slots and also all of them can point to an int\n");
	printf("\nDeclaration 2:\n");
	printf("int(*p2)[10];\n");
	printf("- p2 is a pointer to an array of 10 ints.\n");
	printf("- cap is 10 integers.\n");
}

#define MAX_LEN 100
void reverseMessage_array() {
	char message[MAX_LEN];
	int i = 0, ch;
	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && i < MAX_LEN)
		message[i++] = ch;
	printf("Reversal is: ");
	while (i > 0)
		putchar(message[--i]);
	printf("\n");
}
#define MAX_LEN 100
void reverseMessage_pointer() {
	char message[MAX_LEN];
	char* p = message;
	int ch;
	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && p < message + MAX_LEN)
		*p++ = ch;
	printf("Reversal is: ");
	while (p > message)
		putchar(*--p);
	printf("\n");
}

void codeSnippetSizeOf_ea() {
	printf("given code:\n");
	printf("int doP2(const int *a) {\n");
	printf("    int n = sizeof(a) / sizeof(a[0]);\n");
	printf("    *(a + 2) = 99;\n");
	printf("    return (a[n]);\n");
	printf("}\n\n");
	printf("errors and problems:\n");
	printf("1. `sizeof(a) / sizeof(a[0])` is wrong.\n");
	printf("   -`a` is a pointer not an array.\n");
	printf("   - `sizeof(a)` gives size of pointer not array length.\n");
	printf("   - So `n` will be wrong because they have to pass the array size separately.\n\n");
	printf("2. `*(a + 2) = 99;` is illegal.\n");
	printf("   - `a` is declared as `const int *`, meaning you cannot change the value it points to.\n");
	printf("   -to fix this remove `const` if change is wanted.\n\n");
	printf("3. `return a[n];` is unsafe.\n");
	printf("   - since `n` is wrong this may go to out-of-bounds memory.\n");
	printf("   - they should return a valid index like the last element: `a[size - 1]`.\n\n");
	printf("corrected code:\n");
	printf("int doP2(int *a, int size) {\n");
	printf("    if (size < 3) return -1;\n");
	printf("    a[2] = 99;\n");
	printf("    return a[size - 1];\n");
	printf("}\n");
}

int toMinutes(myTime t) {
	return t.hour * 60 + t.minute;
}
void addSchedule(myTime schedules[], int* count, int hour, int minute) {
	schedules[*count].hour = hour;
	schedules[*count].minute = minute;
	(*count)++;
}
void setMyDesiredDeparture(myTime* desired, int hour, int minute) {
	desired->hour = hour;
	desired->minute = minute;
}
myTime findBestSchedule(myTime schedules[], int count, myTime desired) {
	if (count == 0) {
		myTime none = { -1, -1 };
		return none;
	}
	int desiredMin = toMinutes(desired);
	myTime best = schedules[0];
	int bestDiff = abs(toMinutes(best) - desiredMin);
	for (int i = 1; i < count; i++) {
		int diff = abs(toMinutes(schedules[i]) - desiredMin);
		if (diff < bestDiff) {
			best = schedules[i];
			bestDiff = diff;
		}
	}
	return best;
}
void findClosestFlight_prjct() {
	myTime schedules[50];
	int count = 0;
	myTime desired;
	printf("How many schedules to enter? ");
	int numFlights = getNum();
	if (numFlights < 1) {
		printf("No schedules entered.\n");
		return;
	}
	for (int i = 0; i < numFlights; i++) {
		printf("\nSchedule #%d\n", i + 1);
		printf("Hour (0-23): ");
		int h = getNum();
		printf("Minute (0-59): ");
		int m = getNum();
		addSchedule(schedules, &count, h, m);
	}
	printf("\nEnter desired departure hour: ");
	int dh = getNum();
	printf("Enter desired departure minute: ");
	int dm = getNum();
	setMyDesiredDeparture(&desired, dh, dm);
	myTime best = findBestSchedule(schedules, count, desired);
	if (best.hour == -1) {
		printf("No schedules available.\n");
	}
	else {
		printf("\nClosest schedule: %02d:%02d\n", best.hour, best.minute);
	}
}

void swapPoints(POINT* p1, POINT* p2) {
	POINT temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void swapPoints_func() {
	POINT a = { 1.0, 2.0, 3.0 };
	POINT b = { 4.5, 5.0, 6.0 };
	printf("Before swap:\n");
	printf("A = (%.1f, %.1f, %.1f)\n", a.x, a.y, a.z);
	printf("B = (%.1f, %.1f, %.1f)\n", b.x, b.y, b.z);
	swapPoints(&a, &b);
	printf("After swap:\n");
	printf("A = (%.1f, %.1f, %.1f)\n", a.x, a.y, a.z);
	printf("B = (%.1f, %.1f, %.1f)\n", b.x, b.y, b.z);
}

void showList_ex() {
	int list[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }, n = sizeof(list) / sizeof(list[0]), i;
	for (i = 0; i < n; i++) {
		printf("list + %d: %p contains %d\n", i, (list + i), *(list + i));
	}
}

void reverseRecursiveList_func(int* list, int nElements) {
	if (nElements == 0) {
		return;
	}
	printf("%d ", list[nElements - 1]);
	reverseRecursiveList_func(list, nElements - 1);
}
void reverseRecursiveList_ex() {
	printf("Enter number of elements: ");
	int n = getNum();
	if (n <= 0) {
		printf("No elements.\n");
		return;
	}
	int arr[100];
	for (int i = 0; i < n; i++) {
		printf("Enter integer %d: ", i + 1);
		arr[i] = getNum();
	}
	printf("Array in reverse: ");
	reverseRecursiveList_func(arr, n);
	printf("\n");
}

void showChars_func(char* p) {
	int index = 1;
	while (*p != '\0' && *p != '0') {
		printf("char %d : %c : %d\n", index, *p, (unsigned char)*p);
		p++;
		index++;
	}
	printf("char %d : %c : %d\n", index, *p, (unsigned char)*p);
}
void showChars_ex() {
	char input[100];
	printf("Enter a string (end with 0 or null terminator): ");
	getString(input, sizeof(input));
	showChars_func(input);
}

void show2D_func(int* p, int rows, int cols) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			printf("%d\t", *(p + r * cols + c));
		}
		printf("\n");
	}
}
void show2D_ex() {
	printf("Enter rows: ");
	int r = getNum();

	printf("Enter columns: ");
	int c = getNum();
	if (r <= 0 || c <= 0 || r > 10 || c > 10) {
		printf("Invalid size.\n");
		return;
	}
	int arr[10][10];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("Enter element [%d][%d]: ", i, j);
			arr[i][j] = getNum();
		}
	}
	printf("2D array output:\n");
	show2D_func((int*)arr, r, c);
}

#define R1 2
#define C1 3
#define R2 3
#define C2 4
void dotProduct_array() {
	int M1[R1][C1] = {
		{5, 3, 1},
		{2, 1, 2}
	};
	int M2[R2][C2] = { {1, 2, 50, 20}, {11, 2, 10, 8}, {7, 9, 5, 40} };
	int M3[R1][C2] = { 0 };
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			for (int k = 0; k < C1; k++) {
				M3[i][j] += M1[i][k] * M2[k][j];
			}
		}
	}
	printf("Result (Array syntax):\n");
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			printf("%4d", M3[i][j]);
		}
		printf("\n");
	}
}

void dotProduct_pointer() {
	int M1[R1][C1] = {
		{5, 3, 1},
		{2, 1, 2}
	};
	int M2[R2][C2] = {
		{1,  2,  50, 20},
		{11, 2,  10,  8},
		{7,  9,   5, 40}
	};
	int M3[R1][C2] = { 0 };

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			for (int k = 0; k < C1; k++) {
				*(*(M3 + i) + j) += *(*(M1 + i) + k) * *(*(M2 + k) + j);
			}
		}
	}
	printf("Result (Pointer syntax):\n");
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			printf("%4d", *(*(M3 + i) + j));
		}
		printf("\n");
	}
}

void pointers_main() {
	printf("Choose an exercise from pointers: \n");
	printf("1-8 (textbook exercises) 9 (ch 11 textbook project 1)"
		"10-16 (packet exercises) 17-18 (ch 12 textbook project 1)"
		"19 (ch 11 textbook project 2) 20-25 (packet exercises)\n");
	printf("1 = Pointer Alias Problem\n");
	printf("2 = Pointer Integer Legality\n");
	printf("3 = Array Average Pointer Error Analysis\n");
	printf("4 = Pointer Swap Function\n");
	printf("5 = Pointer Time Storage Function\n");
	printf("6 = Array Largest and Large Storage Function\n");
	printf("7 = Day in a Month in a Year Pointer Function\n");
	printf("8 = Array Largest Element Pointer Function\n");	
	printf("9 = Bill Amount Function Project Using Pointers\n");
	printf("10 = Expressions Error Analysis\n");
	printf("11 = Swap Function Error Analysis\n");
	printf("12 = Constant Pointer Target Error Analysis\n");
	printf("13 = Illegal Print Statement Error Analysis\n");
	printf("14 = Integer SizeOf Error Analysis\n");
	printf("15 = Code Snippet Capacity Legality\n");
	printf("16 = Code Snippet SizeOf Error Analysis\n");
	printf("17 = Sentence Reversal Function Project Using Array\n");
	printf("18 = Sentence Reversal Function Project Using Pointers\n");
	printf("19 = Closest Flight Identifier Function Project Using Pointers\n");
	printf("20 = Swap Points Function Using Pointers \n");
	printf("21 = Integer Input/Hex Output Show List Function\n");
	printf("22 = Recursive Array Reversal Function\n");
	printf("23 = Show Char in Array Function\n");
	printf("24 = Two Dimenstional Array Using Pointers Function\n");
	printf("25 = Dot-Product Function Using Static Arrays Function\n");
	printf("26 = Dot-Product Function Using Pointers Function\n");
	int ex = getNum(); 
	switch (ex) {
	case 1: pointerAlias_ex(); break;
	case 2: pointerIntegerLegality_ex(); break;
	case 3: arrayAveragePointer_ea(); break;
	case 4: pointerSwapFunction_ex(); break;
	case 5: pointerTimeStorageFunction_ex(); break;
	case 6: arrayLargestAndLargeStorageFunction_ex(); break;
	case 7: dayInMonthInYearPointerFunction_ex(); break;
	case 8: arrayLargestElementPointerFunction_ex(); break;
	case 9: billAmtFunc_prjct(564); break;
	case 10: expressions_ea(); break;
	case 11: swapFunction_ea(); break;
	case 12: constPointerTarget_ea(); break;
	case 13: illegalPrintStatement_ea(); break;
	case 14: integerSizeOf_ea(); break;
	case 15: codeSnipperCapacityLegality_ex();break;
	case 16: codeSnippetSizeOf_ea(); break;
	case 17: reverseMessage_array(); break;
	case 18: reverseMessage_pointer(); break;
	case 19: findClosestFlight_prjct(); break;
	case 20: swapPoints_func(); break;
	case 21: showList_ex(); break;
	case 22: reverseRecursiveList_ex(); break;
	case 23: showChars_ex(); break;
	case 24: show2D_ex(); break;
	case 25: dotProduct_array(); break;
	case 26: dotProduct_pointer(); break;
	}
};