#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
bool chk(int i,int j, vector<string>&vec){
int ct =0;
for(int x = -1;x<=1;x++){
for(int y = -1;y<=1;y++){
if(x==0&&y==0)continue;
int di = i+x, dj = j+ y;
if(vec[di][dj]=='@')ct++;
}
}
return ct<4;
}
int main(){
fstream file("input.txt",ios::in);
string line;
vector<string>vec;
int n = -1,m = 1;
while(getline(file,line)){
if(n==-1)
{
n = line.length()+2;
string st(n,'.');
vec.push_back(st);
}
string lin = "." + line;
lin+=".";
vec.push_back(lin);
m++;
}
m++;
string en(n,'.');
vec.push_back(en);
ll sum =0;
bool flag;
do
{
flag = 0;
for(int i =1;i<m-1;i++){
for(int j =1;j<n-1;j++){
if(vec[i][j]!='@')continue;
if(chk(i,j,vec)){
sum++;
vec[i][j]='x';
flag = 1;
}
}
}
}while(flag);
/*for(auto&e:vec){
for(auto&ee:e){
cout<<ee;
}cout<<endl;
}*/
cout<<sum<<endl;
}
