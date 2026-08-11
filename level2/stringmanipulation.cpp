#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

void codeSnippetOutput_ex() {
	printf("What does the following program print?\n\n");
	printf("#include <stdio.h>\n\n");
	printf("int main(void) {\n");
	printf("    char s[] = \"Hsjodi\", *p;\n");
	printf("    for (p = s; *p; p++)\n");
	printf("        --*p;\n");
	printf("    puts(s);\n");
	printf("    return 0;\n");
	printf("}\n\n");
	printf("answer:\n");
	printf("each character in the string is decremented by 1 in ascii value\n");
	printf("given string: H s j o d i\n");
	printf("ascii values:    72 115 106 111 100 105\n");
	printf("after --*p:      71 114 105 110  99 104\n");
	printf("which are:       G r i n c h\n\n");
	printf("so the output is:\n");
	printf("Grinch\n");
}

void functionInputValue_ex() {
	printf("Let f be the following function:\n\n");
	printf("int f(char *s, char *t)\n");
	printf("{\n");
	printf("    char *p1, *p2;\n");
	printf("    for (p1 = s; *p1; p1++) {\n");
	printf("        for (p2 = t; *p2; p2++)\n");
	printf("            if (*p1 == *p2) break;\n");
	printf("        if (*p2 == '\\0') break;\n");
	printf("    }\n");
	printf("    return p1 - s;\n");
	printf("}\n\n");
	printf("(a) What is the value of f(\"abcd\", \"babc\")?\n");
	printf("(b) What is the value of f(\"abcd\", \"bcd\")?\n");
	printf("(c) In general, what value does f return when passed two strings s and t?\n\n");
	printf("answer:\n");
	printf("(a) \"abcd\", \"babc\":\n");
	printf("start p1 at 'a': check t = \"babc\" -> 'a' found (second char), continue.\n");
	printf("'b' found in t, continue.\n");
	printf("'c' not found in \"babc\" -> break outer loop.\n");
	printf("return p1 - s = index 2\n\n");
	printf("(b) \"abcd\", \"bcd\":\n");
	printf("'a' not found in t -> break outer loop immediately.\n");
	printf("Return p1 - s = index 0\n\n");
	printf("(c) in general:\n");
	printf("function scans s from the start, checking each char against all of t\n");
	printf("stops when it finds the first char in s that is not in t\n");
	printf("return value is the index in s of that character\n");
	printf("if every char in s is found in t, it returns the length of s\n");
}

int hasExtension(const char* s) {
	const char* dot = strrchr(s, '.');
	if (!dot) return 0;
	return (strlen(dot) > 1 & isalpha((unsigned char)dot[1]));
}
void getBaseUrl(char* url) {
	char* last_slash = strrchr(url, '/');
	if (last_slash && hasExtension(last_slash)) {
		*last_slash = '\0';
	}
}
void urlStringPointer_exfunc() {
	char url[200];
	printf("Enter a URL: ");
	getString(url, sizeof(url));
	getBaseUrl(url);
	printf("Base URL: %s\n", url);
}

void smallestLargestWord_prjct() {
	char word[21], smallest_word[21], largest_word[21];
	printf("Enter word: ");
	getString(smallest_word, sizeof(smallest_word));
	strcpy(largest_word, smallest_word);
	while (1) {
		printf("Enter word: ");
		getString(word, sizeof(word));
		if (strlen(word) == 4) {
			break;
		}
		if (strcmp(word, smallest_word) < 0) {
			strcpy(smallest_word, word);
		}
		if (strcmp(word, largest_word) > 0) {
			strcpy(largest_word, word);
		}
	}
	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);
}

#define MAX_REMIND 50
#define MSG_LEN 60
void reminderList_prjct() {
	char reminders[MAX_REMIND][MSG_LEN + 10], month_day[6], time_str[6], msg_str[MSG_LEN + 1];
	int month, day, hour, min, num_remind = 0;
	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}
		printf("Enter month/day (mm/dd, 0/0 to end): ");
		getString(month_day, sizeof(month_day));
		if (sscanf(month_day, "%d/%d", &month, &day) != 2) {
			printf("** Invalid date format, try again **\n");
			continue;
		}
		if (month == 0 && day == 0) break;
		if (month < 1 || month > 12 || day < 1 || day > 31) {
			printf("** Invalid date: ignored **\n");
			continue;
		}
		printf("Enter 24-hour time (hh:mm): ");
		getString(time_str, sizeof(time_str));
		if (sscanf(time_str, "%d:%d", &hour, &min) != 2 ||
			hour < 0 || hour > 23 || min < 0 || min > 59) {
			printf("** Invalid time: ignored **\n");
			continue;
		}
		printf("Enter reminder name: ");
		getString(msg_str, sizeof(msg_str));
		char full_entry[MSG_LEN + 10];
		sprintf(full_entry, "%2d/%2d %.2d:%.2d %s", month, day, hour, min, msg_str);
		int i, j;
		for (i = 0; i < num_remind; i++) {
			int m, d, h, mi;
            if (sscanf(reminders[i], "%d/%d %d:%d", &m, &d, &h, &mi) != 4) {
													continue;
            }
			if (month < m ||
				(month == m && day < d) ||
				(month == m && day == d && (hour < h || (hour == h && min < mi)))) {
				break;
			}
		}
		for (j = num_remind; j > i; j--) {
			strcpy(reminders[j], reminders[j - 1]);
		}
		strcpy(reminders[i], full_entry);
		num_remind++;
	}

	printf("\nDay  Time  Reminder\n");
	for (int i = 0; i < num_remind; i++) {
		printf("%s\n", reminders[i]);
	}
}

void sumIntegers_prjct() {
	char line[200];
	int total = 0;
	char* token;
	printf("sum ");
	getString(line, sizeof(line));
	token = strtok(line, " ");
	while (token != NULL) {
		total += atoi(token);
		token = strtok(NULL, " ");
	}
	printf("Total: %d\n", total);
}

void floatingPointAverage_ex() {
	char output[100];
	printf("Enter first floating point number: ");
	double num1 = getDouble();
	printf("Enter second floating point number: ");
	double num2 = getDouble();
	double average = (num1 + num2) / 2.0;
	sprintf(output, "The average of $%.2f and $%.2f = $%.2f", num1, num2, average);
	printf("%s\n", output);
}

void countVowelsConsonants_func(const char* str, int* vowels, int* consonants) {
	*vowels = 0;
	*consonants = 0;
	while (*str) {
		char ch = tolower((unsigned char)*str);
		if (isalpha(ch)) {
			if (strchr("aeiou", ch)) {
				(*vowels)++;
			} else {
				(*consonants)++;
			}
		}
		str++;
	}
}
void countVowelsConsonants_ex() {
	char str[100];
	int vowels, consonants;
	printf("Enter a string: ");
	getString(str, sizeof(str));
	countVowelsConsonants_func(str, &vowels, &consonants);
	printf("Number of vowels: %d\n", vowels);
	printf("Number of consonants: %d\n", consonants);
}

void maxOccurringChar_ex()	 {
	char str[100];
	int count[256] = { 0 };
	int max_count = 0;
	char max_char = '\0';
	printf("Enter a string: ");
	getString(str, sizeof(str));
	for (int i = 0; str[i]; i++) {
		if (isalpha((unsigned char)str[i])) {
			count[(unsigned char)tolower(str[i])]++;
			if (count[(unsigned char)tolower(str[i])] > max_count) {
				max_count = count[(unsigned char)tolower(str[i])];
				max_char = tolower(str[i]);
			}
		}
	}
	printf("The highest frequency of character: '%c'\n", max_char);
	printf("Appears number of times: %d\n", max_count);
}


void swapCase_func(char* str) {
	while (*str) {
		if (islower((unsigned char)*str)) {
			*str = toupper((unsigned char)*str);
		} else if (isupper((unsigned char)*str)) {
			*str = tolower((unsigned char)*str);
		}
		str++;
	}
}
void swapCase_ex() {
	char str[100];
	printf("Enter a string: ");
	getString(str, sizeof(str));
	swapCase_func(str);
	printf("Swapped case string: %s\n", str);
}

void searchSubstringWood_ex() { 
    char str[100], substr[50] = "wood";
    printf("Enter a string: ");
    getString(str, sizeof(str));
    char *p = str;
    int found = 0;
    while ((p = strstr(p, "wood")) != NULL) {
        int index = p - str; 
        printf("\"wood\" found at index: %d %p\n", index, p);
        p++;
        found = 1;
    }
    if (!found) {
        printf("\"wood\" not found.\n");
    }
}

char* findLastSubstring(const char* str, const char* substr) {
	const char* last_occurrence = NULL;
	const char* current_occurrence = strstr(str, substr);
	while (current_occurrence != NULL) {
		last_occurrence = current_occurrence;
		current_occurrence = strstr(current_occurrence + 1, substr);
	}
	return (char*)last_occurrence;
}
void searchLastSubstring_ex() {
	char str[100], substr[50];
	printf("Enter a string: ");
	getString(str, sizeof(str));
	printf("Enter substring to find last occurrence: ");
	getString(substr, sizeof(substr));
	char* last_occurrence = findLastSubstring(str, substr);
	if (last_occurrence) {
		int index = last_occurrence - str;
		printf("Last occurrence of \"%s\" found at index: %d %p\n", substr, index, last_occurrence);
	} else {
		printf("\"%s\" not found.\n", substr);
	}
}

char *replaceSubstring(const char* str, const char* old_substr, const char* new_substr) {
	static char buffer[256];
	const char* pos = strstr(str, old_substr);
	if (!pos) {
		strcpy(buffer, str);
		return buffer;
	}
	int index = pos - str;
	strncpy(buffer, str, index);
	buffer[index] = '\0';
	strcat(buffer, new_substr);
	strcat(buffer, pos + strlen(old_substr));
	return buffer;
}
void replaceSubstring_ex() {
	char str[100], old_substr[50], new_substr[50];
	printf("Enter a string: ");
	getString(str, sizeof(str));
	printf("Enter substring to replace: ");
	getString(old_substr, sizeof(old_substr));
	printf("Enter new substring: ");
	getString(new_substr, sizeof(new_substr));
	char* result = replaceSubstring(str, old_substr, new_substr);
	printf("Resulting string: %s\n", result);
}

void stringToNumber_func(const char* str, int* number) {
	*number = 0;
	int sign = 1;
	if (*str == '-') {
		sign = -1;
		str++;
	} else if (*str == '+') {
		str++;
	}
	while (*str) {
		if (!isdigit((unsigned char)*str)) {
			printf("Invalid character '%c' in input string.\n", *str);
			return;
		}
		*number = *number * 10 + (*str - '0');
		str++;
	}
	*number *= sign;
}
void stringToNumber_ex() {
	char str[100];
	int number;
	printf("Enter a string representing an integer: ");
	getString(str, sizeof(str));
	stringToNumber_func(str, &number);
	printf("Converted number: %d\n", number);
}

void mooElimination_func (char* str, const char* substr) {
	char* pos;
	size_t len = strlen(substr);
	while ((pos = strstr(str, substr)) != NULL) {
		memmove(pos, pos + len, strlen(pos + len) + 1);
	}
}
void mooElimination_ex() {
	char str[100], substr[50];
	printf("Enter a string: ");
	getString(str, sizeof(str));
	strcpy(substr, "moo");
	mooElimination_func(str, substr);
	printf("Resulting string after elimination: %s\n", str);
}

void stringmanipulation_main() {
	printf("Choose an exercise from string manipulation: \n");
	printf("1-3 (ch 13 textbook exercises) 4-6 (ch 13 projects) 7 - 15 (packet exercises)\n");
	printf("1 = Code Snippet Output\n");
	printf("2 = Function Input Value\n");
	printf("3 = URL String Pointer Function\n");
	printf("4 = Smallest and Largest Word Identifier Alphabetically Project\n");
	printf("5 = Reminder List Project\n");	
	printf("6 = Summation Per Integer Input Project\n");
	printf("7 = Floating Point Numbers Average Identifier in a String\n");
	printf("8 = # of Vowels/Consonants in a String Identifier Function\n");
	printf("9 = Maximum Occurring Character in a String Idenfifier Function		\n");
	printf("10 = Uppercase/Lowercase Swap Function\n");
	printf("11 = Search of Index/Location (subscript value and memory address) of a Sub-String Wood\n");
	printf("12 = Search of Last Index/Location of a Sub-String\n"); 
	printf("13 = Sub-String Replacement w/ Different Sub-String\n");
	printf("14 = String to Number Function\n");
	printf("15 = Sub-String Elimination\n");
	int ex = getNum();
	switch (ex) {
	case 1: codeSnippetOutput_ex(); break;
	case 2:	functionInputValue_ex(); break;
	case 3: urlStringPointer_exfunc(); break;
	case 4: smallestLargestWord_prjct(); break;
	case 5: reminderList_prjct(); break;
	case 6: sumIntegers_prjct(); break;
	case 7: floatingPointAverage_ex(); break;
	case 8: countVowelsConsonants_ex(); break;
	case 9: maxOccurringChar_ex(); break;
	case 10: swapCase_ex(); break;
	case 11: searchSubstringWood_ex(); break;
	case 12: searchLastSubstring_ex(); break;
	case 13: replaceSubstring_ex(); break;
	case 14: stringToNumber_ex(); break;
	case 15: mooElimination_ex(); break;
	}
};
