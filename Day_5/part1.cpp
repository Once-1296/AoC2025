#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<set>
typedef long long ll;
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line;
multiset<ll> ms;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq1,pq2;
ll mx =0;
while(getline(file,line))
{
if(line.find('-')!=string::npos){
vector<ll>v;
stringstream obj(line);
string word ="";
while(getline(obj,word,'-'))v.push_back(stoll(word));
pq1.push({v[0],v[1]});
mx = max(mx,v[1]);
}
else if(line[0]<'0'||line[0] > '9');
else{
ms.insert(stoll(line));
}
}
ll ct = 0;
//cout<<*ms.begin()<<" "<<mx<<endl;
while(!ms.empty()){
ll cur = *ms.begin();
//cout<<cur<<endl;
while(!pq1.empty()){
if(pq1.top().first <=cur){
//cout<<cur<<" "<<pq1.top().first<<endl;
pair<ll,ll>  pr = pq1.top();
pq1.pop();
pq2.push({pr.second,pr.first});
}
else break;
}
//if(pq2.size()>0)cout<<pq2.size()<<endl;
while(!pq2.empty()){
if(pq2.top().first < cur){
pq2.pop();
}
else break;
}

if(pq2.empty());
else ct++;

ms.erase(ms.begin());
}
cout<<ct<<endl;
}
