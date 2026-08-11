#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

#define MAXR 25
#define MAXC 20
int abc[MAXR][MAXC];
void sizeof_result() {
    int rows = sizeof(abc) / sizeof(abc[0]);
    int cols = sizeof(abc[0]) / sizeof(abc[0][0]);
    printf("Number of rows: %d\n", rows); 
    printf("Number of columns: %d\n", cols);
}

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void reverse_result() {
    int x[] = { 10, 4, 1, 9 };
    int size = sizeof(x) / sizeof(x[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    reverse(x, size);
    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void alphabetArray_result() {
    char a[26];
    for (int i = 0; i < sizeof(a); i++) {
        a[i] = 'A' + i; 
    }
    for (int i = 0; i < sizeof(a); i++) {
        printf("%c", a[i]);
        if (i < sizeof(a) - 1) {
            printf(","); 
        }
    }
    printf("\n");
};

void alphabetArrayPlus_results() {
    char firstLetter;
    printf("Enter the first letter: ");
    firstLetter = getchar();
    if (!isalpha(firstLetter) || !isupper(firstLetter)) {
        printf("Please enter a valid uppercase letter.\n");
        return; 
    }
    char current = firstLetter;
    for (int i = 0; i < 26; i++) {
        if (i % 5 == 4) { 
            printf("%c,", tolower(current));
        }
        else { 
            printf("%c,", toupper(current));
        }
        current++;
        if (current > 'Z') { 
            current = 'A';
        }
    }
    printf("\n"); 
} 

void calculateWordScore(const char word[]) {
    int totalScore = 0;
    printf("Scores for each letter: ");
    for (int i = 0; word[i] != '\0'; i++) {
        char current = word[i];
        int letterScore = 0;
        switch (tolower(current)) {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            letterScore = 5; break;
        case 'q': case 'x': case 'z':
            letterScore = 20; break;
        default:
            letterScore = 10; break;
        }
        if (isupper(current)) {
            letterScore += 2;
        }
        printf("%d ", letterScore); 
        totalScore += letterScore;
    }
    printf("\nTotal score for the word '%s' is: %d\n", word, totalScore);
}
void calculateWordScore_result() {
    char word[100]; 
    printf("Enter the word: ");
    getString(word, 99);

    calculateWordScore(word);
}

void displayBinary(int number) {
    if (number == 0) {
        printf("0");
        return;
    }
    int binary[32]; 
    int index = 0;
    while (number > 0) {
        binary[index++] = number % 2; 
        number /= 2;
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}
void displayBinary_result() {
    int number;
    printf("Enter a base-10 number: ");
    number = getNum();
    printf("%d (base-10) = ", number);
    displayBinary(number);
    printf("(base-2)\n");
}

void childInfo_result() {
    const char* names[] = { "Beth", "Dennis" };
    const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    const char* genders[] = { "Daughter", "Son     " };
    printf("Child\t\tName\t\tAge\n");
    printf("===================================\n");
    for (int i = 0, age = 30; i < 10; i++, age -= 2) {
        int nameIndex = i % 2; 
        int vowelIndex = i / 2;
        printf("%s\t%s%c\t\t%d\n", genders[i % 2], names[i % 2], vowels[i / 2], age);
    }
}

void sieveOfEratosthenes(int n) {
    char* isPrime = (char*)malloc((n + 1) * sizeof(char)); 
    memset(isPrime, 1, n + 1); 
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) { 
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0; 
            }
        }
    }
    printf("Primes under %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d ", i); 
        }
    }
    printf("\n");
    free(isPrime); 
}
void sieveOfEratosthenes_result() {
    int n;
    printf("Enter the upper limit for prime generation (N): ");
    n = getNum();
    sieveOfEratosthenes(n); 
}

void fillSpiral(int table[6][4], int start) {
    int rows = 6, cols = 4;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int value = start;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            table[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            table[i][right] = value++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                table[bottom][i] = value++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                table[i][left] = value++;
            }
            left++;
        }
    }
}
void displayTable(int table[6][4]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}
void spiralTable_result() {
    int table[6][4];
    int start;

    printf("Enter the starting number: ");
    start = getNum();

    fillSpiral(table, start);
    printf("Spiral table:\n");
    displayTable(table);
}

#define WORDS_COUNT 7
#define MAX_WORD_LENGTH 100
void calculateFrequency(const char* word, int frequency[26]) {
    for (int i = 0; i < 26; i++) {
        frequency[i] = 0;
    }
    for (int i = 0; word[i] != '\0'; i++) {
        frequency[word[i] - 'a']++;
    }
}
bool areFrequenciesEqual(const int freq1[26], const int freq2[26]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}
void anagramFrequency_result() {
    const char words[WORDS_COUNT][MAX_WORD_LENGTH] = {
        "aaabc", "cbaad", "aadbc", "cbaaa", "cdcdcd", "dccdcd", "abcaa"
    };
    int frequency[WORDS_COUNT][26]; 
    int anagramSet[WORDS_COUNT];
    for (int i = 0; i < WORDS_COUNT; i++) {
        calculateFrequency(words[i], frequency[i]);
        anagramSet[i] = 0;
    }
    int setNumber = 1; 
    for (int i = 0; i < WORDS_COUNT; i++) {
        if (anagramSet[i] == 0) { 
            anagramSet[i] = setNumber; 

            for (int j = i + 1; j < WORDS_COUNT; j++) {
                if (anagramSet[j] == 0 && areFrequenciesEqual(frequency[i], frequency[j])) {
                    anagramSet[j] = setNumber; 
                }
            }
            setNumber++; 
        }
    }
    printf("| Word     | Anagram Set |\n");
    printf("|----------|-------------|\n");
    for (int i = 0; i < WORDS_COUNT; i++) {
        printf("| %-8s | %11d |\n", words[i], anagramSet[i]);
    }
}

void arrays_main() {
    printf("Choose an exercise from arrays: \n");
    printf("1 = Generate array values using sizeof\n");
    printf("2 = Reverse the value stored in an array\n");
    printf("3 = Print alphabet in an array\n");
    printf("4 = Alphabet with user start and every fifth lowercase\n");
    printf("5 = Word to scores\n");
    printf("6 = Display a number in binary\n");
    printf("7 = Smith child info\n");
    printf("8 = Sieve of Eratosthenes Prime Number Generator\n");
    printf("9 = Number spiral\n");
    printf("10 = Anagrams set\n");
    int ex = getNum();
    switch (ex) {
    case 1: sizeof_result(); break;
    case 2: reverse_result(); break;
    case 3: alphabetArray_result(); break;
    case 4: alphabetArrayPlus_results(); break;
    case 5: calculateWordScore_result(); break;
    case 6: displayBinary_result(); break;
    case 7: childInfo_result(); break;
    case 8: sieveOfEratosthenes_result(); break;
    case 9: spiralTable_result(); break;
    case 10: anagramFrequency_result(); break;
    }
};