#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// Mutexes used by threads
mutex mtx1;
mutex mtx2;

// --- Example 1: Thread with arguments ---
void worker(const string& name, int delay) {
    cout << "Thread " << name << " starting\n";
    this_thread::sleep_for(chrono::seconds(delay));
    cout << "Thread " << name << " finished after " << delay << " seconds\n";
}

// --- Example 2: Deadlock simulation ---
void deadlock_thread1() {
    cout << "Thread 1: Trying to lock mtx1\n";
    mtx1.lock();
    cout << "Thread 1: locked mtx1\n";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Thread 1: Trying to lock mtx2\n";
    mtx2.lock();
    cout << "Thread 1: locked mtx2\n";

    mtx2.unlock();
    mtx1.unlock();
}

void deadlock_thread2() {
    cout << "Thread 2: Trying to lock mtx2\n";
    mtx2.lock();
    cout << "Thread 2: locked mtx2\n";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Thread 2: Trying to lock mtx1\n";
    mtx1.lock();
    cout << "Thread 2: locked mtx1\n";

    mtx1.unlock();
    mtx2.unlock();
}

// --- Example 3: Deadlock avoidance by locking in consistent order ---
void safe_thread1() {
    cout << "Safe Thread 1: Trying to lock mtx1\n";
    lock_guard<mutex> lock1(mtx1);  // Lock mtx1
    cout << "Safe Thread 1: locked mtx1\n";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Safe Thread 1: Trying to lock mtx2\n";
    lock_guard<mutex> lock2(mtx2);  // Lock mtx2
    cout << "Safe Thread 1: locked mtx2\n";

    // Automatically unlocks on scope exit
}

void safe_thread2() {
    cout << "Safe Thread 2: Trying to lock mtx1\n";
    lock_guard<mutex> lock1(mtx1);  // Lock mtx1 first (same order!)
    cout << "Safe Thread 2: locked mtx1\n";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Safe Thread 2: Trying to lock mtx2\n";
    lock_guard<mutex> lock2(mtx2);  // Then lock mtx2
    cout << "Safe Thread 2: locked mtx2\n";

    // Automatically unlocks on scope exit
}

int main() {
    // Part 1: Threads with arguments
    cout << "=== Part 1: Threads with arguments ===\n";
    thread t1(worker, "A", 2);
    thread t2(worker, "B", 3);
    t1.join();
    t2.join();

    // Part 2: Deadlock demonstration (will hang)
    cout << "\n=== Part 2: Deadlock demonstration ===\n";
    thread dt1(deadlock_thread1);
    thread dt2(deadlock_thread2);
    dt1.join();
    dt2.join();

    // NOTE: The program will likely hang here due to deadlock.  
    // To test Part 3, comment out Part 2 above.

    // Part 3: Deadlock avoidance
    cout << "\n=== Part 3: Deadlock avoidance ===\n";
    thread st1(safe_thread1);
    thread st2(safe_thread2);
    st1.join();
    st2.join();

    return 0;
}

