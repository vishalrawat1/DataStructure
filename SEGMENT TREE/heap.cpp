#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size =0;

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index]=val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1 ; i<=size ; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletenode(){
        if(size==0){
            cout<<"nothing to del"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftind = 2*i;
            int rightind = 2*i+1;
            if(leftind <= size && arr[i]<arr[leftind] && arr[leftind] > arr[rightind] ){
                swap(arr[i],arr[leftind]);
                i=leftind;
            }else if(rightind <= size && arr[i]<arr[rightind] && arr[rightind]>arr[leftind]){
                swap(arr[i], arr[rightind]);
                i=rightind;
            }else{
                return;
            }
        }
    }


};
 void heapify(int arr[] , int n ,int i){
        int largest =i;
        int left= 2*i;
        int right = 2*i+1;
        if(left < n && arr[largest] < arr[left]){
            largest=left;

        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr , n , largest);
        }
    }
void heapsort(int arr[] , int n , int i){
    int size =  n;
    while(n--){
        swap(arr[size],arr[n]);
        size--;

        heapify(arr , size, i);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(90);
    h.insert(100);
    h.print();
    h.deletenode();
    int arr[6]={-1 , 54 , 53 , 55 , 532 , 50};
    int n=5;
    for(int i=n/2;i>0; i--){
        heapify(arr , n ,i);
    }
    return 0;
}