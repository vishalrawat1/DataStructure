#include<iostream>
#define INT_MIN
using namespace std;
int a[100005] , seg[4*100005] , lazy[4*10005];

void build(int ind , int low , int high){
    if(low==high){
        seg[ind]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1 , low , mid);
    build(2*ind+1 , mid+1 , high);
    seg[ind]=max(seg[2*ind+1]  , seg[2*ind+2]);
}

int query(int ind , int low , int high  ,  int l , int r){
    if(low>=l && high<=r){
        return seg[ind];
        //the query completely lies inside the range;
    }
    // node doesnt lies inside the range
    if(high<l || low>r)return INT_MIN;
    // it overlaps in the range;
    // some on left , some on right;
    int mid=(low+high)/2;
    int left=query(2*ind+1 , low , mid , l , r);
    int right = query(2*ind+2 , mid +1 , high , l , r);
    return max(left , right);
    

}
// point update lazy propogation 
//tc = log(n);
// worst time  =  nlogn > brute force

void pointupdate(int ind , int low , int high , int node , int val){
    if(low==high){
        seg[ind]+=val;
    }
    else{

    int mid=(low+high)/2;
    if(node<=mid && node>=low){
        pointupdate(2*ind+1 , low , mid , node , val);
    }else{
        pointupdate(2*ind+2 , mid+1 , high , node , val);
    }
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    
}

//to overcome this lazy update or propogation update comes in
//suspend update for moment and do it in future
void rangeupdate(int ind , int high , int low , int l , int r , int val){
    // check for the dummy updateion of the node 
    
    if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
// if the range completely outside of the nodes 
    if(r<low || l>high || low>high)return;
// if range is completely inside of the nodes;
    if(low>=l && high<=r){
        seg[ind]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        return;
    }
    int mid=(low+high)>>1;
    rangeupdate(2*ind+1 , low , mid , l ,r , val);
    rangeupdate(2*ind+2 , mid+1 , high , l ,r , val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int querysum(int ind ,int low , int high , int l , int r ,int val){
    if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(r<low||l>high || low>high)return 0;
    if(low>=l && high<=r){
        return seg[ind];
    }
    int mid=(low+high)>>1;
    return querysum(2*ind+1 , low , mid , l , r , val)+querysum(2*ind+2 , mid+1 , high , l , r , val);

    
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }
    build(0 ,0, n-1);
    int q;
    cin>>q;
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<query(0,0,n-1 , l , r);
    }
}