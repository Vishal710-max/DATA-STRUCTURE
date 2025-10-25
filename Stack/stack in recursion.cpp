#include <iostream>
using namespace std;
int fact (int);  //declaration of funcation
int fact (int n) //actual implementaion
{
     if (n==0 || n==1)
        {
            return (1);
        }
    else    {
        return (n*fact(n-1));
    }
}
int main () //calling the function 
{
    int n,z;
    cout<<"\nEnter the no.";
    cin>>n;
    z=fact (n);
    cout<<"\nResult :"<<z;
    return (0);
}