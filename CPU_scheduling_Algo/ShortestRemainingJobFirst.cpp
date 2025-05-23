#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid,arrival,brust,remaining;
    int completion,turnaround,waiting;
};


int main(){
  int n;
  cout <<"Enter a number of process: ";
  cin >> n;

  vector<Process>processes(n);

  for(int i=0; i<n; i++){
    processes[i].pid = i+1;
    cout << "Enter process arrival and brust time: ";
    cin >> processes[i].arrival  >> processes[i].brust;

    processes[i].remaining = processes[i].brust;
  }

  int currentTime = 0, completed=0, min_rem = 1e9,shortest=-1;
  bool found = false;

  while(completed<n){
     shortest= -1;
     min_rem = 1e9;
     found = false;

     for(int i=0; i<n; i++){
        if((processes[i].arrival<=currentTime) && processes[i].remaining<min_rem && processes[i].remaining>0){
          shortest = i;
          min_rem = processes[i].remaining;
          found = true;
        }
     }

     if(found==false){
      currentTime++;
      continue;
     }

     processes[shortest].remaining--;
     currentTime++;

     if(processes[shortest].remaining==0)
     {
       completed++;
       processes[shortest].completion = currentTime;
       processes[shortest].turnaround= processes[shortest].completion - processes[shortest].arrival;
       processes[shortest].waiting = processes[shortest].turnaround -processes[shortest].brust;
     }
  }

    double total_wt = 0, total_tat = 0;

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.brust << "\t"
             << p.waiting << "\t" << p.turnaround << "\t\t" << p.completion << "\n";
        total_wt += p.waiting;
        total_tat += p.turnaround;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

}