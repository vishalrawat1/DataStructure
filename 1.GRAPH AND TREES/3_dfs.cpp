#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> graph[n];
int arr[n][n];
int vis[n];
void dfs(int vertex){
    cout<<"traversed values == ";
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(auto child:graph[vertex]){
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
         
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }

    dfs(1);

        
}