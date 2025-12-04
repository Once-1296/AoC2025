#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line;
ll sum =0;
while(getline(file,line))
{
int n = line.length();
vector<vector<ll>> dp(n+1,vector<ll>(13,0));
ll num =0;
for(int i = 0;i<line.length();i++){
for(int j = i; j>=0;j--)
{
for(int k = 0;k<12;k++){
dp[i+1][k+1] = max(dp[i+1][k+1],10ll*dp[j][k]+ll(line[i]-'0'));
}
}
num = max(num,dp[i+1][12]);
}
sum+=num;
}
cout<<sum<<endl;
}
