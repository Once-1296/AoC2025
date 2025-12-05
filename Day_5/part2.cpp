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
ll sum = 0,cur = pq1.top().first;
//cout<<*ms.begin()<<" "<<mx<<endl;
while(!pq1.empty()){
mx =cur-1;
while(!pq1.empty()){
if(pq1.top().first <=cur){
pair<ll,ll> pr = pq1.top();
pq1.pop();
mx = max(mx, pr.second);
}
else break;
}
sum+=mx - cur +1;
if(!pq1.empty())cur = max(mx+1,pq1.top().first);
}
cout<<sum<<endl;
}
