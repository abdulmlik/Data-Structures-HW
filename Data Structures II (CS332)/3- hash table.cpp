/*
/////////// ********************************************************************************************* \\\\\\\\\\\
|                     This program converts data to an index                                                        |
|                     Via hashing and also creates a table to search, add and delete data from the table            |
|                     The program uses chaining to resolve collisions                                               |
|                                                                                                                   |
|                                         Written by Abdulmalik Ben Ali                                             |
\\\\\\\\\\\ ********************************************************************************************* ///////////
*/
#include <iostream>
#include <string>

#define N 73    //Used in table size and mod

using namespace std;

struct Node{
    string name;
    Node* next;
    Node()
    {
        name = "-1";    // default value
        next = NULL;
    }
};

class hash_table{
    Node table[N];
    int Count;      //count data in the table
public:
    hash_table()
    {
        Count = 0;
    }

    size_t hashing(const string s)
    {
        unsigned long h = 0;
        for (unsigned i = 0 ; i < s.length() ; i++)
          h = 5 * h + s[i];
        return size_t(h) % N;                           //  N
    }

    unsigned doubleHashing(const string s)
    {
        unsigned A = 54059, B = 76963, C = 86969,h = 37,i=0;
        while (i < s.length())
        {
            h = (h * A) ^ (s[i] * C);
            i++;
        }
        return (h%B) % N;                               // N
    }

    int Search(string name)
    {
        int index = int(hashing(name));
        if( table[index].name == name )
        {
            return 1;
        }//end if name
        else{
            if( table[index].next == NULL )
            {   return 0;  }
            else{
                Node* p = table[index].next;
                while(p){
                    if( p->name == name )
                    {
                        return 1;
                    }
                    p = p->next;
                }//end while
                p = NULL;
                return 0;
            }//end else Null
        }//end else name
    }//end search
    void Searchtable()          //select 1
    {
        system("cls");
        string name;
        cout << "Enter First and Last Name : ";
        cin.clear();
        cin.ignore();
        getline( cin , name );
        if( Search(name) )
        {
            cout<<"\nThe Name (\""<<name<<"\") is Exist \n\n";
        }else{
            cout<<"\nThe Name (\""<<name<<"\") Not Exist \n\n";
        }
        system("PAUSE");
    }

    int Add(string name)
    {
        int index = int(hashing(name));
        if( table[index].name == name )
        {
            return 0;
        }//end if name exist
        else if(table[index].name == "-1")
        {
            table[index].name = name;
            return 1;
        }//end if name save
        else{
            Node* p =table[index].next;
            Node* c = NULL;
            while(p)
            {
                if( p->name == name )
                {
                    return 0;
                }//end if name in exist chaining
                c = p;
                p = p->next;
            }//end while
            p = new Node;
            p->name = name;
            p->next = NULL;
            if( c == NULL )
                table[index].next = p;
            else
                c->next = p;
            return 2;
        }// chaining to resolve collisions
    }//end add
    void Selectadd()        //2
    {
        system("cls");
        string name;
        cout << "Enter First and Last Name : ";
        cin.clear();
        cin.ignore();
        getline( cin , name );
        if( Add(name) )
        {
            cout<<"\nThe Name (\""<<name<<"\") is save \n\n";
        }else{
            cout<<"\nThe Name (\""<<name<<"\") is Exist \n\n";
        }
        system("PAUSE");
    }

    int Delete(string name)
    {
        int index = int(hashing(name));
        if( table[index].name == name )
        {
            table[index].name = "-1";
            if(table[index].next != NULL )
            {
                Node* p = table[index].next;
                table[index].name = p->name;
                table[index].next = p->next;
                p->next = NULL;
                delete p;
            }
            return 1;
        }//end if name delete
        else if(table[index].name == "-1")
        {
            return 0;
        }//end if name not exist
        else{
            Node *p =table[index].next, *c = NULL;
            while(p)
            {
                if( p->name == name )
                {
                    if(c == NULL)
                    {
                        table[index].next = p->next;
                        p->next = NULL;
                        delete p;
                    }else{
                        c->next = p->next;
                        p->next = NULL;
                        delete p;
                    }
                    return 1;
                }//end if name in exist chaining
                c = p;
                p = p->next;
            }//end while
            return 0;
        }// chaining to resolve collisions
    }
    void selectdelete()     //3
    {
        system("cls");
        string name;
        cout << "Enter First and Last Name : ";
        cin.clear();
        cin.ignore();
        getline( cin , name );
        if( Delete(name) )
        {
            cout<<"\nThe Name (\""<<name<<"\") is deleted \n\n";
        }else{
            cout<<"\nThe Name (\""<<name<<"\") Not Exist \n\n";
        }
        system("PAUSE");
    }
};

void printScreens();
void enterName(hash_table *table);

int main()
{
    //hash<string> hashing;             // c++11 ( c++ approved 2011 containing hashing)
    //cout << hashing("abdulmailk");
    char input;
    hash_table table;
    enterName(&table);
    do{
        system("cls");
        printScreens();
        cout<<"\n\nEnter number \'1-4\' : ";
        cin>>input;
        switch (input)
        {
            case '1':   table.Searchtable();
                break;
            case '2':   table.Selectadd();
                break;
            case '3':   table.selectdelete();
                break;
            case '4': return 0;
        }
    }while(input != '4');
    return 0;
}

void printScreens()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali"<<"\n\t\t\tStudent Number : 213010551" << endl;
    cout <<"\n\t\t1- Search in Table."<<endl;
    cout <<"\n\t\t2- Add in Table."<<endl;
    cout <<"\n\t\t3- Delete in Table."<<endl;
    cout <<"\n\t\t4- End Program."<<endl;
}

void enterName(hash_table *table)
{
    table->Add("abdulmalik");
    table->Add("abdulrahman");
    table->Add("ali");
    table->Add("ben ali");
    table->Add("wesam");
    table->Add("ahmed");
}
