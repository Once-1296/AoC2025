#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
typedef long long ll;
using namespace std;
class Node{
public:
ll x,y,z;
int i;
Node(ll a, ll b, ll c, int j){x=a,y=b,z=c,i=j;}

};
ll dist(const Node&a, const Node&b){
return (a.x-b.x)*(a.x-b.x) +(a.y-b.y)*(a.y-b.y) +(a.z-b.z)*(a.z-b.z);
}
bool compare(const pair<Node,Node> & pA, const pair<Node,Node> & pB){
ll dA = dist(pA.first,pA.second), dB = dist(pB.first,pB.second);
return dA < dB;
}
class dsu{
public:
vector<int>par;
vector<ll>siz;
int sz =0;
dsu(int n){
sz = n;
par.resize(n,0);
siz.resize(n,1ll);
for(int i = 0;i<n;i++){
par[i]=i;
}
}
int find(int u){
if(u!=par[u]){
return par[u]=find(par[u]);
}
return u;
}
void comb(int u, int v){
int ru = find(u),rv = find(v);
if(ru!=rv){
par[rv]=ru;
siz[ru]+=siz[rv];
}
}
ll maxk(ll k){
priority_queue<ll> hep;
ll prod=1;
set<int>vis;
for(int i =0;i<sz;i++){
int ri = find(i);
if(vis.count(ri))continue;
vis.insert(ri);
hep.push(siz[ri]);
}
while(k>0ll&!hep.empty()){
prod*=hep.top();
hep.pop();
k--;
}
return prod;
}
};
ll solve(vector<Node>&vec, ll m, ll n, ll k){
if(m>(n*(n-1ll))/2ll)return 0;
dsu ds(n);
vector<pair<Node,Node>>edges;
for(ll i =0;i<n;i++){
for(ll j =i+1;j<n;j++){
edges.push_back({vec[i],vec[j]});
}
}
sort(edges.begin(),edges.end(),compare);
for(ll i = 0;i<m;i++){
ds.comb(edges[i].first.i,edges[i].second.i);
}
return ds.maxk(k);
}
int main(){
fstream file("input.txt",ios::in);
string line;
vector<Node> vec;
ll m = 1000, n =0, k = 3;
while(getline(file,line))
{
stringstream obj(line);
string word = "";
vector<ll> arr;
while(getline(obj,word,',')){
arr.push_back(stoll(word));
}
Node *nd = new Node(arr[0],arr[1],arr[2],int(n));
n++;
vec.push_back(*nd);
}

cout<<solve(vec,m,n,k)<<endl;
}
