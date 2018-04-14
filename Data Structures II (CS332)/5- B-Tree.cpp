/*
/////////// ********************************************************************************************* \\\\\\\\\\\
|                     This program configures B-tree and adds elements to it                                        |
|                                                                                                                   |
|                                         Written by Abdulmalik Ben Ali                                             |
\\\\\\\\\\\ ********************************************************************************************* ///////////
*/

#include<iostream>
#include <limits> //numeric_limits<streamsize>::max()
#include <string>
//#include <iomanip>//setw

using namespace std;

typedef int Type;

// node B-Tree
template<class T>
struct Node
{
    T *data;  // مصفوفة العناصر
    int t;      // اقل عدد للاطفال
    Node **C; // مصفوفة مؤشرات لاطفال النود
    int n;     // عدد العناصر الموجودة في النود
    bool leaf; // هل هذا النود موجود في اسفل الشجرة او لا
    Node(int m, bool l);
    void insertNonFull(T x);
    void splitChild(int i, Node<T> *temp);
    void Display();
    void level(int l, bool& logic, int h);
};

template<class T>
Node<T>::Node(int m, bool l)
{
    t = m;
    leaf = l;
    data = new T[2*t-1];
    C = new Node<T> *[2*t];
    n = 0;
}

template<class T>
void Node<T>::Display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->Display();
        cout << " " << data[i];
    }
    if (leaf == false)
        C[i]->Display();
}

template<class T>
void Node<T>::level(int l,bool& logic,int h /*= 0*/)// error in gcc compiler
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->level(l,logic,h++);
        if(h == l)
        {
            logic = false;
            cout << " " << data[i];
        }
    }
    if (leaf == false)
        C[i]->level(l,logic,h++);
}


// BTree
template<class T>
class BTree
{
    Node<T> *R;
    int t;
public:
    BTree(int m)
    {
        R = NULL;
        t = m;
    }
    void Display()
    {
        if (R != NULL)
            R->Display();
        else
            cout << endl << "B-Tree is Empty" << endl;
    }
    void level(int L)
    {
        if (R != NULL)
        {
            bool logic = true;
            cout << "Element in Level " << L << " :";
            R->level(L,logic,0);
            if(logic)
            {
                cout << " Level " << L << " not exist.";
            }
            cout << endl << endl;
        }
        else
        {
            cout << endl << "B-Tree is Empty" << endl;
        }
    }
    void insert(T data);
};

template<class T>
void BTree<T>::insert(T data)
{
    if (R == NULL)
    {
        R = new Node<T>(t, true);
        R->data[0] = data;
        R->n = 1;
    }
    else
    {
        if (R->n == 2*t-1)
        {
            Node<T> *s = new Node<T>(t, false);
            s->C[0] = R;
            s->splitChild(0, R);
            int i = 0;
            if(s->data[0] < data)
                i++;
            s->C[i]->insertNonFull(data);
            R = s;
        }
        else
            R->insertNonFull(data);
    }
}

template<class T>
void Node<T>::insertNonFull(T x)
{
    int i = n-1;
    if (leaf == true)
    {
        while (i >= 0 && data[i] > x)
        {
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = x;
        n = n+1;
    }
    else
    {
        while (i >= 0 && data[i] > x)
        {
            i--;
        }
        if (C[i+1]->n == 2*t-1)
        {
            splitChild(i+1, C[i+1]);
            if (data[i+1] < x)
            { i++; }
        }
        C[i+1]->insertNonFull(x);
    }
}

template<class T>
void Node<T>::splitChild(int i, Node<T> *temp)
{
    Node *z = new Node<T>(temp->t, temp->leaf);
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)
    {
        z->data[j] = temp->data[j+t];
    }
    if (temp->leaf == false)
    {
        for (int j = 0; j < t; j++)
        {
            z->C[j] = temp->C[j+t];
        }
    }
    temp->n = t - 1;
    for (int j = n; j >= i+1; j--)
    {
        C[j+1] = C[j];
    }
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
    {
        data[j+1] = data[j];
    }
    data[i] = temp->data[t-1];
    n = n + 1;
}

void printScreens();
void adds(BTree<int> *B);

int main()
{
    char input;
    BTree<int> *B = new BTree<int>(2);
    adds(B);
    do{
        system("cls");
        printScreens();
        cout<<"\n\nEnter number \'1-4\' : ";
        cin>>input;
        /*------------- تجاهل جميع الاحرف او الارقام الزائدة عند الادخال --------------*/
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*------------------------------*/
        switch (input)
        {
            case '1':{
                int item;
                system("cls");
                cout << "Enter item(\'integer number\') : ";
                cin >> item;
                B->insert(item);
                cout << endl << "Item (\'" << item << "\') added" << endl << endl;
                system("PAUSE");
                break;
            }
            case '2':{
                system("cls");
                cout << endl << "Element in B-Tree : ";
                B->Display();
                cout << endl;
                system("PAUSE");
                break;
            }
            case '3':{
                int L;
                string s;
                do{
                    system("cls");
                    cout << "Enter No of Level : ";
                    cin >> s;
                    // string.find_first_not_of("") دالة ترجع مكان اول حرف في السلسلة غير موجود في النص المعطى
                }while( s.find_first_not_of( "0123456789" ) != string::npos );// يجب ان يدخل رقم
                L = stoi(s); // يحول من السلسلة الى رقم صحيح
                B->level(L);
                cout << endl;
                system("PAUSE");
                break;
            }
            case '4': return 0;
        }
    }while(input != '4');
    return 0;
}

void printScreens()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali"<<"\n\t\t\tStudent Number : 213010551" << endl;
    cout <<"\n\t\t1- Add item in B-Tree."<<endl;
    cout <<"\n\t\t2- Display items in B-Tree."<<endl;
    cout <<"\n\t\t3- Select a level to display the items in B-Tree."<<endl;
    cout <<"\n\t\t4- End Program."<<endl;
}

void adds(BTree<int> *B)
{
    B->insert(70);
    B->insert(121);
    B->insert(88);
    B->insert(11);
    B->insert(55);
    B->insert(77);
    B->insert(1);
    B->insert(33);
    B->insert(12);
    B->insert(4);
    B->insert(6);
    B->insert(10);
    B->insert(15);
    B->insert(16);
    B->insert(18);
    B->insert(40);
    B->insert(7);
    B->insert(17);
}// end insert 18 item
