#include<iostream>
using namespace std;

class parent{
public:
  parent(){
    cout << "Parent class" << endl;
  }
};

class child: public parent { // inherit class parent by class child 
public:
  child(){
    cout << "child class" << endl;
  }
};


int main(){
  
  child c;
  
  return 0;
}