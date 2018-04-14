#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>
#include <string>
using namespace std;


static void Merge2(int* arr1, int len1, int* arr2, int len2)
{
    int i = len1 - 1;
    int j = len2 - 1;
    int k = len1 + len2 -1;

    while(i >= 0 && j >=0){
        if(arr1[i] >= arr2[j]){
            arr1[k --] = arr1[i --];
        }
        else{
            arr1[k --] = arr2[j --];
        }
    }

    while(j >=0){
        arr1[k--] = arr2[j--];
    }
}

static void Merge3(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3, int* output, int len4)
{
    for(int i = 0; i < len1; ++i){
        output[i] = arr1[i];
    }

    Merge2(output, len1, arr2, len2);
    Merge2(output, len1 + len2, arr3, len3);
}

void PrintArray(int* arr, int len, string msg)
{
    cout << msg << endl;
    for(int i = 0 ; i < len; ++i){
        cout << setw(4) << left << arr[i];
    }
    cout << endl<<endl;
}
void DoTest(int* arr1, int len1, int* arr2, int len2, int* arr3, int len3, int* output, int len4)
{
    PrintArray(arr1, len1, "Array 1");
    PrintArray(arr2, len2, "Array 2");
    PrintArray(arr3, len3, "Array 3");
    Merge3(arr1, len1, arr2, len2, arr3, len3, output, len4);
    PrintArray(output, len4, "Output after merging");
}

int main(int argc, char* argv[])
{
    int A[]={2,4,6,8};
    int B[]={1,3,5,7};
    int C[]={10,12,14,16};

    int lenA = sizeof(A)/sizeof(A[0]);
    int lenB = sizeof(B)/sizeof(B[0]);
    int lenC = sizeof(C)/sizeof(C[0]);
    int lenD = lenA + lenB + lenC;
    int *D = new int[lenD];
    DoTest(A, lenA, B, lenB, C, lenC, D, lenD);
    delete[] D;

    return 0;
}
