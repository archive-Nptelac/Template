/* First come first serve (FCFS) */
#include<bits/stdc++.h>
using namespace std;

struct Process{
    int id,AT,BT,ST,CT,TAT,WT,RT;
};

int main(){
    vector<Process>v;
    // Total number of process
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int pid,at,bt;
        cin >> pid >> at >> bt;
        Process p;
        p.id=pid;p.AT=at;p.BT=bt;
        v.push_back(p);
    }
    
    // Sort them with respect to their arrival time;
    sort(v.begin(),v.end(),[](Process p1,Process p2){
        if(p1.AT==p2.AT)    return (p1.id<p2.id);
        return (p1.AT<p2.AT);
    });
    
    // Calculate all the entities of a process
    for(int i=0;i<n;i++){
        Process &p=v[i];
        p.ST=(i==0)?p.AT:max(v[i-1].CT,p.AT);
        p.CT=p.ST+p.BT;
        p.TAT=p.CT-p.AT;
        p.WT=p.TAT-p.BT;
        p.RT=p.ST-p.AT;
    }
    
    // calculate all average values
    
    double avgTAT=0,avgWT=0,avgRT=0;
    for(int i=0;i<n;i++){
        avgTAT+=v[i].TAT;
        avgWT+=v[i].WT;
        avgRT+=v[i].RT;
    }
    avgTAT/=n;avgWT/=n;avgRT/=n;
    
    sort(v.begin(),v.end(),[](Process p1,Process p2){
        return p1.id<p2.id;
    });
    
    for(Process p:v){
        cout << p.id << " " << p.AT << " " << p.BT << " " << p.ST << " " << p.CT << " " << p.TAT << " " << p.WT << " " << p.RT << endl;
    }
    
    cout << fixed << setprecision(3);
    cout << "Average TAT=" << avgTAT << endl;
    cout << "Average WT= " << avgWT << endl;
    cout << "Average RT= " << avgRT << endl;
    
    
    return 0;
}
/*UJJWAL KESHRI */
/*
    AT -> Arrival Time
    BT -> Burst Time
    ST -> Start Time            = max(previous completion time, current arrival time)
    CT -> Completion Time       = ST + BT
    TAT -> Turn Around Time     = CT - AT
    WT -> Waiting Time          = TAT - BT
    RT -> Response Time         = ST - AT
*/
