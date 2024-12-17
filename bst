#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}

void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t",root->data);
    }
}

void preorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \t",root->data);
        inorder(root->right);

    }
}

int main()
{
    Node* root=NULL;
    int choice,value;
    while(1)
    {
        printf("\n 1. Inserting a node");
        printf("\n 2. postorder");
        printf("\n 3. preorder");
        printf("\n 4. inorder");
        printf("\n 5. Exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\n enter the data to be added");
                scanf("%d",&value);
                root=insert(root,value);
                break;
            case 2:postorder(root);
                break;
            case 3:preorder(root);
                break;
            case 4:inorder(root);
                break;
            case 5:exit(0);
                break;
            default:printf("\n Invalid Choice");
                break;
        }
    }
    return 0;
}
