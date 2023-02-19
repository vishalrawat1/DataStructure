#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int arr[n][n];
void dfs(int v , int p){
    cout<<v<<" ";
    for(auto child:g[v]){
        if(child==p)continue;
        dfs(child,v);
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
    cout<<"traveresed values ";


        
}
