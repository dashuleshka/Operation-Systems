//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//int s = 0;
//
//void BFS(int s, int** matrix_smezh, int n)
//{
//    queue<int> queue;
//    vector<int> Predsessor(n);
//    vector <bool> visited(n, false);
//    for (int i = 0; i < n; i++)
//    {
//        if (visited[i] == 0)
//        {
//            queue.push(i);
//            s++;
//            Predsessor[i] = s;
//            visited[i] = true;
//            while (!queue.empty() && visited[i] == 1)
//            {
//                int v = queue.front();
//                queue.pop();
//                for (int j = 0; j < n; j++)
//                    if (matrix_smezh[v][j] == 1 && visited[j] == 0)
//                    {
//                        queue.push(j);
//                        s++;
//                        Predsessor[j] = s;
//                        visited[j] = true;
//                    }
//            }
//        }
//        cout << Predsessor[i] << " ";
//    }
//
//}
//
//int main() {
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
//    int n;
//    cin >> n;
//    //vector<int> Predsessor;
//    int** matrix = new int* [n];
//    for (int i = 0; i < n; i++) {
//        matrix[i] = new int[n];
//        for (int j = 0; j < n; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    vector< vector<int>> g; // граф
//    BFS(s, matrix, n);
//    /*for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> g[i][j];
//        }
//    }*/
//    /*void bfs(int n) {
//        queue<int> q;
//        q.push(s);
//        vector<bool> used(n);
//        vector<int> d(n), p(n);
//        used[s] = true;
//        p[s] = -1;
//        while (!q.empty()) {
//            int v = q.front();
//            q.pop();
//            for (size_t i = 0; i < g[v].size(); ++i) {
//                int to = g[v][i];
//                if (!used[to]) {
//                    used[to] = true;
//                    q.push(to);
//                    d[to] = d[v] + 1;
//                    p[to] = v;
//                }
//                if (!used[to])
//                    cout << "No path!";
//                else {
//                    vector<int> path;
//                    for (int v = to; v != -1; v = p[v])
//                        path.push_back(v);
//                    reverse(path.begin(), path.end());
//                    for (size_t i = 0; i < path.size(); ++i)
//                        cout << path[i] + 1 << " ";
//                }
//            }
//        }
//    }*/
//}
using namespace std;
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
