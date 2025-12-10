#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
ll help(ll x1, ll y1, ll x2, ll y2){
return (1+abs(x1-x2))*(1+abs(y1-y2));
}
ll help2(ll x2, set<ll>ys,ll x1, ll y1){
ll y2 =*ys.begin();
ll res=help(x1,y1,x2,y2);
y2=*(--ys.end());
res=max(res,help(x1,y1,x2,y2));
return res;
}
ll solve(map<ll,set<ll>>&mps, pair<ll,ll> e){
ll ar =0, x1=e.first,y1=e.second;
for(auto&e:mps){
ar=max(ar,help2(e.first,e.second,x1,y1));
}
return ar;
}
int main(){
fstream file("input.txt",ios::in);
string line;
map<ll,set<ll>>mps;
vector<pair<ll,ll>>vec;
ll ans =0;
while(getline(file,line))
{
vector<ll> arr;
stringstream obj(line);
string word="";
while(getline(obj,word,',')){
arr.push_back(stoll(word));
}
vec.push_back({arr[0],arr[1]});
mps[arr[0]].insert(arr[1]);
}
for(auto&e:vec){
ans = max(ans,solve(mps,e));
}
cout<<ans<<endl;
}
