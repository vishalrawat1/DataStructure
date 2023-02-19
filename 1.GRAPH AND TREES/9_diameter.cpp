#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int arr[n][n];
int depth[n];
// finding the subtree sum for all nodes 
void dfs(int vertex , int par){
    //here the value of vertex is vertex ;
    // we can add diff value for it
    for(auto child:g[vertex]){
        if(child==par)continue;
        depth[child]=depth[par]+1;
        dfs(child , vertex);
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
    
    dfs(1,0);
    int max_depth=-1;
    int node;
    for(int i=0 ; i<n ; i++){
        if(max_depth<depth[i]);
        max_depth=depth[i];
        node=i;
    }

    dfs(node , 0);
    for(int i=0 ; i<n ; i++){
        if(max_depth<depth[i]);
        max_depth=depth[i];

    }
  


        
}
