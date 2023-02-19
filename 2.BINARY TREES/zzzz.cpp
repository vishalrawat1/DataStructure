#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this -> val = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
  TreeNode* searchBST(TreeNode* root, int val) {
     int x=val;
        TreeNode* root1 = new TreeNode(NULL);
        if(root == NULL){
            return NULL;
        }
        if(root->val==x){
            root1=root;
        }
        searchBST(root->left , x);
        searchBST(root->right , x);
        root1->left=root->left;
        root1->right=root->right;

        return root1;


    }

TreeNode* buildTree(TreeNode* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}
int main(){
    TreeNode * root=NULL;
    root=buildTree(root);
  // 4 2 1 -1 -1 3 -1 -1 7 -1 -1
    TreeNode* root2 = new TreeNode(NULL);
    
    root2=searchBST(root , 2);
    printf("%d ",root2->left);

}