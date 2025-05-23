#include<bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int burst;
    int arrival;
    int completion;
    int turnaround;
    int waiting;
    bool isCompleted;
};

int main(){
   int n;
   cout << "Enter Number of process: ";
   cin >> n;

   vector<Process> processes(n);

   for(int i=0; i<n; i++){
     processes[i].pid = i;
     cout<<"Enter arrival time and burst time of process "<<i<<": ";
     cin >> processes[i].arrival  >> processes[i].burst;
   }

   sort(processes.begin(),processes.end(), [](Process p1, Process p2){
     return p1.arrival < p2.arrival;
   });
    
   int cTime=0, idx=0;

   while(idx < n){
        cTime = max(cTime, processes[idx].arrival) + processes[idx].burst;
        processes[idx].completion = cTime;
        processes[idx].turnaround = processes[idx].completion - processes[idx].arrival;
        processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
        idx++;
   }

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

}