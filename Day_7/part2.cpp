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
int n = gd.size(),m = gd[0].size();
ll ans=0;
vector<vector<ll>>tab(n,vector<ll>(m,0));
for(int i =1;i<n;i++){
for(int j = 0;j<m;j++){
if(gd[i][j]=='.'){
if(gd[i-1][j]=='S'){
tab[i][j]=1;
}
else tab[i][j] += tab[i-1][j];
}
else{
if(j>0){tab[i][j-1]+=tab[i-1][j];}
if(j<m-1){
tab[i][j+1]+=tab[i-1][j];

}
}
}
}

/*for(int i =0;i<n;i++){
for(int j =0;j<m;j++){
if(tab[i][j])gd[i][j]='|';
cout<<tab[i][j]<<" ";
}
cout<<endl;
}*/
for(int i = 0;i<m;i++)ans+=tab[n-1][i];
cout<<ans<<endl;
}
