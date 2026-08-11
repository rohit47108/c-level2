#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "level2.h"
#include <vector>
using namespace std;

void creationInitialization_ex() {
	vector<int> v1{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> v2 = { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> v3(10, 42);
	vector<int> v4{ 10, 42 };
	vector<string> v5(10, "Monkey");
	vector<string> v6(v5);
	vector<int> v7{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto i : v7) {
		i *= 10;
	}
}

void atVsBracket_ex() {
	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*for (int i = 0; i < 15; i++) {
		printf("%d\n", v1.at(i));
	}
	for (int j = 0; j < 15; j++) {
		printf("%d", v1[j]);
	}*/
	printf("v1.at(15) will throw an out_of_range exception, while v1[15] will not throw an exception but will result in undefined behavior.\n");
}

void rangedForLoop_ex() {
	vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<string> v2{ "hamilton", "washington", "lincoln", "joe" };
	for (auto j : v1) {
		printf("%d ", j);
	}
	for (auto& j : v1) {
		j++;
		printf("%d ", j);
	}
	for (auto k : v2) {
		printf("%s ", k.c_str());
	}
	for (auto &l : v2) {
		for (auto &m : l) {
			l[m] = toupper(static_cast<unsigned char>(l[m]));
		}
		printf("%s ", l.c_str());
	}
}

void employees_ex() {
	struct Employee {
		string firstName;
		string lastName;
		int age = 0;
		double salary = 10000;
	};
	vector<Employee> Employees = { {"Rohit", "Singh", 14, 250000.00}, {"John", "Doe", 15, 2.50} };
	while (true) {
		Employee employee;
		printf("Enter first name (or QUIT to stop): ");
		char buffer[51];
		getString(buffer, 50);
		employee.firstName = buffer;
		if (employee.firstName == "QUIT") {
			break;
		}
		printf("Enter last name: ");
		getString(buffer, 50);
		employee.lastName = buffer;
		printf("Enter age: ");
		employee.age = getNum();
		printf("Enter salary: ");
		employee.salary = getDouble();
		Employees.push_back(employee);
	}
	double totalSalary = 0.0;
	for (const auto& emp : Employees) {
		totalSalary += emp.salary;
	}
	double averageSalary = totalSalary / Employees.size();
	printf("Average salary: %.2f\n", averageSalary);
}

void twoDVector_ex() {
	vector<vector<int>> vvi(5);
	for (int i = 0; i < 5; i++) {
		vvi[i].resize(5);
		printf("Enter row %d: ", i + 1);
		for (int j = 0; j < 5; j++) {
			vvi[i][j] = getNum();
		}
	}
	printf("Row totals: ");
	for (const auto& row : vvi) {
		int rowSum = 0;
		for (const auto& elem : row) {
			rowSum += elem;
		}
		printf("%d ", rowSum);
	}
	printf("\nColumn totals: ");
	for (int j = 0; j < 5; j++) {
		int colSum = 0;
		for (int i = 0; i < 5; i++) {
			colSum += vvi[i][j];
		}
		printf("%d ", colSum);
	}
	printf("\n");
}

void sizeVsCapacity_ex() {
	vector<int> vi;
	vi.reserve(100);
	for (int i = 0; i < 100; i++) {
		vi.push_back(i);
		printf("Size: %zu, Capacity: %zu\n", vi.size(), vi.capacity());
	}
	vi.clear();
	printf("After clear ~ Size: %zu, Capacity: %zu\n", vi.size(), vi.capacity());
	vi.shrink_to_fit();
	printf("After shrink_to_fit ~ Size: %zu, Capacity: %zu\n", vi.size(), vi.capacity());
	vi.resize(100);
	printf("After resize(100) ~ Size: %zu, Capacity: %zu\n", vi.size(), vi.capacity());
}

void codeSnippetOutput1_ex() {
	std::vector<int> v1{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> v2{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> v3{ 2, 3, 4, 5, 6, 7 };
	if (v1 == v2) std:cout << "v1 == v2\n";
	else std::cout << "v1 != v2\n";
	if (v2 == v3) std::cout << "v2 == v3\n";
	else std::cout << "v2 != v3\n";
	if (v2>v3) std::cout << "v2 > v3\n";
	else std::cout << "v2 < v3\n";
	printf("What is the output and why?\n");
	printf("v1 == v2 because all elements are equal.\n");
	printf("v2 != v3 because the first elements are different.\n");
	printf("v2 < v3 because the first element of v2 is less than the first element of v3.\n");
}

void vectors_main() {
	printf("Choose an exercise from vectors: \n");
	printf("1 = Creation and Initialization\n");
	printf("2 = at() vs. []\n");
	printf("3 = Ranged For Loop\n");
	printf("4 = Employees Exercise\n");
	printf("5 = 2D Vector\n");
	printf("6 = Size vs. Capacity\n");
	printf("7 = Code Snippet Output\n");
	int ex = getNum();
	switch (ex) {
		case 1: creationInitialization_ex(); break;
		case 2: atVsBracket_ex(); break;
		case 3: rangedForLoop_ex(); break;
		case 4: employees_ex(); break;
		case 5: twoDVector_ex(); break;
		case 6: sizeVsCapacity_ex(); break;
		case 7: codeSnippetOutput1_ex(); break;
	}
};