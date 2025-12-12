#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<climits>
#include "mathelp.h"
typedef long long ll;
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> v2i;

// vi add(vi&a, vi&b,ll mul){
// vi c(a.size(),0ll);
// int an = a.size();
// for(int i =0;i<an;i++){
// c[i] = a[i] + b[i]*mul;
// }
// return c;
// }
// bool iseq(vi&a,vi&b){
// if(a.size()!=b.size())return false;
// for(int i =0;i<a.size();i++)if(a[i]!=b[i])return false;
// return true;
// }
// bool isgr(vi&a,vi&b){
// if(a.size()!=b.size())return true;
// for(int i =0;i<a.size();i++)if(a[i]>b[i])return true;
// return false;
// }

// bool dfs(int i, int m, int n, vector<vector<int>>&vecs,vector<int>&target,vector<int>cur_vec,ll &mn, ll ct){
// //print(cur_vec);
// if(ct + 1 >= mn) return false;
// if(i==m){
// return false;
// }
// cout<<i<<" ";
// for(int j =0;ct+j<mn;j++){
// vector<int>new_vec=add(cur_vec,vecs[i],j);
// if(isgr(new_vec,target))break;
// else if(iseq(new_vec,target)){mn = min(mn,ct+j);return true;}
// else dfs(i+1,m,n,vecs,target,new_vec,mn,ct+j);
// }
// return false;
// }
// ll solve(vector<vector<int>>&vecs,vector<int>&target){
// int pivot =0, n = target.size(),m = vecs.size();
// for(int i =0;i<n;i++)if(target[i] < target[pivot])pivot =i;
// ll mn = LLONG_MAX;
// for(int i =0;i<m;i++){
// swap(vecs[0],vecs[i]);
// vector<int>cur_vec(n,0);
// dfs(0,m,n,vecs,target,cur_vec,mn,0ll);
// swap(vecs[0],vecs[i]);
// }
// cout<<mn<<endl;
// return mn == LLONG_MAX ?-1: mn;
// }
int main(){
fstream file("input.txt",ios::in);
string line;
ll sum =0,s2=0,ct=0;
ll ans=0;
ll an2=0;
ll fin_sum =0;
while(getline(file,line))
{
ll mn =LLONG_MAX;
v2i vecs;
vi targ;
ll vsz =-1,tsum=0;
stringstream obj(line);
string word = "";
	while(getline(obj,word,' ')){
		if(word[0]=='['){vsz = word.length()-2;}
			else if(word[0]=='('){
			stringstream obj2(word.substr(1,word.length()-2));
			string part="";
			vi vec(vsz,0);
			while(getline(obj2,part,',')){
			mn = min(mn,stoll(part));
			vec[stoll(part)]++;
			}vecs.push_back(vec);
		}
		else {
		stringstream obj2(word.substr(1,word.length()-2));
		string part="";
		targ.resize(vsz,0);
		int ptr=0;
		while(getline(obj2,part,',')){
		mn = min(mn,stoll(part));
		targ[ptr++]=stoll(part);
		tsum+=stoll(part);
		}
	}
}
vecs = transpose(vecs);
ll MINVAL = tsum + 5;
auto respr = num_free_vars(vecs,targ,MINVAL);
ll frvars=respr.first;
ll pos = respr.second,add=0;
if(frvars >= 0){
	ans=max(ans,frvars);
	sum+=frvars;
	an2=max(an2,pos);
	s2+=pos;
	ct++;
	fin_sum+=MINVAL;
	add = MINVAL;
}
else {
	cout<<"\n\nerrors faced\n\n";
}
//cout<<endl<<add<<endl<<endl;
}
cout<<endl<<"MAX: "<<ans<<endl;
cout<<"AVERAGE: "<<(((long double)(sum))/((long double)(ct)))<<endl;

cout<<endl<<"MAX: "<<an2<<endl;
cout<<"AVERAGE: "<<(((long double)(s2))/((long double)(ct)))<<endl;
cout<<"COUNT: "<<ct<<endl;

cout<<"FINAL ANSWER: "<<fin_sum<<endl;
}
