#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
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

void insertathead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next=head;
    head = temp;
}

void insertattail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp=tail;
}

void traverse(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void insertatposition(Node* &tail ,Node* &head, int position , int d){
    if(position==1){
        insertathead(head , d);
        return;
    }
    Node* temp = head;
    int cn=1;
    while(cn<position-1){
        temp=temp->next;
        cn++;
    }
    if(temp->next==NULL){
        insertattail(tail , d);
    }
    Node* temp1 = new Node(d);
    temp1->next = temp->next;
    temp->next=temp1;

}

void deletion(int pos , Node* &head){
    if(pos == 1){
        Node* temp= head;
        head = head ->next;
        temp->next=NULL;
        delete temp;

    }
    Node * curr = head;
    Node * prev = NULL;
    int ct=1;
    while(ct < pos-1){
        prev = curr;
        curr = curr->next;
        ct++;
    }
    prev->next = curr ->next;
    curr->next=NULL;
    delete curr;
    

}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertathead(head , 9);
    insertathead(head , 8);
    insertathead(head , 7);
    insertattail(tail , 6);
    
    insertathead(tail , 5);

    insertatposition(tail , head , 3 , 2 );
    traverse(head);
    deletion(3 , head);
    traverse(head);



}