#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int val[n];
int subtree[n];
// finding the subtree sum for all nodes 
void dfs(int vertex , int parent){
    //here the value of vertex is vertex ;
    // we can add diff value for it
    subtree[vertex]+=val[vertex];
    for(auto child:g[vertex]){
        if(child==parent)continue;
        dfs(child , vertex);
        subtree[vertex]+=subtree[child]+1;
    
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


        
}
