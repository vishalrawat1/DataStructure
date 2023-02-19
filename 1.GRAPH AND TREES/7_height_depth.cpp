#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> g[n];
int arr[n][n];
int height[n];
int depth[n];

int dfs(int v , int p){
    for(auto child:g[v]){
        depth[v]+=depth[p]+1;
        if(child==p)continue;
        dfs(child,v);
        height[v]=max(height[v] , height[child]+1);
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
    cout<<depth[1];


        
}
