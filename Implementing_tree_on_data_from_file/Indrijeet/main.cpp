#include<iostream>
#include<fstream>

using namespace std;

struct node{
int val;
struct node *l;
struct node *r;
};

struct node* newNode(int k)
{
    struct node* nnode=new node();
    nnode->val=k;
    nnode->l=NULL;
    nnode->r=NULL;
    return nnode;
}

node * Bt(ifstream &inputFile)
    {
      int k,l,r;
      inputFile>>k>>l>>r;
      node * Node= newNode(k);
      if(inputFile.eof())
      return NULL;
      if(l==1)
      {
         Node->l= Bt(inputFile);
         }
      if(r==1)
      {
        Node->r= Bt(inputFile);
        }
      return Node;
    }

    void Inorder(node *root)
    {
     if(root==NULL)
     return;
     Inorder(root->l);
     cout<<root->val<<" ";
     Inorder(root->r);
    }

    void Preorder(node *root)
    {
     if(root==NULL)
     return;
     cout<<root->val<<" ";
     Inorder(root->l);
     Inorder(root->r);
    }

      void Postorder(node *root)
    {
     if(root==NULL)
     return;
     Inorder(root->l);
     Inorder(root->r);
     cout<<root->val<<" ";
    }

int main()
{
    ifstream inputFile;
    inputFile.open("ip.txt");

    if(!inputFile.is_open())
    {
        cout<<"Not working";
    }
    node *newNode= Bt(inputFile);
    cout<<"Inorder:-";
    Inorder(newNode);
    cout<<endl<<"Preorder:-";
    Preorder(newNode);
    cout<<endl<<"Postorder:-";
    Postorder(newNode);
    inputFile.close();
    
    return 0;
}
