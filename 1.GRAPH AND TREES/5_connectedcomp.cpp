#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
int g[n][n];
// vector<int> g[n];
int arr[n][n];
int vis[n];

void dfs(int v){
    vis[v]=1;
    for(auto child:g[v]){
        if(vis[child])continue;
        dfs(child);
    }
}


int main(){
    int n , m;
    cin>>n>>m;
// unweighted grap
    for(int i=0 ; i<m ; i++){
        int v1 , v2;
        cin>>v1>>v2;
        g[v1][v2]=1;
        g[v2][v1]=1;

    }
    dfs(1);
    int cc=0;
    for(int i=0 ; i<m ; i++){
        if(vis[i])continue;
        dfs(i);
        cc++;


    }
    cout<<cc;
    

   
        
}