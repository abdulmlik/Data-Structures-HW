#include <iostream>     //cin ,cout
#include <stdlib.h>     //exit,system

using namespace std;

template<class T>
class BSTree
{
    struct NodeBST{
        T data;
        NodeBST *lift,*right;
    };
    NodeBST* root;
public:
    BSTree()
    {
        root = NULL;
    }
    ~BSTree()
    {
        delete root;
    }
    bool isEmpty() const { return root==NULL; }
    void CreateTree();      /* دالة الاختيار الاول */
    void insertTree(T data);/* دالة الاضافة للشجرة */
    void printSizeTree();   /* دالة الاختيار الثاني */
    int sizeTree(NodeBST *n);/* دالة حساب عدد العقد في الشجرة */
    void printLeaves();   /* دالة الاختيار الثالث */
    int countLeaves(NodeBST *n);/* دالة حساب عدد العقد في الشجرة */
    void printTwoChildren();   /* دالة الاختيار الرابع */
    int countTwoChildren(NodeBST *n);/* دالة حساب عدد العقدالتي تحتوي على عقدة في اليسار وعقدة في اليمين */
    void printHeight();   /* دالة الاختيار الخامس */
    int countHeight(NodeBST *n);/* دالة حساب طول الشجرة */
    void display();   /* دالة الاختيار السادس */
    void preorder(NodeBST *n);/* show preorder */
    void inorder(NodeBST *n);/* show inorder */
    void postorder(NodeBST *n);/* show postorder */
    void printTreeDeg90(NodeBST* t, int h);
};

template<class T>
void BSTree<T>::CreateTree()
{
    T data;
    int n;
    system("cls");
    cout<<"\nEnter The number of data : ";
    cin>>n;
    for(int i = 1; i <=n  ; i++)
    {
        cout<<"\nEnter data "<<i<<" : ";
        cin>>data;
        insertTree(data);
    }
    cout<<endl;
    system("PAUSE");
}

template<class T>
void BSTree<T>::insertTree(T data)
{
    NodeBST *p;
    NodeBST *parent;
    p = new NodeBST;
    p->data = data;
    p->lift = NULL;
    p->right = NULL;
    parent = NULL;
    if(isEmpty()) root = p;
    else{
        NodeBST* next;
        next = root;
        while(next)//next != NULL
        {
            parent = next;
            if(p->data > next->data) next = next->right;
            else next = next->lift;
        }
        if(p->data > parent->data) parent->right = p;
        else  parent->lift = p;
    }
    p = NULL;
    delete p;
}

template<class T>
void BSTree<T>::printSizeTree()
{
    system("cls");
    if(!isEmpty())
    {
        int n = sizeTree(root);
        cout<<"\n"<<n<<" Nodes in Tree\n\n";
    }else{
        cout<<"Tree is Empty\n\n";
    }
    system("PAUSE");
}

template<class T>
int BSTree<T>::sizeTree(NodeBST* n)
{
    if(!n)
    {
        return 0;
    }else{
        return 1+sizeTree(n->lift)+sizeTree(n->right);
    }
}

template<class T>
void BSTree<T>::printLeaves()
{
    {
    system("cls");
    if(!isEmpty())
    {
        int n = countLeaves(root);
        cout<<"\n"<<n<<" Leaves Nodes in Tree\n\n";
    }else{
        cout<<"Tree is Empty\n\n";
    }
    system("PAUSE");
}
}

template<class T>
int BSTree<T>::countLeaves(NodeBST* n)
{
    if(n == NULL)
    {
        return 0;
    }
    else if(n->lift == NULL && n->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeaves(n->lift) + countLeaves(n->right);
    }
}

template<class T>
void BSTree<T>::printTreeDeg90(NodeBST* t, int h)
{
   if(t!=0)
    {
        printTreeDeg90(t->right, h+1);
        for(int i=1; i<=h; i++)
                cout << "      " ;
        cout << t->data << endl;
        printTreeDeg90(t->left, h+1);
    }
}

template<class T>
void BSTree<T>::printTwoChildren()
{
    {
    system("cls");
    if(!isEmpty())
    {
        int n = countTwoChildren(root);
        cout<<"\n"<<n<<" Nodes With Two Children in Tree\n\n";
    }else{
        cout<<"Tree is Empty\n\n";
    }
    system("PAUSE");
}
}

template<class T>
int BSTree<T>::countTwoChildren(NodeBST* n)
{
    if(n == NULL)
    {
        return 0;
    }
    else if((n->lift != NULL) && (n->right != NULL))
    {
        return 1 + countTwoChildren(n->lift) + countTwoChildren(n->right);
    }
    else
    {
        return countTwoChildren(n->lift) + countTwoChildren(n->right);
    }
}

template<class T>
void BSTree<T>::printHeight()
{
    system("cls");
    if(!isEmpty())
    {
        int n = countHeight(root);
        cout<<"\n"<<n<<" Height of Tree\n\n";
    }else{
        cout<<"Tree is Empty\n\n";
    }
    system("PAUSE");
}

template<class T>
int BSTree<T>::countHeight(NodeBST* n)
{
    if(n == NULL) return 0;
    else return 1 + max(countHeight(n->lift),countHeight(n->right));
}

template<class T>
void BSTree<T>::display()
{
    system("cls");
    if(!isEmpty())
    {
        int n;
        cout<<"1- show data preorder\n2- show data inorder\n2- show data postorder"<<endl;
        cout<<"Enter number (1-3) : ";
        cin>>n;
        cout<<"{ ";
        switch(n)
        {
            case 1: preorder(root);
                break;
            case 2: inorder(root);
                break;
            case 3: postorder(root);
                break;
        }
        cout<<"}\n";
    }else{
        cout<<"Tree is Empty\n\n";
    }
    system("PAUSE");
}

template<class T>
void BSTree<T>::preorder(NodeBST* n)
{
    if(n != NULL)
    {
        cout<<n->data<<" ";
        preorder(n->lift);
        preorder(n->right);
    }
}
template<class T>
void BSTree<T>::inorder(NodeBST* n)
{
    if(n != NULL)
    {
        inorder(n->lift);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}
template<class T>
void BSTree<T>::postorder(NodeBST* n)
{
    if(n != NULL)
    {
        postorder(n->lift);
        postorder(n->right);
        cout<<n->data<<" ";
    }
}

void printScreens();/* دالة طباعة الاختيارت */

int main()
{
    int input, trun = 0;
    BSTree<int> BST;
    do{
        system("cls");
        printScreens();
        cout<<"\n\nEnter number \'1-7\' : ";
        cin>>input;
        switch (input)
        {
            case 1:
                {
                    BST.CreateTree();
                    trun = 1;
                    break;
                }
            case 2:
                {
                    if( trun == 1 )
                    {
                        BST.printSizeTree();
                    }else{
                        cout<<"The Tree does not Exist Please Create The Tree\n";
                        system("PAUSE");
                    }
                    break;
                }
            case 3:
                {
                    if( trun == 1 )
                    {
                        BST.printLeaves();
                    }else{
                        cout<<"The Tree does not Exist Please Create The Tree\n";
                        system("PAUSE");
                    }
                    break;
                }
            case 4:
                {
                    if( trun == 1 )
                    {
                        BST.printTwoChildren();
                    }else{
                        cout<<"The Tree does not Exist Please Create The Tree\n";
                        system("PAUSE");
                    }
                    break;
                }
            case 5:
                {
                    if( trun == 1 )
                    {
                        BST.printHeight();
                    }else{
                        cout<<"The Tree does not Exist Please Create The Tree\n";
                        system("PAUSE");
                    }
                    break;
                }
            case 6:
                {
                    if( trun == 1 )
                    {

                    }else{
                        cout<<"The Tree does not Exist Please Create The Tree\n";
                        system("PAUSE");
                    }
                    break;
                }
            case 7: exit(0);
        }
    }while(input!=7);
    return 0;
}

void printScreens()
{
    cout << "\n\t\t\tName           : Abdulmalik Ben Ali"<<"\n\t\t\tStudent Number : 213010551" << endl;
    cout <<"\n\t\t1- Create Binary Search Tree (\"SBT\")\n\t\t   Using Data Type Integer (\"int data\")."<<endl;
    cout <<"\n\t\t2- The Number of Nodes in Tree."<<endl;
    cout <<"\n\t\t3- The Number of Terminal Nodes in Tree."<<endl;
    cout <<"\n\t\t4- The Number of Nodes With Two Children in Tree."<<endl;
    cout <<"\n\t\t5- The Height of Tree."<<endl;
    cout <<"\n\t\t6- Display the Tree."<<endl;
    cout <<"\n\t\t7- End Program."<<endl;
}
