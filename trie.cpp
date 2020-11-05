#include<bits/stdc++.h>
#define size 26
using namespace std;


class Trie{
    public:struct node
            {
                int isend;
                struct node *child[size];
            };
            struct node *root=NULL;

    public:
            void insert(string key)
            {
                if(root==NULL)
                {
                    struct node *newnode=(struct node*)malloc(sizeof(struct node));
                    newnode->isend=0;
                    for(int j=0;j<size;j++)
                    {
                        newnode->child[j]=NULL;
                    }
                    root=newnode;
                    //cout<<"idhar"<<endl;
                }
                inserthelper(root,key);
            }
            
            void inserthelper(struct node* root, string key)
            {
                struct node *temp=root;
                int s=key.length();
                int i=0;
                while(i<s)
                {
                    int tindx=key[i]-'a';
                    if(temp->child[tindx]==NULL)
                    {
                        struct node *newnode=(struct node*)malloc(sizeof(struct node));
                        newnode->isend=0;
                        for(int j=0;j<size;j++)
                        {
                            newnode->child[j]=NULL;
                        }
                        temp->child[tindx]=newnode;
                    }
                    temp=temp->child[tindx];
                    i++;
                }
                temp->isend=1;
            }

            
            int search(string key)
            {
                return searchhelper(root,key);
            }
            
            int searchhelper(struct node* root, string key)
            {
                if(root==NULL)
                    return 0;
                struct node* temp=root;
                int s=key.length();
                for(int i=0;i<s;i++)
                {
                    int indx=key[i]-'a';
                    temp=temp->child[indx];
                    if(temp==NULL)
                    {
                        return 0;
                    }  
                }
                return temp->isend;
            }
};


int main()
{
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" };
    Trie t;
    for (int i = 0; i < 8; i++)
    {
        cout<<"Hello"<<endl;
        t.insert(keys[i]);
    } 
    cout<<"outside for"<<endl;   
    int r1=t.search("the");
    cout<<r1<<endl;
}