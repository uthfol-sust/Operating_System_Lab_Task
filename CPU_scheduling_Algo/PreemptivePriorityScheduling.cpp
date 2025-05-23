#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, arrival, burst, priority;
    int remaining, completion, turnaround, waiting;
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
        p[i].remaining = p[i].burst;
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_priority = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].finished && p[i].priority < min_priority && p[i].remaining > 0) {
                min_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            current_time++;

            if (p[idx].remaining == 0) {
                p[idx].completion = current_time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                p[idx].finished = true;
                completed++;
            }
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
