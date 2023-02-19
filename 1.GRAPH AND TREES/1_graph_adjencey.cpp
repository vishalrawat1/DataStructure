#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
int graph[n][n];
int main(){
    int n,m;
    // verteces , edges;
    cout<<"enter the no of vertices and edges"<<endl;
    cin>>n>>m;
    int graph[m+1][m+1];
// for unweighted graph 
    for(int i=0; i<m ; i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;

    }
// for weighted graph
    // for(int i=0; i<m ; i++){
    //     int x,y,wt;
    //     cin>>x>>y>>wt;
    //     graph[x][y]=wt;
    //     graph[y][x]=wt;

    // }
 
    

}