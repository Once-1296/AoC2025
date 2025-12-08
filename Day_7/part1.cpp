#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line;
vector<vector<char>>gd;
while(getline(file,line))
{
vector<char> row;
for(auto&e:line)row.push_back(e);
gd.push_back(row);
}
int n = gd.size(),m = gd[0].size(),ans=0;
vector<vector<int>>tab(n,vector<int>(m,0));
for(int i =1;i<n;i++){
for(int j = 0;j<m;j++){
if(gd[i][j]=='.'){
if(tab[i-1][j]){
tab[i][j]=1;
}
else if(gd[i-1][j]=='S'){
tab[i][j]=1;
}

}
else{
if(tab[i-1][j]){
if(j>0)tab[i][j-1]=1;
if(j+1<m)tab[i][j+1]=1;
ans++;
}
}
}
}
/*
for(int i =0;i<n;i++){
for(int j =0;j<m;j++){
if(tab[i][j])gd[i][j]='|';
cout<<gd[i][j];
}
cout<<endl;
}*/
cout<<ans<<endl;
}
