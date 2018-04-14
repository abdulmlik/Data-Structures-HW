#include <iostream>
#include <cmath>
#include <stdlib.h>     //exit,system c++98

using namespace std;

class HeapTree {
public:
    HeapTree(int n);
    void insert(int data);
    int getLeft(int i) { return 2 * i; }
    int getRight(int i) { return (2 * i) + 1; }
    int getParent(int i) { return i / 2; }
    int getMax() { return maxHeap[0]; }
    void print()
    {
        for(int i=0 ;i<size;i++)
        { cout<<maxHeap[i]; (i !=size-1 )? cout<<", ":cout<<" "; }
    }

    void Build_Max_Heap(int heap_size);
    void Max_Heapify(int i, int heap_size);
    int Search(int Number);
    void Delete();
    void CreateHeap();

private:
    int size;
    int maxSize;
    int *maxHeap;
};

HeapTree::HeapTree(int n) {
    maxHeap = new int[n];
    for(int i = 0 ; i < n ; i++ )
    {
        maxHeap[i]=-1;
    }
    maxSize = n;
    size = 0;
}

void HeapTree::insert(int data) {
    size++;
    if(size > maxSize){
        cout<<"Heap Tree is Full"<<endl;
        return;
    }

    maxHeap[size - 1] = data;
    Build_Max_Heap(size);
}


void HeapTree::Build_Max_Heap(int heap_size) {
    int n = size;
    for (int i = floor(getParent(n-1)); i >= 0; i--) {
        Max_Heapify(i, heap_size);
    }
    return;
}

void HeapTree::Max_Heapify(int i, int heap_size) {
    // int n = size;
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l <= heap_size) && (maxHeap[l] > maxHeap[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r <= heap_size) && (maxHeap[r] > maxHeap[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(maxHeap[i] ,maxHeap[largest]);
        Max_Heapify(largest, heap_size);
    }
    return;
}

int HeapTree::Search(int Number)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(maxHeap[i] == Number)
        {
            return i+1;
        }
    }
    return 0;
}

void HeapTree::Delete()
{
    int Number;
    cout<<"\nEnter The Delete Number : ";
    cin>>Number;
    int index = Search(Number);
    if(index)
    {
        swap(maxHeap[index] ,maxHeap[size-1]);
        maxHeap[--size]=-1;
        cout<<"\nDelete Number "<<Number<<" in Heap\n\n";
        Build_Max_Heap(size);
    }else{
        cout<<"\nNumber "<<Number<<" is not found in Heap\n\n";
    }
}

void HeapTree::CreateHeap()
{
    int data;
    int n , m = maxSize-size;
    do{
        system("cls");
        cout<<"\nEnter The number of data (max inset is "<<m<<") or -999 for exit : ";
        cin>>n;
        if(n == -999) return;
    }while(n > m);
    for(int i = 1; i <=n  ; i++)
    {
        cout<<"\nEnter data "<<i<<" : ";
        cin>>data;
        insert(data);
    }
    cout<<endl;
    system("PAUSE");
}

void printScreens();

int main() {

    HeapTree t(25);
    char input;
    int trun = 0;
    do{
        system("cls");
        printScreens();
        cout<<"\n\nEnter number \'1-5\' : ";
        cin>>input;
        switch (input)
        {
            case '1':
                {
                    t.CreateHeap();
                    trun = 1;
                    break;
                }
            case '2':
                {
                    if( trun )
                    {
                        system("cls");
                        int Number;
                        cout<<"\nEnter The Search Number : ";
                        cin>>Number;
                        if(t.Search(Number))
                        {
                            cout<<"\nNumber "<<Number<<" is found\n\n";
                            system("PAUSE");
                        }else{
                            cout<<"\nNumber "<<Number<<" is not found\n\n";
                            system("PAUSE");
                        }
                    }else{
                        cout<<"The heap does not Exist Please Create The heap\n";
                        system("PAUSE");
                    }
                    break;
                }
            case '3':
                {
                    if( trun )
                    {
                        system("cls");
                        t.Delete();
                        system("PAUSE");
                    }else{
                        cout<<"The heap does not Exist Please Create The heap\n";
                        system("PAUSE");
                    }
                    break;
                }
            case '4':
                {
                    if( trun )
                    {
                        system("cls");
                        cout<<"\nheap = {";
                        t.print();
                        cout<<"}\n";
                        system("PAUSE");
                    }else{
                        cout<<"The heap does not Exist Please Create The heap\n";
                        system("PAUSE");
                    }
                    break;
                }
            case '5': return 0;
        }
    }while(input != '5');
    return 0;
}

void printScreens()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali"<<"\n\t\t\tStudent Number : 213010551" << endl;
    cout <<"\n\t\t1- Create & insert Max Heap Tree \n\t\t   Using Data Type Integer (\"int data\")."<<endl;
    cout <<"\n\t\t2- Search in Heap."<<endl;
    cout <<"\n\t\t3- Delete in Heap."<<endl;
    cout <<"\n\t\t4- Print Heap."<<endl;
    cout <<"\n\t\t5- End Program."<<endl;
}
