#include<iostream>
using namespace std;

class Abc{
  int x;
  
  public: 
  Abc(int y){
    x=y;
  }
  
  friend void print(Abc &obj);  //defination 
 
};

void print(Abc &obj){
  cout << obj.x<< endl;
}

int main(){
  Abc obj(5);
  
  // cout << obj.x << endl;  error
  print(obj);
 
 
  return 0;
}