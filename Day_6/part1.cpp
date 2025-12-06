#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> v2ll;
int main(){
fstream file("input.txt",ios::in);
string line;
v2ll tab;
vector<char> ops;
while(getline(file,line))
{
while(!line.empty()&&line[0]==' ')line.erase(line.begin());
//cout<<line<<endl;
if(line[0] >= '0' &&line[0]<='9'){
vll row;
string tm = "";
for(char c : line){
if(c==' '){if(tm!=""){row.push_back(stoll(tm));}tm="";continue;}
else tm+=c;
}
if(tm!="")row.push_back(stoll(tm));
//cout<<row.size()<<endl;
tab.push_back(row);
}
else{
//cout<<line<<endl;
for(char c:line){
if(c!=' ')ops.push_back(c);
}
//for(auto&e:ops)cout<<e<<" ";
}
}
ll sum =0, n = tab.size(), m = min(ll(tab[0].size()),ll(ops.size()));
//cout<<m<<endl;
for(int i = 0;i<n;i++){
for(int j = 0;j<m;j++){
//cout<<tab[i][j]<<" ";
if(i>0){
if(ops[j]=='*')tab[i][j]=tab[i][j]*tab[i-1][j];
else tab[i][j]=tab[i][j]+tab[i-1][j];
}
if(i==n-1) {
//cout<<tab[i][j]<<endl;
sum+=tab[i][j];
}
}
//cout<<endl;
}
cout<<sum<<endl;
}
