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
if(add==0)continue;
int extra = add/MOD;
ct+=abs(extra);
add -= extra * MOD;
if(a + add > 0 && a + add < MOD)
{
a = a + add;
continue;
}
//cout<<add<<endl;
if(a==0)ct--;
a = ((a+add)%MOD + MOD)%MOD;
ct++;
}
cout<<ct<<endl;
}
