/*C++11   , Code::Blocks   settings->compiler->compiler flags->(-g++ -std=c++11) */

#include <iostream>     // std::cout
#include <numeric>      // std::iota
#include <algorithm>    // std::sort
#include <functional>   // std::bind
//#include <stdlib.h>   // std::system  , C++96

using namespace std::placeholders; // _1 , _2
using namespace std;


int main()
{

    double data[10]={2.7182, 3.14159, 1.202, 1.618, 0.5772, 1.3035, 2.6854, 1.32471, 0.70258, 4.6692};
    int index[10];

    iota (begin(index), end(index), 0); // fill index with {0,1,2,...} This only needs to happen once
    //for(int i = 0; i < 10; i++) index[i] = i;
    sort(begin(index), end(index), [&](int a,int b){return data[a]<data[b];}) ;
    // sort(index, index+10, [&](int a,int b){return data[a]<data[b];} );

    cout << "data:   "; for (int i=0; i<10; i++) cout << data[i] << " "; cout << "\n";
    cout << "index:  "; for (int i=0; i<10; i++) cout << index[i] << " "; cout << "\n";
    cout << "sorted: "; for (int i=0; i<10; i++) cout << data[index[i]] << " "; cout << "\n";

    system("PAUSE");
    return 0;
}
