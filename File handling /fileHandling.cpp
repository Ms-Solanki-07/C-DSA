#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file1, tempfile;
    char str[2000];

    file1.open("hello.txt", ios :: out);
    tempfile.open("temp.txt", ios :: out);

    if(!file1){
        cout<<"file not opened/created"<<endl;
    } 
    else {
        cout<<"Enter some data: ";
        gets(str);
        file1<<str;
        file1.close();
    }

    file1.open("hello.txt", ios:: in);

    if(!file1){
        cout<<"file not opened/created"<<endl;
    }
    else {
        char getdata;
        int count=0;
        cout<<"original: ";
        while(!file1.eof()){
            getdata = file1.get();
            cout<<getdata;
            if(getdata==32){
                count++;
            }else {
                count=0;
            }
            if(count > 1){
                continue;  
            }
            else {
                tempfile<<getdata;
            }
        }
        file1.close();
        tempfile.close();
    }
    
    cout<<endl<<endl;

    tempfile.open("temp.txt", ios:: in);

    if(!tempfile){
        cout<<"`file not opened/created"<<endl;
    }
    else {
        char getdata;
        cout<<"tempfile: ";
        while(!tempfile.eof()){
            getdata = tempfile.get();
            cout<<getdata;
        } cout<<endl<<endl;
        tempfile.close();
    } 

    return 0;
}