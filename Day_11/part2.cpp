#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
typedef long long ll;
using namespace std;
ll solve(string S,string T, map<string,set<string>>&adj){

map<string,ll> cnts;
cnts[S]=1;
queue<string>qe;
map<string,ll>indeg;
for(auto&U:adj){indeg[U.first]=max(indeg[U.first],0ll);for(auto&V:U.second){indeg[V]++;}}
for(auto&ND:indeg){
//cout<<ND.first<<" "<<ND.second<<endl;
if(ND.second == 0){
qe.push(ND.first);
}
}
while(!qe.empty()){
string u = qe.front();
//cout<<u<<endl;
qe.pop();
	for(auto&v:adj[u]){
		cnts[v] += cnts[u];
		//cout<<v<<endl;
		indeg[v]--;
		if(indeg[v]==0){
		qe.push(v);
		}
	}

}

/*for(auto&e:cnts){
cout<<e.first<<" "<<e.second<<endl;
}*/
//cout<<"end\n";
return cnts[T];
}

int main(){
fstream file("input.txt",ios::in);
string line;
int sum =0;
set<string> nds;
map<string,set<string>>adj;
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


ll a = solve("svr","dac",adj), b = solve("dac","fft",adj), c = solve("fft","out",adj);
//cout<<a<<" "<<b<<" "<<c<<endl;
ll d = solve("svr","fft",adj), e = solve("fft","dac",adj), f = solve("dac","out",adj);
//cout<<d<<" "<<e<<" "<<f<<endl;

cout<<max(a*b*c,d*e*f)<<endl;
}
