// Spinlock.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

class Spinlock {
    atomic <bool> flag;
public:
    Spinlock() : flag(false) {}

    void lock() {
        while (flag.exchange(true));
    }

    void unlock() {
        flag.store(false);
    }
};