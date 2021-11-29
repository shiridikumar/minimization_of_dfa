#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a;
    cin>>n>>k>>a;
    vector<int>accept;
    map<string ,int> transition[n];
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
    while(q.size()!=0){
        int s=q.front();
        reachable.push_back(s);
        cout<<s<<"****************"<<endl;
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
            cout<<i<<"--------------------"<<endl;
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
    cout<<"     ";
    for(int i=0;i<n;i++){
        cout<<i<<"  ";

    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"    ";
        for(int j=0;j<i;j++){
            cout<<table[i][j]<<"  ";
        }
        cout<<endl;
    }
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
    cout<<"     ";
    for(int i=0;i<n;i++){
        cout<<i<<"  ";

    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"    ";
        for(int j=0;j<i;j++){
            cout<<table[i][j]<<"  ";
        }
        cout<<endl;
    }
    vector <pair<int,int> > merge;
    vector<int> unmerged(n,0);
    int coun=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(table[i][j]!=1){
                unmerged[i]=1;
                unmerged[j]=1;
                merge.push_back(make_pair(i,j));
            }
        }
    }

    vector<vector<int> > states(n);
    int cur=0;
    int flag=0;
    int state_no[n];
    cout<<merge.size()<<endl;
    int seq[n];

    for(int i=0;i<merge.size();i++){
        flag=0;
        for(int j=0;j<states.size();j++){
            if(find(states[j].begin(), states[j].end(), merge[i].first) != states[j].end()){
                if(!(find(states[j].begin(), states[j].end(), merge[i].second) != states[j].end())){
                    states[j].push_back(merge[i].second);
                    state_no[merge[i].second]=seq[j];
                    state_no[merge[i].first]=seq[j];
                } 
                flag=1;
            }
            else if(find(states[j].begin(), states[j].end(), merge[i].second) != states[j].end()){
                if(!(find(states[j].begin(), states[j].end(), merge[i].first) != states[j].end())){
                    states[j].push_back(merge[i].first);
                    state_no[merge[i].second]=seq[j];
                    state_no[merge[i].first]=seq[j];
                }
                flag=1;
            }
        }
        if(flag==0){
            states[cur].push_back(merge[i].first);
            states[cur].push_back(merge[i].second);
            seq[cur]=merge[i].first;
            cur++;
        }
    }
    vector<int> new_states;
    for(int i=0;i<cur;i++){
        cout<<seq[i]<<" : ";
        for(int j=0;j<states[i].size();j++){
            cout<<states[i][j]<<" ";
        }
        cout<<endl;
        new_states.push_back(seq[i]);
    }
    cout<<cur<<endl;
    for(int i=0;i<n;i++){
        if(unmerged[i]==0){
            new_states.push_back(i);
        }
    }
    for(int i=0;i<new_states.size();i++){
        cout<<new_states[i]<<" ";
    }
    












    /*while(1){
        vector<vector<int> > prev(dup);
        int ind=0;
        while(ind!=dup.size()){
            cout<<dup[ind].size()<<"------************"<<endl;
            vector<int> new_part;
            vector<int> part(dup[ind]);
            vector<vector<int>::iterator> curr;
            vector<int> seen(reachable.size(),0);
            jtr=dup[ind].begin();
            while(jtr!=dup[ind].end()){
                ktr=jtr+1;
                //cout<<*jtr<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<endl;
                while(ktr!=dup[ind].end()){
                    //cout<<*ktr<<" !!!!!!!!!!!!!!!!!!"<<endl;
                    if(seen[*jtr]!=1 && seen[*ktr]!=1){
                      //  cout<<*jtr<<"              "<<*ktr<<endl;
                        for(it=symbols.begin();it!=symbols.end();it++){
                            cout<<*jtr<<" "<<*ktr<<" "<<*it<<":"<<part_no[transition[*jtr][*it]]<<","<<part_no[transition[*ktr][*it]]<<endl;
                            if(part_no[transition[*jtr][*it]]!=part_no[transition[*ktr][*it]]){
                                curr.push_back(ktr);
                                seen[*ktr]=1;
                                break;
                            }
                        }
                    }
                    ktr++;
                }
                for(int i=0;i<curr.size();i++){
                    new_part.push_back(*curr[i]);
                    part_no[*curr[i]]=npart;
                    dup[ind].erase(curr[i]);

                }
                curr.clear();
                cout<<"***********************************"<<endl;
                jtr++;
            }
            cout<<new_part.size()<<"------------------------"<<endl;
            if(new_part.size()!=0){
                npart++;
                vector<int> np(new_part);
                dup.push_back(np);
                new_part.clear();
            }
            ind++;
            cout<<(dup.size())<<"<<<<<<<<<<<<<<<<<<<<<"<<endl;
        }
        if(dup==prev){
            break;
        }
    }
    int states=0;
    cout<<endl;
    for(int i=0;i<dup.size();i++){
        if(dup[i].size()!=0){
            states++;
            cout<<"Partition "<<states<<": ";
            for(int j=0;j<dup[i].size();j++){
                cout<<dup[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"Total states: "<<states<<endl;*/
}