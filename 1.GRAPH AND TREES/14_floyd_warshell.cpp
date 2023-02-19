#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
const int inf=1e5+10;
vector<pair<int ,int>> g[n];
int dist[n][n];
int main(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)dist[i][j]=0;
            dist[i][j]=inf;
        }
        
    }


    int n;
    cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        int v1 , v2 ,wt;
        cin>>v1>>v2>>wt; 
        g[v1].push_back({v2,wt});
        g[v2].push_back({v1,wt});

    }

    //floyd warshell;
    for(int k=0 ; k<n ; k++){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j]=min(dist[i][j] , dist[i][k]+dist[k][j]);
            }
            
        }
        
    }

    //print

     for(int k=0 ; k<n ; k++){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][j]==inf){
                    cout<<"I";
                }
                else{
                    cout<<dist[i][j];
                }
            }
            
        }
        
    }


  
    
    


}