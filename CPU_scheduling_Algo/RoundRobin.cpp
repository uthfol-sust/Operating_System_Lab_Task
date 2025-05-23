#include<bits/stdc++.h>

using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst;
        processes[i].remaining = processes[i].burst;
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    queue<int> q;
    vector<bool> in_queue(n, false);

    int current_time = 0;
    int completed = 0;

    // Sort by arrival time initially
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    q.push(0);
    in_queue[0] = true;
    current_time = processes[0].arrival;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        Process &p = processes[idx];

        if (p.remaining > quantum) {
            current_time = max(current_time, p.arrival) + quantum;
            p.remaining -= quantum;
        } else {
            current_time = max(current_time, p.arrival) + p.remaining;
            p.remaining = 0;
            p.completion = current_time;
            p.turnaround = p.completion - p.arrival;
            p.waiting = p.turnaround - p.burst;
            completed++;
        }

        // Enqueue newly arrived processes
        for (int i = 0; i < n; i++) {
            if (i != idx && !in_queue[i] && processes[i].arrival <= current_time && processes[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        // Re-enqueue current process if it's not finished
        if (p.remaining > 0) {
            q.push(idx);
        }
    }

    // Output
    double total_wt = 0, total_tat = 0;

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.waiting << "\t" << p.turnaround << "\t\t" << p.completion << "\n";
        total_wt += p.waiting;
        total_tat += p.turnaround;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "Average Turnaround Time: " << total_tat / n << endl;

    return 0;
}
