#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"

struct Employee {
    char fname[80];
    char mname[80];
    char lname[80];
    double salary;
};

void avgSum_func(double a[], int n, double &avg, double &sum) {
	int i;
	sum = 0.0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	avg = sum / n;
}
void avgSum_ex() {
	double a[10];
	printf("Enter 10 numbers: ");
	for (int i = 0; i < 10; i++) {
		a[i] = getDouble();
	}
	double avg, sum;
	avgSum_func(a, 10, avg, sum);
	printf("Average: %.2f\n", avg);
	printf("Sum: %.2f\n", sum);
}

void findTwoLargest_func(int a[], int n, int &largest, int &second_largest) {
	if (n < 2) {
		printf("Array must have at least two elements.\n");
		return;
	}
	largest = second_largest = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i] > largest) {
			second_largest = largest;
			largest = a[i];
		} else if (a[i] > second_largest && a[i] != largest) {
			second_largest = a[i];
		}
	}
}
void findTwoLargest_ex() {
	int a[10];
	printf("Enter 10 integers: ");
	for (int i = 0; i < 10; i++) {
		a[i] = getNum();
	}
	int largest, second_largest;
	findTwoLargest_func(a, 10, largest, second_largest);
	printf("Largest: %d\n", largest);
	printf("Second Largest: %d\n", second_largest);
}

void splitDate_func(int day_of_year, int year, int &month, int &day) {
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29; 
	}
	int m = 0;
	while (day_of_year > days_in_month[m]) {
		day_of_year -= days_in_month[m];
		m++;
	}
	month = m + 1;
	day = day_of_year;
}
void splitDate_ex() {
	int day_of_year, year, month, day;
	printf("Enter year: ");
	year = getNum();
	printf("Enter day of the year (1-365 or 366 for leap years): ");
	day_of_year = getNum();
	splitDate_func(day_of_year, year, month, day);
	printf("Month: %d, Day: %d\n", month, day);
}

int* findLargest_func(int a[], int n) {
	if (n <= 0) return nullptr;
	int* largest = &a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > *largest) {
			largest = &a[i];
		}
	}
	return largest;
}
void findLargest_ex() {
	int a[10];
	printf("Enter 10 integers: ");
	for (int i = 0; i < 10; i++) {
		a[i] = getNum();
	}
	int* largest = findLargest_func(a, 10);
	if (largest) {
		printf("The largest number is: %d\n", *largest);
	} else {
		printf("Array is empty.\n");
	}
}

void increaseSalaryptr(Employee* emp, double percentage) {
	if (emp != nullptr) {
		emp->salary += emp->salary * (percentage / 100.0);
	}
}
void increaseSalaryref(Employee& emp, double percentage) {
	emp.salary += emp.salary * (percentage / 100.0);
}
void increaseSalary_ex() {
	Employee emp;
	printf("Enter employee's first name: ");
	getString(emp.fname, 80);
	printf("Enter employee's middle name: ");
	getString(emp.mname, 80);
	printf("Enter employee's last name: ");
	getString(emp.lname, 80);
	printf("Enter employee's salary: ");
	emp.salary = getDouble();
	printf("Current salary: %.2f\n", emp.salary);
	double percentage;
	printf("Enter percentage to increase salary: ");
	percentage = getDouble();
	increaseSalaryptr(&emp, percentage);
	printf("New salary after pointer function: %.2f\n", emp.salary);
	increaseSalaryref(emp, percentage);
	printf("New salary after reference function: %.2f\n", emp.salary);
}

void pointerReferenceTest_ex() {
	int x = 42;
	int& r = x; 
	int* p = &r; 
	printf("Initial values: x = %d, r = %d, *p = %d\n", x, r, *p);
	*p = 100; 
	printf("After *p = 100: x = %d, r = %d, *p = %d\n", x, r, *p);
	r++; 
	printf("After r++: x = %d, r = %d, *p = %d\n", x, r, *p);
	int& r2 = *p; 
	r2 = 100; 
	printf("After r2 = 100: x = %d, r = %d, *p = %d\n", x, r, *p);
	int y = 222; 
	p = &y; 
	r2 = 1; 
	printf("After p points to y and r2 = 1: x = %d, y = %d, *p = %d, r = %d\n", x, y, *p, r);
}


void validCodeCheck_ex() {
	printf("int x = 42;\nint& r = x;\nint&& r2 = r;\n");
	printf("The code is invalid because you cannot bind an rvalue reference (int&&) to an lvalue (r).\n");
}

void references_main() {
	printf("Choose an exercise from references: \n");
	printf("1 = Average and Sum Rewrite\n");
	printf("2 = Largest and Second Largest Search\n");
	printf("3 = Split Date Function\n");
	printf("4 = Largest Pointer Search\n");
	printf("5 = Employees + Pointers\n");
	printf("6 = Pointer and Reference Test\n");
	printf("7 = Valid Code Check\n");
	int ex = getNum();
	switch (ex) {
	case 1: avgSum_ex(); break;
	case 2: findTwoLargest_ex(); break;
	case 3: splitDate_ex(); break;
	case 4: findLargest_ex(); break;
	case 5: increaseSalary_ex(); break;
	case 6: pointerReferenceTest_ex(); break;
	case 7: validCodeCheck_ex(); break;
	}
};