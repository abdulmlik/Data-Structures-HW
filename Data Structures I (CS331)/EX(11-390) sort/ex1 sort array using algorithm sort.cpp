#include <iostream>

using namespace std;

// Rank sort
template <class T>
void Ranksorting(T *a,int n)
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

// Bubble sort
template <class T>
void Bubblesorting(T *a,int n)
{
    int i;
    bool done=false;
    i=n;
    while( (i>1) && (!done) )
    {
        done=true;
        for(int j=0;j<i-1;++j)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                done=false;
            }// end if
        }// end for
        --i;
    }//end while
}


// Quick sort
template <class T>
void Quicksorting(T *a,int left,int right)
{
    int i=left,j=right;
    T pivot=a[(left+right)/2];

    while(i<=j){
        while(a[i]<pivot){i++;}
        while(a[j]>pivot){j--;}
        if(i<=j){ swap(a[i],a[j]);i++;j--; }
    }

    if(left<j){Quicksorting(a,left,j);}
    if(i<right){Quicksorting(a,i,right);}
}

/* Merge Sort */
// Merge
template <class T>
void Merge(T *a,int low,int high,int mid)
{
    int i,j,k;
    T c[50];
    i=low;
    k=low;
    j=mid+1;
    while(i <= mid && j <= high)
    {
        if(a[i]<a[j]){c[k]=a[i];k++;i++;}
        else {c[k]=a[j];k++;j++;}
    }
    while(i<=mid)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++)
    {
        a[i]=c[i];
    }
}

// Merge Sort
template <class T>
void Mergesorting(T *a,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        Mergesorting(a,low,mid);
        Mergesorting(a,mid+1,high);
        Merge(a,low,high,mid);
    }
    return;
}
/* End Merge */

int main()
{
    int  Last1[10]={17,29,11,10,35,46,25,31,17,48};
    char Last2[10]={'H','R','C','K','M','D','Y','F','P','J'};
    Ranksorting(Last1,10);
    Bubblesorting(Last2,10);
    Quicksorting(Last1,0,9);
    Mergesorting(Last2,0,9);
    return 0;
}
