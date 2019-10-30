#include <iostream>

using namespace std;

void selectionSort(int *ar,int n)
{
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {

            if(ar[j]<ar[minIndex])
            {
                minIndex=j;
            }
        }
        swap(ar[minIndex],ar[i]);
    }
    cout<<"after selection sort"<<'\n';
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<'\n';
}

void insertionSort(int *ar,int n)
{

    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int value=ar[i];

        while(j>=0&&ar[j]>value)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=value;
    }
       cout<<"after insertion sort"<<'\n';
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<'\n';
}

void mergee(int *ar,int s,int m,int e)
{
    int result[e-s+1];
    int i=s;
    int j=m+1;
    int k=0;

    while(i<=m&&j<=e)
    {
        if(ar[i]<=ar[j])
        {
            result[k++]=ar[i];
            i++;
        }
        else
        {
            result[k++]=ar[j];
            j++;
        }
    }
    while(i<=m)
        result[k++]=ar[i++];
    while(j<=e)
        result[k++]=ar[j++];

    for(int i=0;i<e-s+1;i++)
        ar[s+i]=result[i];


}
void mergeSort(int *ar,int s,int e)
{
    if(s>=e)
        return;
    int m=(s+e)/2;

    cout<<"m sort "<<s<<" "<<e<<"\n";
    mergeSort(ar,s,m);
    mergeSort(ar,m+1,e);
    mergee(ar,s,m,e);
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
   // selectionSort(ar,n);
    //insertionSort(ar,n);
    mergeSort(ar,0,n-1);
     cout<<"after merge sort"<<'\n';
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<'\n';
    return 0;
}
