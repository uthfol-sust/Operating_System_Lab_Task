#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid,arrival,brust;
    int completion,turnaround,waiting;
    bool done;
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

    processes[i].done = false;
  }
   
  int idx =-1, completed=0,currenTime=0,min_burst=INT_MAX;
  while(completed<n){
    idx = -1;
    min_burst = INT_MAX;

    for(int i=0; i<n; i++){
        if(processes[i].done==false &&processes[i].arrival<=currenTime && processes[i].brust<min_burst ){
            idx = i;
            min_burst = processes[i].brust;
        }
    }

    if(idx!=-1){
      currenTime = currenTime +  processes[idx].brust;
      processes[idx].completion = currenTime;
      processes[idx].turnaround =  processes[idx].completion -  processes[idx].arrival;
      processes[idx].waiting =  processes[idx].turnaround -  processes[idx].brust; 

       processes[idx].done = true;
       completed++;
    }
    else{
        currenTime++;
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