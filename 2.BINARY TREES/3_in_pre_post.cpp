// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}
// l n r 
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

}
// n l r 
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    inorder(root->left);
    inorder(root->right);

}
// l r n
void postorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data;

}
int main(){
    node * root=NULL;
    root=buildTree(root);
    inorder(root);

}