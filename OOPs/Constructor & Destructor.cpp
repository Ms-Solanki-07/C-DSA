#include<iostream>
using namespace std;

class Rectangle {
public:  // Access specifier
  int l;
  int b;
  
  Rectangle() { // default constructor - No argument pass 
    l=0;
    b=0;
  }
  
  Rectangle(int x, int y){ // parametersied constructor - Argument pass
    l=x;
    b=y;
  }
  
  Rectangle(Rectangle& r){ // copy constructor - initialise an object by existing object 
    l=r.l;
    b=r.b;
  }
  
  ~Rectangle(){ // destructor
     cout << "Destructor called" << endl;
  }
  
};

int main(){
  Rectangle r1;  // default constructor call
  cout << r1.l <<" " << r1.b<<endl;
  
  Rectangle r2(3,4); //parametersied constructor call
  cout <<r2.l<< " " << r2.b<<endl;
  
  Rectangle r3 = r2; // copy constructor call
  cout <<r3.l<< " " <<r3.b<< endl;
  

  return 0;
}