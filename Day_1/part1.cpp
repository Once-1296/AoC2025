#include<iostream>
#include<fstream>
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line ="";
int ct =0, a = 50,MOD=100;
while(getline(file,line)){
int n = line.length();
int add = stoi(line.substr(1,n-1));
if(line[0] == 'L' ) add*=-1;
a = ((a+add)%MOD + MOD)%MOD;
if(a==0)ct++;
}
cout<<ct<<endl;
}
