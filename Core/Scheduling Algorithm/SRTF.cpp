/* Shortest Remaining Time First (SRTF) */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll max(ll a,ll b){ return (a>b)?a:b; }
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
    
    // Sort according to their arrival time;
    sort(v.begin(),v.end(),[](Process p1,Process p2){
        return (p1.AT<p2.AT);
    });
    
    // Just copy required info in another variable for simplicity;
    pair<int,pair<int,int> >ps[n]; // {AT,{BT,ID} }
    for(int i=0;i<n;i++){
        ps[i]={v[i].AT,{v[i].BT,v[i].id}};
    }
    
    // will store information of each id their start and completion time;
    vector<pair<int,pair<int,int> > >v2; // {ID,{ST,CT} }
    
    // Will select the process having smallest burst time;
    priority_queue<pair<int,pair<int,int> > >pq;    // {-BT,{-ID,AT} }
    ll cur_time=0,i=0;
    
    int tmpST[n];
    memset(tmpST,-1,sizeof(tmpST));
    
    while(i<n || !pq.empty()){
        if(i<n && pq.empty()){
            cur_time=max(cur_time,ps[i].first);
        }
        while(i<n && ps[i].first<=cur_time){
            pq.push({-ps[i].second.first,{-ps[i].second.second,ps[i].first}});
            i++;
        }
        auto p=pq.top();
        pq.pop();
        int bt=-p.first;
        int id=-p.second.first;
        int at=p.second.second;
        if(tmpST[id-1]==-1){
            tmpST[id-1]=cur_time;
        }
        if(bt==1){
            int ct=max(cur_time+bt,at+bt);
            v2.push_back({id,{cur_time,ct}});
            cur_time=ct;
        }
        else{
            bt--;
            cur_time++;
            pq.push({-bt,{-id,at}});
        }
    }
    
    // now sort them again with respect to their id;
    sort(v.begin(),v.end(),[](Process p1,Process p2){
        return (p1.id<p2.id);
    });
    
    for(int i=0;i<n;i++){
        int id=v2[i].first;
        id--;
        int st=tmpST[id];
        int ct=v2[i].second.second;
        v[id].ST=st;
        v[id].CT=ct;
        v[id].TAT=ct-v[id].AT;
        v[id].WT=v[id].TAT-v[id].BT;
        v[id].RT=v[id].ST-v[id].AT;
    }
    for(int i=0;i<n;i++){
        Process &p=v[i];
        cout << "P" << p.id << " " << p.AT << " " << p.BT << " " << p.ST << " " << p.CT << " " << p.TAT << " " << p.WT << " " << p.RT << endl;
    }
    
    
    
    return 0;
}
/*
    AT -> Arrival Time
    BT -> Burst Time
    ST -> Start Time            = max(previous completion time, current arrival time)
    CT -> Completion Time       = ST + BT
    TAT -> Turn Around Time     = CT - AT
    WT -> Waiting Time          = TAT - BT
    RT -> Response Time         = ST - AT
*/
