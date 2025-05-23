#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
using namespace std;

shared_mutex rw_mutex; 

void reader(int id) {
    while (true) {
        rw_mutex.lock_shared();
        cout << "Reader " << id << " is reading...\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Reader  " << id << " done reading\n";
        rw_mutex.unlock_shared();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void writer(int id) {
    while (true) {
        rw_mutex.lock();
        cout << "Writer " << id << " is writing...\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Writer " << id << " done writing\n";
        rw_mutex.unlock();
        this_thread::sleep_for(chrono::milliseconds(1500));
    }
}

int main() {
    thread r1(reader, 1), r2(reader, 2), w1(writer, 1);
    r1.join(); r2.join(); w1.join();
    return 0;
}
