#include <iostream>
#define max 7
using namespace std;
int stack_arr[max];
int top=-1;
int value;
int push(int data){

    if(top==max-1||top==max)
    {
        cout<<"the stack is overflow";
    }
    top=top+1;
    stack_arr[top]=data;
}

int dec_to_bi(int dec)
{

    while(dec!=0)
    {
        push(dec%2);
        dec=dec/2;
    }

}
int display ()
{
    if(top==-1)
    {
        cout<<"the stack is underflow";
    }
    for(int i=top;i>=0;i-- )
    {
        cout<<stack_arr[i];
    }
}
int main(){
    int dec;
    cout<<"please enter the number "<<endl;
    cin>>dec;
    dec_to_bi(dec);
    display();



}
