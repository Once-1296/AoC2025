#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<climits>
typedef long long ll;
using namespace std;
ll f1(string s){
ll num=0,n=s.length();
for(ll i =0;i<n;i++){if(s[i]=='#')num+=(1ll<<i);}
return num;
}
ll f2(string s){
stringstream obj(s);
string num="";
ll res =0;
while(getline(obj,num,',')){
res+=(1ll<<stoll(num));
}
return res;
}
void dfs(int i, int n, ll gol,ll mask, vector<ll>&vec,ll &mn){
if(i==n){
ll res =0,ct =0;
for(ll j = 0;j<n;j++){if(mask&(1ll<<j)){res^=vec[j];ct++;}}
if(res==gol)mn=min(mn,ct);
return;
}
dfs(i+1,n,gol,mask,vec,mn);
dfs(i+1,n,gol,(mask|(1ll<<i)),vec,mn);
}
ll solve(pair<ll,set<ll>>&nums){
ll gol = nums.first;
vector<ll> ans;
for(auto&e:nums.second)ans.push_back(e);
ll mn =LLONG_MAX;
int n = ans.size();
dfs(0,n,gol,0ll,ans,mn);
return mn == LLONG_MAX?-1ll:mn;
}
int main(){
fstream file("input.txt",ios::in);
string line;
ll sum =0,mx=0;
vector<pair<ll,set<ll>>> info;
while(getline(file,line))
{
ll mn =LLONG_MAX;
pair<ll,set<ll>> row;
stringstream obj(line);
string word = "";
while(getline(obj,word,' ')){
if(word[0]=='['){row.first=f1(word.substr(1,word.length()-2));}
else if(word[0]=='('){row.second.insert(f2(word.substr(1,word.length()-2)));}
else {
stringstream obj2(word.substr(1,word.length()-2));
string part="";
while(getline(obj2,part,',')){
mn = min(mn,stoll(part));
}
}
}

mx = max(mx,mn);
ll add = solve(row);
sum+=add;
//cout<<add<<" ";
}
cout<<endl<<mx<<endl<<sum<<endl;
}
