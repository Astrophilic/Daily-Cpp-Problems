#include <iostream>

using namespace std;

const int inf=1e6;
class maxHeap
{
int *harr;
int hsize;
int capacity;

int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return 2*i+1;

}
int right(int i)
{
    return 2*i+2;
}

public:
    maxHeap(int capacity)
    {
    this->capacity=capacity;
    hsize=0;
    harr=new int[capacity];
    }

    void heapify(int index)
    {
        int largest=index;

        if(left(index)<hsize&& harr[largest]<harr[left(index)])
            largest=left(index);

        if(right(index)<hsize&& harr[largest]<harr[right(index)])
            largest=right(index);

        if(largest!=index)
        {
            swap(harr[largest],harr[index]);
            heapify(largest);
        }
    }

    void insert(int key)
    {
        hsize+=1;
        if(hsize>capacity)
        {
            cout<<"overflow \n";
            return;
        }
        harr[hsize-1]=-inf;
        increaseKey(hsize-1,key);

    }
    void increaseKey(int index,int key)
    {
        if(key<harr[index])
        {
            cout<<"not possible\n";
            return;
        }
        else
        {
            if(index==0)
            {
                harr[index]=key;
                return;
            }
            int i=index;
            harr[i]=key;
            while(i>0&&harr[i]>harr[parent(i)])
            {
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
        }
    }
    int extractMax()
    {
        int value=harr[0];
        swap(harr[0],harr[hsize-1]);
        hsize-=1;
        status();
        heapify(0);
        return value;
    }
    void status()
    {
        for(int i=0;i<hsize;i++)
        {
            cout<<harr[i]<<" ";
        }
        cout<<'\n';
    }
};
int main()
{
    maxHeap mh=maxHeap(20);
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        cout<<"inserting \n";
        mh.insert(x);
        mh.status();
    }
    for(int i=0;i<5;i++)
    {
        cout<<"max ";
        cout<<mh.extractMax()<<'\n';
        mh.status();
    }
    return 0;
}
