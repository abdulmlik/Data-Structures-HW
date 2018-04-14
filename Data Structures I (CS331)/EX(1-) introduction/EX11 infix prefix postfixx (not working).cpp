#include <iostream>
#include <string>

using namespace std;

bool isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='v' || ch=='!' || ch=='&')
        return true;
    else
        return false;
}

int main()
{
    string cal;
    char str[30],op[5];
    int t=-1,i=0,p=0,j=0,oppp=0;
    cout<<"Enter calculator , EX:{x+y-z} \nOperation {+,-,*,/,^(and),v(or),!(not),&(power)} : ";
    cin>>cal;
    if(cal[i]=='(')
    {
        p=1;
        i++;
    }
    while(i < cal.length()-p)
    {

        if(isOperator(cal[i]))
        {
            if(t<0)
            {
                t=0;
            }
            op[t]=cal[i];
            oppp=0;
            t++;
        }
        else if(cal[i]=='(')
        {
            i++;
            str[j]=cal[i];
            oppp=1;
            j++;

        }
        else if(cal[i]==')')
        {
            while(t>=0)
            {
                str[j]=op[t];
                oppp=0;
                j++;
                t--;
            }
        }
        else
        {
                str[j]=cal[i];
                j++;
                if(t>=0 && oppp==0)
                {
                    str[j]=op[t];
                    t--;
                    j++;
                }
        }
    }
    cout<<endl<<"postfix : "<<str;
    return 0;
}
