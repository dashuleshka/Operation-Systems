#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
int iter = 0;
mutex m;
int i;
bool checkPrime(int n) {
    bool isPrime = true;
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

void PrimeCheckVec(vector <int>& vec, vector <bool>& res) {
    int temp;
    while (1) {
        unique_lock<mutex> guard(m);
        if (iter == vec.size()) {
            return;
        }
        else {
            iter++;
            temp = iter;
        }
        guard.unlock();
        if (checkPrime(vec[temp - 1]))
            res[temp - 1] = 1;
    }
}


int main() {
    int n;
    cout << "Enter size of vector: " << endl;
    cin >> n;
    cout << "Enter elements: " << endl;
    vector <int> vec(n);
    vector <bool> res(n);
    for (size_t i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }

    cout << endl;
    cout << " Amount of threads : ";
    int sz;
    cin >> sz;
    vector <thread> thr;
    for (int i = 0; i < sz; i++)
    {
        thr.emplace_back(PrimeCheckVec, ref(vec), ref(res));

    }
    for (i = 0; i < sz; i++)
    {
        thr[i].join();
    }
    for (i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}