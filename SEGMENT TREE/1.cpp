#include<iostream>
using namespace std;

int a[100005] , seg[4*100005] , lazy[4*100005];

void buildsegmenttree(int ind , int start , int end){
    if(start==end){
        seg[ind]+=a[ind];
        return;
    }
    int mid = (start+end)/2;
    buildsegmenttree(2*ind+1 , start ,mid);
    buildsegmenttree(2*ind+2 , mid+1 , end);
    seg[ind]=max(seg[2*ind+1], seg[2*ind+2]);

}

int query(int ind , int start , int end, int left , int right){
    //completely lies , not lies , partiely
    if(start<=left && end >=right){
        return seg[ind];
    }

    if(end<right || start>end)return INT_MIN;

    int mid=(start+end)/2;
    int leftsum = query(2*ind+1 ,start , mid , left , right);
    int rightsum = query(2*ind+2 , mid+1 , end , left , right);
    return max(leftsum , rightsum);
}


//  ------------------------------------------------------------------------part 2 ------------------------------------------------------------------- pointupdate(to update value at a given index) ,(these are the advance version) range sum , lazy propogation
int pointupdate(int ind , int start , int end , int node, int val){
    if(start==end){
        seg[node]+=val;
    }
    else{
        int mid=(start+end)/2;
        if(node<=mid && node>=start){
            pointupdate(2*ind+1 , start , mid , node , val);
        }else{
            pointupdate(2*ind +2 , mid+1 , end , node , val);
        }
        seg[ind] = seg[2*ind+1]+ seg[2*ind+2];
    }
}

void rangeupdate(int ind , int low  , int high , int l , int r , int val){
    if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            seg[2*ind+1]+=lazy[ind];
            seg[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    // out of the idx
    if(l<low || r >high || low>high)return;
    //completely insde
    if(low>=l && high<=r){
        seg[ind]+=(high-low+1)*val;
        if(low!=high){
            seg[2*ind+1]+=lazy[ind];
            seg[2*ind+2]+=lazy[ind];
        }
        return;
    }

    int mid=(high+low)/2;
    rangeupdate(2*ind+1 , low , mid , l , r , val);
    rangeupdate(2*ind+2 , mid+1 , high , l , r , val);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];

    
}

void queryupdate(int ind , int low  , int high ,  int l , int r, int val){
    if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            seg[2*ind+1] +=lazy[ind];
            seg[2*ind+2] +=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l<low || r >high || low>high)return;
    //completely insde
    if(low>=l && high<=r){
        return seg[ind];
    }

    int mid=(high+low)/2;
    return queryupdate(2*ind+1 , low , mid , l , r , val) + queryupdate(2*ind+2 , mid+1 , high , l , r , val);
    

}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }

    buildsegmenttree(0 , 0 , n-1);

    int q;
    cin>>q;
    while(q--){
        int l , r;
        cin>>l>>r;
        cout<<query(0 , 0 , n-1 , l , r);
    }
}