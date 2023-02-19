#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
const int inf=1e5+10;
vector<int> graph[n];
int arr[n][n];
vector<pair<int ,int>> g[n];
int par[n];
int vis[n];
int dist[n][n];
void make(int source){
    par[source]=source;
    vis[source];

}

int find(int source){
    if(source==par[source])return source;
    else{
        return find(par[source]);
    }

}

void Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        par[b]=a;
    }

}
int main(){
    // cout<<"enter no of vertces and edges"<<endl;
    int n , m;
    cin>>n>>m;
    vector<pair<int , pair<int,int>>> edge;
        // cout<<"for weighted graph"<<endl;
    for(int i=0 ; i<m ; i++){
        int v1 , v2 , wt;
        cin>>v1>>v2>>wt;
        edge.push_back({wt , {v1,v2}});

    }

    for(int i=0 ; i<m ; i++){
        make(i);
    }

    sort(edge.begin(),edge.end());
    int ts=0;

    for(auto child:edge){
        int wt = child.first
        int u=child.second.first;
        int v=child.second.second;

        if(find(u)==find(v))continue;
        Union(u,v);
        ts+=wt;
        
    }



}
        