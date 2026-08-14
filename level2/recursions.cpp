#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

long long getNum() {
    long long num = 0;
    int sign = 1;
    char ch = getchar();
    while (ch == ' ' || ch == '\t') {
        ch = getchar();
    }
    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }
    else if (ch == '+') {
        ch = getchar();
    }
    while (ch != '\n' && isdigit(ch)) {
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * sign;
}
double getDouble() {
    double num = 0.0, fraction = 0.0, divisor = 1.0;
    char ch;
    int decimalSeen = 0;
    while ((ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            if (decimalSeen) {
                fraction = fraction * 10 + (ch - '0');
                divisor *= 10;
            }
            else {
                num = num * 10 + (ch - '0');
            }
        }
        else if (ch == '.' && !decimalSeen) {
            decimalSeen = 1;
        }
        else {
            break;
        }
    }
    return num + fraction / divisor;
}
void getString(char* str, int size) {
    scanf(" %[^\n]", str);
}

int sumUpToN(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n + sumUpToN(n - 1); 
    }
}
void sumUpToN_result() {
    int n;
    printf("Enter a number (n): ");
    n = getNum();
    int result = sumUpToN(n);
    printf("The sum of natural numbers up to %d is: %d\n", n, result);
}

void prtn20(int n) {
    if (n < 0) { 
        return;
    }
    else {
        printf("%d ", n); 
        prtn20(n - 1);   
    }
}
void prtn20_result() {
    int n;
    printf("Enter a number (n): ");
    n = getNum();
    printf("Numbers from %d down to 0:\n", n);
    prtn20(n);
    printf("\n"); 
}

void prt02n(int n) {
    if (n < 0) { 
        return;
    }
    else {
        prt02n(n - 1);  
        printf("%d ", n); 
    }
}
void prt02n_result() {
    int n;
    printf("Enter a number (n): ");
    n = getNum();

    printf("Numbers from 0 to %d:\n", n);
    prt02n(n);
    printf("\n"); 
}

int countDigits(int n) {
    if (n == 0) { 
        return 0;
    }
    else {
        return 1 + countDigits(n / 10); 
    }
}
void countDigits_result() {
    int n;
    printf("Enter a number: ");
    n = getNum();
    if (n < 0) {
        n = -n;
    }
    int digitCount = countDigits(n);
    printf("The number of digits is: %d\n", digitCount);
}

int gcd(int a, int b) {
    if (b == 0) { 
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
void gcd_result() {
    int a, b;
    printf("Enter two numbers to find their GCD:\n");
    printf("Number 1: ");
    a = getNum();
    printf("Number 2: ");
    b = getNum();

    int result = gcd(a, b);
    printf("The GCD of %d and %d is: %d\n", a, b, result);
}

void showBinary_char(char number) {
    if (number == 0 || number == -1) { 
        return;
    }
    showBinary_char((number >> 1) & 0x7F); 
    printf("%d", number & 1); 
}
void showBinary_short(short number) {
    if (number == 0 || number == -1) { 
        return;
    }
    showBinary_short((number >> 1) & 0x7FFF); 
    printf("%d", number & 1); 
}
void showBinary_int(int number) {
    if (number == 0 || number == -1) { 
        return;
    }
    showBinary_int(number >> 1); 
    printf("%d", number & 1); 
}
void showBinary_result() {
    int type;
    printf("Choose a type to display binary representation (1=char, 2=short, 3=int): ");
    type = getNum();
    if (type == 1) {
        char number;
        printf("Enter a char type number: ");
        number = getchar();
        printf("Binary: ");
        showBinary_char(number);
    }
    else if (type == 2) {
        short number;
        printf("Enter a short type number: ");
        number = getNum();
        printf("Binary: ");
        showBinary_short(number);
    }
    else if (type == 3) {
        int number;
        printf("Enter an int type number: ");
        number = getNum();
        printf("Binary: ");
        showBinary_int(number);
    }
    else {
        printf("Invalid type selected.\n");
    }
    printf("\n");
}

double f(double x, int y) {
    if (y == 0) {
        return 1; 
    }
    else if (y > 0) {
        return x * f(x, y - 1); 
    }
    else { 
        return 1.0 / f(x, -y); 
    }
}
void f_result() {
    double x;
    int y;

    printf("Enter the value of x: ");
    x = getDouble();
    printf("Enter the value of y: ");
    y = getNum();

    double result = f(x, y);
    printf("f(%.2lf, %d) = %.2lf\n", x, y, result);
}

int baseExp(int base, int exponent) {
    if (exponent == 0) { 
        return 1;
    }
    else if (exponent > 0) { 
        return base * baseExp(base, exponent - 1);
    }
}
void baseExp_result() {
    int base, exponent;

    printf("Enter the base: ");
    base = getNum();
    printf("Enter the exponent: ");
    exponent = getNum();

    int result = baseExp(base, exponent);
    printf("%d raised to the power %d is: %d\n", base, exponent, result);
}

void drawTriangle(int height) {
    if (height == 0) { 
        return;
    }
    drawTriangle(height - 1); 
    for (int i = 0; i < height; i++) { 
        printf("#");
    }
    printf("\n"); 
}
void drawTriangle_result() {
    int height;
    printf("Enter the height of the triangle: ");
    height = getNum();

    printf("The triangle of height %d is:\n", height);
    drawTriangle(height);
}

void drawTriangleUpsideDown(int height) {
    if (height == 0) {
        return;
    }
    for (int i = 0; i < height; i++) { 
        printf("#");
    }
    printf("\n"); 
    drawTriangleUpsideDown(height - 1); 
};
void drawTriangleUpsideDown_result() {
    int height;
    printf("Enter the height of the upside-down triangle: ");
    height = getNum();

    printf("The upside-down triangle of height %d is:\n", height);
    drawTriangleUpsideDown(height);
};

char* bal(char* p) {
    // Base case: reached end of string, all brackets were matched
    if (*p == '\0') {
        return p;
    }

    // Skip non-bracket characters
    if (*p != '{' && *p != '(' && *p != '}' && *p != ')') {
        return bal(p + 1);
    }

    // Opening bracket found
    if (*p == '{' || *p == '(') {
        char opening = *p;

        // Recursively search for the matching closing bracket
        char* nextp = bal(p + 1);

        // Check if we found a closing bracket
        if (nextp != nullptr && *nextp != '\0') {
            char closing = *nextp;

            // Verify the match: { with }, ( with )
            if ((opening == '{' && closing == '}') || 
                (opening == '(' && closing == ')')) {

                // Match found! Continue searching after the closing bracket
                return bal(nextp + 1);
            }
        }

        // No valid match found
        return p;
    }

    // Closing bracket without matching opening bracket
    if (*p == '}' || *p == ')') {
        return p;
    }

    return p;
}

bool balance(char* string) {
    if (string == nullptr) {
        return false;
    }

    char* result = bal(string);

    // All brackets matched if bal() returns pointer to '\0'
    return (result != nullptr && *result == '\0');
}

void balance_result() {
    char phrase[256];
    printf("Enter phrase: ");
    getString(phrase, sizeof(phrase));

    if (balance(phrase)) {
        printf("Result: Balance\n");
    }
    else {
        printf("Result: Not Balance\n");
    }
}

void recursions_main() {
	printf("Choose an exercise from recursions: \n");
    printf("1 = Recursive function returning sum of series of natural numbers up to n\n");
    printf("2 = Function using recursion 'void prtn20(int n)' printing numbers n to 0\n");
    printf("3 = Function using recursion 'void prt02n(int n)' printing numbers 0 to n\n");
    printf("4 = Function 'int countDigits(int n)' returning # of digits in a number\n");
    printf("5 = Function 'int gcd(int a, int b)' reutrning gcf of 2 numbers using Euclids Algorithm, recursively\n");
    printf("6 = 3 recursive functions printing binary of a number with diff types\n");
    printf("7 = Recursive algorithm\n");
    printf("8 = Function int baseExp(int base, int exponent) that recursively computes base exponent with given base and exponent\n");
    printf("9 = Function 'void drawTriangle()' to print a left justified right triangle of a given height\n");
    printf("10 = Function 'void drawTriangleUpsideDown()' to print of a given height\n");
    int ex = getNum();
    switch (ex) {
    case 1: sumUpToN_result(); break;
    case 2: prtn20_result(); break;
    case 3: prt02n_result(); break;
    case 4: countDigits_result(); break;
    case 5: gcd_result(); break;
    case 6: showBinary_result(); break;
    case 7: f_result(); break;
    case 8: baseExp_result(); break;
    case 9: drawTriangle_result(); break;
    case 10: drawTriangleUpsideDown_result(); break;

    }
};