#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
    bool finished = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst >> p[i].priority;
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_priority = 1e9;

        for (int i = 0; i < n; i++) {
            if (!p[i].finished && p[i].arrival <= current_time) {
                if (p[i].priority < min_priority || 
                   (p[i].priority == min_priority && p[i].arrival < p[idx].arrival)) {
                    min_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            current_time = max(current_time, p[idx].arrival) + p[idx].burst;
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].finished = true;
            completed++;
        } else {
            current_time++;
        }
    }

    double total_wait = 0, total_turnaround = 0;

    cout << "\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\tCompletion\n";
    for (auto &proc : p) {
        cout << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t" << proc.priority
             << "\t\t" << proc.waiting << "\t" << proc.turnaround << "\t\t" << proc.completion << "\n";
        total_wait += proc.waiting;
        total_turnaround += proc.turnaround;
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";

    return 0;
}
