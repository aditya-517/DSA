#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* left; 
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data : ";
    int data; 
    cin>>data;

    root = new node(data);

    if(data == -1)
    return NULL;

    cout<<"Enter data to the left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data to the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);   // separator

    while(!q.empty()){
        node* temp = q.front();   
        q.pop();

        if(temp == NULL){
            // prev level is completed
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left != NULL)
            q.push(temp->left);

            if(temp->right != NULL)
            q.push(temp->right);
        }     
    }
}

// Inorder = L-N-R
void inorder(node* root){
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Preorder = N-L-R
void preorder(node* root){
    if(root == NULL)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder = L-R-N
void postorder(node* root){
    if(root == NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<< " :";
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left); 
        }

        cout<<"Enter right node for "<<temp->data<< " :";
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right); 
        }
    }
}
int main()
{ 
    node* root = NULL;

    //buildFromLevelOrder(root);
    
    // Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     
    cout<<"\nLevel Order Traversal\n";
    levelOrderTraversal(root);
    cout<<"\nIn Order Traversal\n";
    inorder(root);
    cout<<"\nPre Order Traversal\n";
    preorder(root);
    cout<<"\nPost Order Traversal\n";
    postorder(root);

    return 0;
} 
