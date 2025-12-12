#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
typedef long long ll;
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line;
int sum =0;
set<string> nds;
map<string,set<string>>adj;
map<string,ll> cnts;
while(getline(file,line))
{
stringstream obj(line);
string word="";
getline(obj,word,':');
if(word==""||word==" ")continue;
string u = word;
getline(obj,word,',');
stringstream obj2(word);
string part ="";
	while(getline(obj2,part,' ')){
		if(part==""||part==" ")continue;
		nds.insert(part);
		adj[u].insert(part);
	}
}
string S = "dac", T = "out";
cnts[S]=1;
queue<pair<string,set<string>>>qe;
set<string> st = {S};

qe.push({S,st});
set<string> vis = {S};

while(!qe.empty()){
string u = qe.front().first;
set<string> nx = qe.front().second;
qe.pop();
	for(auto&v:adj[u]){
		if(nx.count(v))continue;
		//if(v=="ggg")cout<<u<<" "<<cnts[u]<<endl;
		cnts[v] += cnts[u];
		if(vis.count(v))continue;
		vis.insert(v);
		set<string> top = nx;
		top.insert(v);
		qe.push({v,top});
	}

}
/*for(auto&e:cnts){
cout<<e.first<<" "<<e.second<<endl;
}*/
cout<<cnts[T]<<endl;
}
