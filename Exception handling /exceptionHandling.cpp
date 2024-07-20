#include<iostream>
#include<stdexcept>
#include<math.h>
using namespace std;

int main(){

    try{
        int x,y; //x to the power y
        cout<<"enter the base: ";
        cin>>x;
        cout<<"enter the power: ";
        cin>>y;

        if(x==0 && y==0){
            throw runtime_error("zero to the power zero not posiable");
        }
        cout<<"result: "<<pow(x,y);
    }

    catch(exception &e){
        cout<<"error1: "<<e.what()<<endl;
    }

    return 0;
}