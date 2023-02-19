#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int arr[n][n];
int subtree[n];
// finding the subtree sum for all nodes 
void dfs(int vertex){
    //here the value of vertex is vertex ;
    // we can add diff value for it
    subtree[vertex]+=vertex;
    for(auto child:g[vertex]){
        if(child==vertex)continue;
        dfs(child);
        subtree[vertex]+=subtree[child];
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
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        dfs(x);
        // finding the subtree sum from the v
    }
  


        
}
