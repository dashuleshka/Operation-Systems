// Producer-Consumer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <cmath>

using namespace std;
condition_variable condvia;
mutex cv_mutex;
bool flag = false;


void Find_next_primeNumber(int n, int& result) {

	bool prime = true;
	while (!flag) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			result = n;
			flag = true;
			break;
		}
		prime = true;
		n++;
	}

	condvia.notify_one();
}

void Print(int& result) {
	unique_lock<mutex> lock(cv_mutex);
	while (!flag) {
		condvia.wait(lock);
	}
	cout << result;
}



int main() {
	int number;
	cout << "Enter your number: ";
	cin >> number;
	int result = 0;

	thread t1(Print, ref(result)), t2(Find_next_primeNumber, number, ref(result));

	t1.join();
	t2.join();

}
