#include<iostream>
#include<vector>

class NumArray {
public:
    vector<int> seg;
    int N;
    void build(int idx,int l,int r,vector<int> &nums)
    {
        if(l==r)
        {
            seg[idx]=nums[l];return ;
        }
        int mid=l+(r-l)/2;
        build(2*idx+1,l,mid,nums);
        build(2*idx+2,mid+1,r,nums);
        
        seg[idx]=seg[2*idx+1] + seg[2*idx+2];
        
    }
    void upd(int idx,int pos,int l,int r,int val)
    {
        if(l==r)
        {
            seg[idx]=val; 
             // cout<<idx<<" "<<seg[idx]<<"\n";
            return ;
        }
        
         int mid=l+(r-l)/2;
        if(pos<=mid)
        upd(2*idx+1,pos,l,mid,val);
        else
        upd(2*idx+2,pos,mid+1,r,val);
        
        
        seg[idx]=seg[2*idx+1] + seg[2*idx+2];
       
    }
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        seg.resize(4*n+1);
        N=n;
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        upd(0,index,0,N-1,val);
        
    }
    
    int query(int idx,int l,int r,int left,int right)
    {
        if(l>right || r<left) return 0;
        
        if(left<=l && right>=r) return seg[idx];
        
        int mid=l+(r-l)/2;
        
        return query(2*idx+1,l,mid,left,right) + query(2*idx+2,mid+1,r,left,right);
        
        
    }
    
    
    int sumRange(int left, int right) {
        return query(0,0,N-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */