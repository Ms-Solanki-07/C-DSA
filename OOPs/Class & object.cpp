#include<iostream>
using namespace std;

class Fruit{
public:  // Access specifier
  string name;
  string color;
};

int main(){
  Fruit apple;  // object
  apple.name = "Apple";
  apple.color = "Red";
  cout << apple.name <<" "<< apple.color << endl;
  
  /*Fruit* mango = new Fruit();  // new keyword give the pointer
  mango -> name = "Mango";  // use arrow operater with pointer
  mango -> color = "Yellow";
  cout << apple->name <<" "<< apple->color << endl; */

  return 0;
}