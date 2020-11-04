#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &a, int i, int mid,int j)
{
    vector<int> temp(j-i+1);
    int k=i;
    int l=mid+1;
    int m=0;
    while(k<=mid && l<=j)
    {
        //cout<<"idhar";
        if(a[k]<=a[l])
        {
            temp[m]=a[k];
            m++;
            k++;
        }
        else if(a[k]>a[l])
        {
            temp[m]=a[l];
            m++;
            l++;
        }
    }

    while(k<=mid)
    {
        //cout<<"sahi";
        temp[m]=a[k];
        k++;
        m++;
    }

    while(l<=j)
    {
        //cout<<"galat";
        temp[m]=a[l];
        l++;
        m++;
    }
    //k=0;
    for(int z=i;z<=j;z++)
    {
        //cout<<"idhar to aa ja bc";
        a[z]=temp[z-i];
    }
}




void mergesort(vector<int> &a, int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        //cout<<"hello";
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        //cout<<low<<" "<<mid+1<<endl;

        merge(a,low,mid,high);
    }
}


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}