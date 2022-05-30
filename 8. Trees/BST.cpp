#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* left; 
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // separator

    while(!q.empty()){
        Node* temp = q.front();   
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

Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL)
    temp = temp->left;

    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL)
    temp = temp->right;

    return temp;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL)
    return root;

    if(root->data == val){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left && root->right){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        // left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        // right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
 
Node* insertInBST(Node* root, int d){
    // base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if(d > root->data)
    root->right = insertInBST(root->right, d);

    else
    root->left = insertInBST(root->left, d);
    

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

int main()
{ 
    Node* root = NULL;
    // 10 8 21 7 27 5 4 3 -1
    cout<<"Enter data for BST : ";
    takeInput(root);
    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);

    deleteFromBST(root, 7);

    cout<<"Printing BST : "<<endl;
    levelOrderTraversal(root);
    return 0;
}