#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int data;
    struct Node *left, *right;
};
 

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
   
    printPostorder(node->left);
 
    
    printPostorder(node->right);
 
    
    cout << node->data << " ";
}
 
