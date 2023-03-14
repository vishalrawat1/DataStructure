#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    
    }

    //destructor;
    ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory  free of "<<val<<endl;
    }


};

void traverse(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
int getlength(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
    temp=temp->next;
    }
    return len;
}

void insertathead(Node* &head , int d){
    Node * temp = new Node(d);
    temp -> next = head;
    head->prev = temp;
    head = temp;
}

void insertattail(Node* &tail , int d){
    Node * temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
} 
int main(){
    Node* node1 = new Node(10);
    Node*head = node1;
    Node* tail = node1;
    insertathead(head  , 9);
    insertattail(tail , 11);
    traverse(head);
}
