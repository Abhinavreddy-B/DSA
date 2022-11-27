#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void dfs(vector<int> adj[],vector<bool> & vst,int pos){
    vst[pos]=true;
    for(auto i: adj[pos]){
        if(!vst[i]){
            dfs(adj,vst,i);
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> in[n];
    vector<int> out[n];
    vector<bool> vst(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        out[x].push_back(y);
        in[y].push_back(x);
    }
    bool flg=true;
    dfs(out,vst,0);
    for(int i=0;i<n;i++){
        if(!vst[i]){
            flg=false;
            break;
        }
    }
    if(!flg){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<n;i++) vst[i]=false;
    dfs(in,vst,0);
    for(int i=0;i<n;i++){
        if(!vst[i]){
            flg=false;
            break;
        }
    }
    if(flg){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}