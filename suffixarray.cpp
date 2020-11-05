#include<bits/stdc++.h>
using namespace std;

class suffixarray
{
    public: 
    struct suffixnode
    {
        int index;
        string st;
        int rank;
        int nextindexrank;
    };
    string ip;
    static int n;
    

    public:
    /*suffixarray(string t, int n1)
    {
        ip=t;
        n=n1;
    }*/
    vector<int> constructsuffixarray(string ip, int n)
    {
        struct suffixnode allsuffix[n];
        int newindex[n];
        vector<int> res(n);

        //sarre suffix ke liye struct me value dalwa do
        for(int i=0;i<n;i++)
        {
            allsuffix[i].index=i;
            allsuffix[i].st=ip.substr(i);
            allsuffix[i].rank=(ip[i]-'a');
            if(n<=(i+1))
            {
                allsuffix[i].nextindexrank=-1;
            }
            else if(n>(i+1))
            {
                allsuffix[i].nextindexrank=(ip[i+1]-'a');
            }
        }

        sort(allsuffix,allsuffix+n,comparator);
        for(int i=4;i<2*n;i*=2)
        {
            int k=allsuffix[0].index;
            newindex[k]=0;
            int prev=allsuffix[0].rank;
            int r=0;
            allsuffix[0].rank=r;
            for(int j=1;j<n;j++)
            {
                if(allsuffix[j].rank==prev)
                {
                    //rank same to wahi assign kr diya
                    if(allsuffix[j-1].nextindexrank==allsuffix[j].nextindexrank)
                    {
                        prev=allsuffix[j].rank;
                        allsuffix[j].rank=r;
                    }
                    else
                    {
                        //wrna increment kr do rank ko
                        r++;
                        prev=allsuffix[j].rank;
                        allsuffix[j].rank=r;
                    } 
                }
                else
                {
                    r++;
                    prev=allsuffix[j].rank;
                    allsuffix[j].rank=r;
                }
                k=allsuffix[j].index;
                newindex[k]=j;
            }
            for(int j=0;j<n;j++)
            {
                //struct suffixnode *temp=allsuffix[j];
                int z=allsuffix[j].index;
                int next=z+i/2;
                if(n<=next)
                {
                    allsuffix[j].nextindexrank=-1;
                }
                else
                {
                    int t=newindex[next];
                    allsuffix[j].nextindexrank=allsuffix[t].rank;
                } 
            }
            sort(allsuffix,allsuffix+n,comparator);
        }

        for(int i=0;i<n;i++)
        {
            res[i]=allsuffix[i].index;
        }
        return res;
    }

    static bool comparator(struct suffixnode a1, struct suffixnode a2)
    {
        if(a1.rank==a2.rank)
        {
            return a1.nextindexrank<a2.nextindexrank;
        }
        return a1.rank<a2.rank;
    }
     
};

int main()
{
    string x="dcabca";
    suffixarray sa;
    vector<int> sarray=sa.constructsuffixarray(x,6);
    for(int i=0;i<6;i++)
    {
        cout<<sarray[i]<<" ";
    }
    cout<<endl;
}