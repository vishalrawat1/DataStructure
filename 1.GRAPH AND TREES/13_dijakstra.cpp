#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
const int inf=1e5+10;
vector<pair<int ,int>> g[n];
//   node , wt
vector<int> vis(n,0);
vector<int> dist(n,inf);
void dijsktra(int source ){
    set<pair<int,int>> st;
    // wt , node 
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node = *st.begin();
        int d=node.first;
        int v=node.second;

        for(auto child:g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt < dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});

            }
        
        }
    }



}
int main(){
    int n;
    cin>>n;
    for(int i=0 ; i<n-1; i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g[v1].push_back({v2,wt});
        g[v2].push_back({v1,wt});
    }

}