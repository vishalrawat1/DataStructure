#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int> graph[n];
int arr[n][n];
vector<pair<int , int>> graph2[n];
int main(){
    cout<<"enter no of vertces and edges"<<endl;
    int n , m;
    cin>>n>>m;
// unweighted graph
        cout<<"for unwighted graph"<<endl;
    for(int i=0 ; i<m ; i++){
        int v1 , v2;
        cin>>v1>>v2;
         
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }
//  for weighted
        cout<<"for weighted graph"<<endl;
    for(int i=0 ; i<m ; i++){
        int v1 , v2 , wt;
        cin>>v1>>v2>>wt;

        graph2[v1].push_back({v2 ,wt});
        graph2[v2].push_back({v1,wt});

    }
        
}