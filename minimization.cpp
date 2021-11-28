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
    for(int i=0;i<k;i++){
        for(it=symbols.begin();it!=symbols.end();it++){
            cout<<i<<" "<<*it<<" "<<transition[i][*it]<<endl;
        }
    }
    vector<vector<int> > partitions; 
    vector<int> rejects;
    for(int i=0;i<a;i++){
        if(reject[i]==0){
            rejects.push_back(i);
            part_no[i]=0;
        }
        else{
            part_no[i]=1;
        }
    }
    partitions.push_back(rejects);
    partitions.push_back(accept);
    vector<vector<int> > dup(partitions);

    vector<vector<int> >::iterator itr;
    int tk1,tk2;
    int npart=2;
    vector<int>::iterator jtr;
    while(1){
        for(int i=0;i<dup.size();i++){
            vector<int> new_part;
            for(int j=0;j<dup[i].size();j++){
                for(int k=j+1;k<dup[i].size();k++){
                    for(it=symbols.begin();it!=symbols.end();it++){
                        symbol=*it;tk1=partitions[i][j];tk2=partitions[i][k];
                        if(part_no[transition[tk1][symbol]] != part_no[transition[tk2][symbol]]){
                            new_part.push_back(partitions[i][k]);
                            part_no[tk2]=npart;
                            npart++;
                            partitions[i].erase(partitions[i].begin()+k);
                        }
                        break;
                    }
                }
            }
            if(new_part.size()!=0){
                partitions.push_back(new_part);
            }
        }
    }

}