﻿#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
using namespace std;

vector<vector<int>> Multiplication(int& size, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, vector<vector<int>>& result) {
	for (int k = 0; k < size; ++k) {
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				result[k][i] += matrix1[k][j] * matrix2[j][i];
			}
		}
	}
	return result;
}

 
int main() {
	int size;
	int& copy = size;
	cout << "Input the size of square matrix: ";
	cin >> size;
	vector<vector<int>> matrix1(size, vector<int>(size));
	vector <vector<int>> matrix2(size, vector<int>(size));
	vector<vector<int>> result(size, vector<int>(size));
	cout << "1st Matrix:" << endl;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cin >> matrix1[i][j];
		}
	}
	cout << "2nd Matrix: " << endl;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cin >> matrix2[i][j];
		}
	}
	cout << "Amount of threads: ";
	int count_thread;
	cin >> count_thread;
	vector<thread> thr;
	for (int i = 0; i < count_thread; i++) {
		//thr.emplace_back(power, vec, i);  
		thr.emplace_back([&size, &matrix1, &matrix2, &result]() {Multiplication(size, matrix1, matrix2, result); });
	}
	for (int i = 0; i < count_thread; i++) {
		thr[i].join();
	}
	cout << "The result Is : " << endl;
	for (int i = 0; i < size; i++) {
		cout << endl;
		for (int j = 0; j < size; j++) {
			std::cout << std::right << std::setw(7) << result[i][j];
		}
	}
	return 0;
}
