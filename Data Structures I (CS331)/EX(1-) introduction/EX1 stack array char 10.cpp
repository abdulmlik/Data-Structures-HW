#include <iostream>
using namespace std;
class arrayStackType
{
      private:
              int maxStackSize;
              int Top;
              char listt[];
      public:
             arrayStackType(int);
             bool isEmptyStack();
              bool isFullStack();
              void push(char);
              int top();
              char pop();
};
arrayStackType::arrayStackType(int stacksize)
{
    listt[stacksize];
    maxStackSize=stacksize;
    Top=0;
}
void arrayStackType::push(char n)
{
     if(!isFullStack())
     {
        listt[Top]=n;
        Top++;
     }
      else
        cout<<"Stack is full"<<endl;
}
bool arrayStackType::isEmptyStack()
{
        return(Top==0);
}
bool arrayStackType::isFullStack()
{
      return(Top==maxStackSize);
}
int arrayStackType::top()
{
       if(isEmptyStack())
            cout<<"empty stack"<<endl;
       else
            return listt[Top-1];
}
char arrayStackType::pop()
{
        if(!isEmptyStack())
        {
            Top--;
            int f=Top;
            char k=listt[f];
            return k;
        }
        else
        {
            cout<<"Empty Stack"<<endl;
        }
}

int main()
{
    arrayStackType SChar(5);
    SChar.push('A');
    SChar.push('B');
    SChar.push('C');
    SChar.push('D');
    cout<<"SChar{A,B,C,D,}\n";
    SChar.pop();
    SChar.pop();
    cout<<"SChar{A,B,,,}\n";
    SChar.push('D');
    SChar.push('C');
    cout<<"SChsr{A,B,D,C,}\n";
    SChar.pop();
    cout<<"SChar{A,B,D,,}\n";
    SChar.push('E');
    SChar.push('F');
    SChar.push('G');
    cout<<"SChar{A,B,D,E,F} IS FULL\n";
    SChar.pop();
    SChar.pop();
    SChar.pop();
    SChar.pop();
    cout<<"SChar{A,,,,}\n";
    SChar.push('C');
    SChar.push('H');
    cout<<"SChar{A,C,H,,}";
    SChar.pop();
    cout<<"SChar{A,C,,,}";
    system("pause");
return 0;
}
