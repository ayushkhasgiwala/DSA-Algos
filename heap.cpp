#include<bits/stdc++.h>
using namespace std;


class HeapSort
{
    public:
        long long int capacity;
        long long int size;
        long long int *heap;

    public:
        //constructor
        HeapSort(long long int c)
        {
            capacity=c;
            size=0;
            heap=(long long int*)malloc(c*sizeof(long long int));
        }

        //to get the index of the parent
        long long int parent(long long int index)
        {
            return (index-1)/2;
        }
        
        //to get the index of the left child
        long long int leftchild(long long int index)
        {
            return ((2*index)+1);
        }

        //to get the index of the right child
        long long int rightchild(long long int index)
        {
            return ((2*index)+2);
        }

        //to swap 2 numbers
        void swap(long long int *a, long long int *b) 
        { 
            long long int temp=*a; 
            *a=*b; 
            *b=temp; 
        } 

        //to again heapify the heap
        void heapify(long long int indx)
        {
            long long int l=leftchild(indx);
            long long int r=rightchild(indx);
            long long int i=indx;
            //if left child does not exist
            if(l>=size)
            {
                return;
            }
            //if right child does not exist
            if(r>=size)
            {
                return;
            }
            // if left child exist
            if(l<size)
            {
                if(heap[indx]>heap[l])
                {
                    i=l;
                }
            }
            if(r<size)
            {
                if(heap[i]>heap[r])
                {
                    i=r;
                }
            }
            if(indx!=i)
            {
                swap(&heap[i],&heap[indx]);
                heapify(i);
            }
            return;
        }


        //to insert the value in the heap
        void insert(long long int key)
        {
            if(size==0)
            {
                heap[0]=key;
                size++;
            }
            else if(size==capacity)
            {
                cout<<"Heap is Full";
            }
            else
            {
                heap[size]=key;
                long long int indx=size;
                size++;
                long long int parnt=parent(indx);
                while(heap[parnt]>heap[indx])
                {
                    swap(&heap[parnt],&heap[indx]);
                    indx=parent(indx);
                    parnt=parent(indx);
                }
            }
        }

        // to get the min value in O(1)
        long long int getmin()
        {
            if(size<=0)
            {
                //cout<<"Heap is empty";
                return -1;
            }
            return heap[0];
        }

        //to delete the min value from the heap
        void deletemin()
        {
            if(size==0)
            {
                cout<<"Heap is empty";
                size--;
            }
            else if(size==1)
            {
                size--;
            }
            else
            {
                heap[0]=heap[size-1];
                size--;
                heapify(0);
            }
        }

};

int main()
{
    HeapSort h(11);
    h.insert(3); 
    h.insert(2);  
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.getmin()<<" "<<h.size<<endl;
    h.deletemin(); 
    cout << h.getmin()<<" "<<h.size<<endl; 
    h.deletemin();
    cout << h.getmin()<<" "<<h.size<<endl; 
    h.deletemin();
    cout << h.getmin()<<" "<<h.size<<endl;
    h.deletemin();
    cout << h.getmin()<<" "<<h.size<<endl; 
    h.deletemin();
    cout << h.getmin()<<" "<<h.size<<endl; 
    h.deletemin();
    cout << h.getmin()<<" "<<h.size<<endl; 
    //h.deletemin();
    cout<<endl;
}