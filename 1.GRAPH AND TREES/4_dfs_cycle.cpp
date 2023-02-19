#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int arr[n][n];
int vis[n];

bool dfscycle(int vertex , int parent){
    bool isloop=false;
    vis[vertex]=true;
    for(auto child:g[vertex]){
        if(child==parent && vis[child])continue;
        if(vis[child]) return true;
        isloop = (isloop || dfscycle(child , vertex));
    }
    return isloop;

}

int main(){
    int n , m;
    cin>>n>>m;
// unweighted grap
    for(int i=0 ; i<m ; i++){
        int v1 , v2;
        cin>>v1>>v2;
         
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }

    dfscycle(1,0);

        
}