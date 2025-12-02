#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
bool chk(ll i){
string x = to_string(i);
ll len = x.length();
ll half = len/2;
string left = x.substr(0,half), right = x.substr(half,len-half);
return left==right;
}
int main(){
fstream file("input.txt",ios::in);
string line;
getline(file,line);
stringstream obj(line);
string part;
ll sum = 0 ;
while(getline(obj,part,',')){
stringstream nums(part);
string num;
vector<string>arr;
while(getline(nums,num,'-')){
arr.push_back(num);
}
//for(auto&e:arr)cout<<e<<" ";
//cout<<endl;
ll L = stoll(arr[0]),R=stoll(arr[1]);
for(ll i = L;i<=R;i++)if(chk(i))sum+=i;
//string sL = arr[0], sR=arr[1];
//while(sL.length() < sR.length())sL="0"+sL;
//if(sL.length()%2==1 && sl[0] > '0') continue;
}
cout<<sum<<endl;
}
