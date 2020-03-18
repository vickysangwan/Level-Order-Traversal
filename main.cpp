#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    struct node* root;
    root=NULL;
    int size;
    cout<<"Enter size of tree"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        int data;
        cout<<"Enter data in node"<<endl;
        cin>>data;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else{
            struct node* curr,*ptr;
            curr=root;
            while(curr)
            {
                ptr=curr;
                if(temp->data > curr->data)
                {
                    curr=curr->right;
                }
                else
                {
                    curr=curr->left;
                }
            }
            if(temp->data > ptr->data)
            {
                ptr->right=temp;
            }
            else
            {
                ptr->left=temp;
            }
        }
    }
    return root;
}
void levelorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<struct node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        struct node* curr=Q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL)
        {
            Q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            Q.push(curr->right);
        }
        Q.pop();
    }
}
int main()
{
    struct node* root;
    root=create();
    levelorder(root);
    return 0;
}
