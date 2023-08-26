#include<iostream>

using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node * right;
    int height;
};

int getHeight(struct Node *n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a>b)? a : b;
}

struct Node *createNode(int key)
{
    struct Node * node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node * rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
};

struct Node * leftRotate(struct Node* x)
{
    struct Node* y =x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
};

int getBalanceFactor(struct  Node *n)
{
   if(n==NULL)
   return 0;
   return getHeight(n->left) - getHeight(n->right);
};

struct Node* insert(struct Node* node, int key)
{
    if(node == NULL)
    return(createNode(key));

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
    return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    //left left case
    if(bf > 1 && key < node->left->key)
        return rightRotate(node);
    //right right case
    if(bf < -1 && key > node->right->key)
        return leftRotate(node);
    //left right case
    if(bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right left case
    if(bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node* root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    
    int n;
    cout<<"Enter the number of student data to be entered:";
    cin>>n;
    for(int i = 0; i<n; i++)
    {
       int value;
       cout<<"Enter the value to be entered into the node:";
       cin>>value;
       root = insert(root, value);
       cout<<"Height="<<root->height<<endl;
    }

    cout<<"Preorder traversal of the constructed AVL tree is=";
    preOrder(root);
    
    return 0;
}