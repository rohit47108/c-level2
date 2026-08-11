#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include "level2.h"


void negativeAssertion_ex() {
	while (true) {
		printf("Enter an integer: ");
		int x = getNum();
		assert(x > 0);
	}
}

typedef enum {
    SUCCESS = 0,
    ERROR_DIVISION_BY_ZERO = 1,
    ERROR_INVALID_INPUT = 2
} CalculateStatus;
CalculateStatus divide(int a, int b, int* result) {
    if (result == NULL) {
        return ERROR_INVALID_INPUT;
    }
    if (b == 0) {
        return ERROR_DIVISION_BY_ZERO;
    }
    *result = a / b;
    return SUCCESS;
}
int test_divide(int num1, int num2) {
    int res = 0;
    CalculateStatus status = divide(num1, num2, &res);
    switch (status) {
    case SUCCESS:
        printf("Result: %d / %d = %d\n", num1, num2, res);
        return 0;
    case ERROR_DIVISION_BY_ZERO:
        printf("Error: division by zero (num2 == 0)\n");
        return 1;
    case ERROR_INVALID_INPUT:
        printf("Error: invalid input (NULL result pointer)\n");
        return 2;
    default:
        printf("Error: unknown status code %d\n", (int)status);
        return 3;
    }
}
void divideError_ex() {
    printf("Enter two numbers for division test-cases: \n");
    int x = getNum();
    int y = getNum();
    test_divide(x, y);
}

typedef enum {
    FILE_OK = 0,
    ERROR_OPEN_FAILED = 1,
    ERROR_INVALID_ARGUMENT = 2
} FileOpenStatus;
FileOpenStatus open_file_for_read(const char* path, FILE** out, char* err_msg, size_t err_len) {
    if (path == NULL || out == NULL) {
        if (err_msg && err_len > 0) {
            snprintf(err_msg, err_len, "Invalid argument: path and out must not be NULL");
        }
        return ERROR_INVALID_ARGUMENT;
    }
    errno = 0;
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        int saved_errno = errno;
        if (err_msg && err_len > 0) {
            const char* desc = strerror(saved_errno);
            snprintf(err_msg, err_len, "Failed to open '%s' for reading: %s (errno=%d)", path, desc, saved_errno);
        }
        return ERROR_OPEN_FAILED;
    }

    *out = f;
    return FILE_OK;
}
int errorDescription_ex() {
    const char* path = "arrays.cpp";
    FILE* fp = NULL;
    char err[256];
    FileOpenStatus st = open_file_for_read(path, &fp, err, sizeof(err));
    switch (st) {
    case FILE_OK:
        printf("Opened '%s' successfully.\n", path);
        fclose(fp);
        break;
    case ERROR_INVALID_ARGUMENT:
        printf("Invalid argument passed to open_file_for_read\n");
        break;
    case ERROR_OPEN_FAILED:
        printf("%s\n", err);
        break;
    default:
        printf("Unknown status %d\n", (int)st);
    }
    return (st == FILE_OK) ? 0 : 1;
}


void errorchecking_main() {
	printf("Choose an exercise from Error Checking: \n");
	printf("1 = Assert if Negative\n");
	printf("2 = Custom Error Codes and Enums\n");
	printf("3 = File Opening Error Description\n");
	int ex = getNum();
	switch (ex) {
	case 1: negativeAssertion_ex(); break;
    case 2: divideError_ex(); break;
    case 3: errorDescription_ex(); break;
	}
};