#include<bits/stdc++.h>
using namespace std;
const int n=1e5+10;
vector<int> g[n];
int par[n];

void dfs(int vertex , int parent){
    par[vertex]=parent;
    for(auto child:g[vertex]){
        if(child==parent)continue;
        dfs(child , vertex);
    }
}

vector<int> path(int x){
    vector<int> ans;
    while(x!=-1){
        ans.push_back(x);
        x=par[x];
    }
    reverse(ans.begin() , ans.end());
    return ans;

}

int main(){
    int n;
    cin>>n;

    for(int i=1 ; i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1,0);
    cout<<"enter the value of the lca to find off"<<endl;
    int x,y;
    cin>>x>>y;
    vector<int> path_a=path(x);
    vector<int> path_b=path(y);

    int size=min(path_a.size() , path_b.size());
    int lca=-1;

    for (int i = 0; i < size; i++)
    {
        if(path_a[i]==path_b[i]){
            lca=path_a[i];
        }
        else{
            break;
        }
    }
    cout<<lca;
    

    



}