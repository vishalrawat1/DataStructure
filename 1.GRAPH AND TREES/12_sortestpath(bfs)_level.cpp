#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int level[n];
int vis[n];
void dfs(int vertex){
    //here the value of vertex is vertex ;
    // we can add diff value for it
    queue<int> q;
    q.push(vertex);
    vis[vertex]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto child:g[vertex]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur]+1;

            }
        }

    }



}
int main(){
    // cout<<"enter no of vertces and edges"<<endl;
    int n;
    cin>>n;
// unweighted graph
        // cout<<"for unwighted graph"<<endl;
    for(int i=0 ; i<n-1 ; i++){
        int v1 , v2;
        cin>>v1>>v2;
         
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
  


        
}
