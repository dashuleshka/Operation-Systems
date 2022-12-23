//vector<vector<int>> Multiplication(int size, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, vector<vector<int>>& result) {
//	for (int k = 0; k < size; ++k) {
//		for (size_t i = 0; i < size; i++) {
//			for (size_t j = 0; j < size; j++) {
//				result[k][i] += matrix1[k][j] * matrix2[j][i];
//			}
//		}
//	}
//	return result;
//}

#include <iostream>
#include <vector>
#include <thread>
using namespace std;
int i, j;

int MatrixMul(vector <vector <int>>& m1, vector <vector <int>>& m2, int row, int column) {
	int result = 0;
	for (i = 0; i < m1[0].size(); i++) {
		result += m1[row][i] * m2[i][column];
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

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			thr.emplace_back([&result, &matrix1, &matrix2, i, j]() {
				result[i][j] = MatrixMul(matrix1, matrix2, i, j);
				});
		}
	}
	for (auto& i : thr) {
		i.join();
	}

	for (auto& i : result) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
