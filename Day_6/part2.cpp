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
vector<vector<char>>gd;
while(getline(file,line))
{
vector<char> row;
for(char c:line)row.push_back(c);
gd.push_back(row);
}
int n = gd.size(), m = gd[0].size();
vector<vector<char>>g2(m,vector<char>(n,' '));
vector<int> md(m,0);
for(int i =0;i<n;i++)
{
for(int j = 0;j<m;j++){
g2[j][i] = gd[i][j];
if(gd[i][j] != ' '){
if(gd[i][j]=='+' || gd[i][j] =='*') md[j]=max(md[j],2);
else md[j] = max(md[j],1);
}
}
}
char op = '+'; ll pm = 1, pa = 0,sum =0;
for(int i = 0;i<m;i++){
if(md[i]==0){
if(op=='+')sum+=pa;
else sum+=pm;
pa=0,pm=1;
continue;
}
if(md[i] == 2){
op = g2[i][n-1];
}
string num ="";
for(char c: g2[i])if(c>='0'&&c<='9')num+=c;
ll N = stoll(num);
//cout<<N<<endl;
if(op=='+')pa+=N;
else pm*=N;
}
if(op=='+')sum+=pa;
else sum+=pm;
cout<<sum<<endl;
}
