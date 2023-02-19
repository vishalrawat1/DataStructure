#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
const int inf=1e5+10;
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
// path compression
int pc_find(int source){
    if(source==par[source])return source;
    else{
        par[source]=find(par[source]);
    }

}
//Union by size
void Unionbysize(int a, int b){
    a=pc_find(a);
    b=pc_find(b);

    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        par[b]=a;
        size[a]+=size[b];
    }

}

int main(){
    int n;
    cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        int v1 , v2 ,wt;
        cin>>v1>>v2>>wt; 
        g[v1].push_back({v2,wt});
        g[v2].push_back({v1,wt});

    }


    


}