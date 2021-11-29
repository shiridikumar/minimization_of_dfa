#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a;
    cin>>n>>k>>a;
    vector<int>accept;
    map<string,int> transition[n];
    set<string> symbols;
    int part_no[n];
    int temp;
    int reject[n];
    for(int i=0;i<n;i++){
        reject[i]=0;
    }
    for(int i=0;i<a;i++){
        cin>>temp;
        reject[temp]=1;
        accept.push_back(temp);
    }
    int start,end;
    string symbol;
    for(int i=0;i<k;i++){
        cin>>start>>symbol>>end;
        transition[start][symbol]=end;
        symbols.insert(symbol);
    }
    set<string>::iterator it;


    //******************************** For removing non reachable states********************************
    vector<int> visited(n,0);
    queue<int> q;
    q.push(0);
    visited[0]=1;
    vector<int> reachable;
    vector<int> reach(n,0);
    while(q.size()!=0){
        int s=q.front();
        reachable.push_back(s);
        reach[s]=1;
        //cout<<s<<"****************"<<endl;
        q.pop();
        for(it=symbols.begin();it!=symbols.end();it++){
            if(visited[transition[s][*it]]!=1){
                visited[transition[s][*it]]=1;
                q.push(transition[s][*it]);
            }
        }
    }

    vector<vector<int> > partitions; 
    vector<int> rejects;
    for(int i=0;i<reachable.size();i++){
        if(reject[reachable[i]]==0){
            rejects.push_back(reachable[i]);
           // cout<<i<<"--------------------"<<endl;
            part_no[reachable[i]]=0;
        }
        else{
            part_no[reachable[i]]=1;
        }
    }
    partitions.push_back(rejects);
    partitions.push_back(accept);
    vector<vector<int> > dup(partitions);

    vector<vector<int> >::iterator itr;
    int npart=2;
    vector<int>::iterator jtr;
    vector<int>::iterator ktr;
    //cout<<"  "<<partitions[0].size()<<"  "<<partitions[1].size()<<endl;
    int i=0;
    int table[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(part_no[i]!=part_no[j]){
                table[i][j]=1;
                table[j][i]=1;
            }
            else{
                table[i][j]=0;
                table[j][i]=0;
            }
        }
    }
    int tk1,tk2;
    int marks=0;
   

    while(1){
        marks=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(table[i][j]!=1){
                    for(it=symbols.begin();it!=symbols.end();it++){
                        tk1=transition[i][*it];tk2=transition[j][*it];
                        if(table[tk1][tk2]==1){
                            table[i][j]=1;marks=1;
                            table[j][i]=1;
                            break;
                        }
                    }
                }
            }
        }
        if(marks!=1){
            break;
        }
    }
    /*cout<<"     ";
    for(int i=0;i<n;i++){
        cout<<i<<"  ";

    }*/
    //cout<<endl;
    
    vector <pair<int,int> > merge;
    vector<int> unmerged(n,0);
    int coun=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(table[i][j]!=1){
                unmerged[i]=1;
                unmerged[j]=1;
                if(reach[i]==1 && reach[j]==1){
                    merge.push_back(make_pair(i,j));
                }
                else if(reach[i]==1){
                    merge.push_back(make_pair(i,i));
                }
                else if(reach[j]==1){
                    merge.push_back(make_pair(j,j));
                }
            }
        }
    }


    vector<vector<int> > states(n);
    int cur=0;
    int flag=0;
    int state_no[n];
    int seq[n];
    int sequence[n];
    for(int i=0;i<merge.size();i++){
        flag=0;
        for(int j=0;j<states.size();j++){
            if(find(states[j].begin(), states[j].end(), merge[i].first) != states[j].end()){
                if(!(find(states[j].begin(), states[j].end(), merge[i].second) != states[j].end())){
                    states[j].push_back(merge[i].second);
                    seq[merge[i].second]=sequence[j];
                    seq[merge[i].first]=sequence[j];
                } 
                flag=1;
            }
            else if(find(states[j].begin(), states[j].end(), merge[i].second) != states[j].end()){
                if(!(find(states[j].begin(), states[j].end(), merge[i].first) != states[j].end())){
                    states[j].push_back(merge[i].first);
                    seq[merge[i].second]=sequence[j];
                    seq[merge[i].first]=sequence[j];
                }
                flag=1;
            }
        }
        if(flag==0){
            states[cur].push_back(merge[i].first);
            if(merge[i].first!=merge[i].second){
                states[cur].push_back(merge[i].second);
            }
            //cout<<merge[i].first<<"___________________________________"<<merge[i].second<<"          "<<cur<<endl;
            sequence[cur]=merge[i].first;
            seq[merge[i].first]=sequence[cur];seq[merge[i].second]=sequence[cur];
            cur++;
        }
    }
    vector<int> new_states;
    for(int i=0;i<cur;i++){
        for(int j=0;j<states[i].size();j++){
        }
        new_states.push_back(sequence[i]);
    }
    for(int i=0;i<n;i++){
        if(unmerged[i]==0){
            seq[i]=i;
            new_states.push_back(i);
        }
    }
    int encoding[n];
    int pointer=0;
    for(int i=0;i<new_states.size();i++){
        encoding[new_states[i]]=pointer;
        pointer++;
    }
    map<string ,int> new_t[n];
    vector<int> new_acc;
    for(int i=0;i<accept.size();i++){
        if(!(find(new_acc.begin(), new_acc.end(), encoding[seq[accept[i]]]) != new_acc.end())){
            new_acc.push_back(encoding[seq[accept[i]]]);
        }
    }
    cout<<new_states.size()<<" "<<new_states.size()*symbols.size()<<" "<<new_acc.size();
    cout<<endl;
    for(int i=0;i<new_acc.size();i++){
        cout<<new_acc[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<new_states.size();i++){
        for(it=symbols.begin();it!=symbols.end();it++){
            new_t[new_states[i]][*it]=sequence[transition[new_states[i]][*it]];
            cout<<encoding[seq[new_states[i]]]<<" "<<*it<<" "<<encoding[seq[transition[new_states[i]][*it]]]<<endl;
        }
    }
}