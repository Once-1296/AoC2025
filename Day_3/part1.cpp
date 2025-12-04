#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
int main(){
fstream file("input.txt",ios::in);
string line;
int sum =0;
while(getline(file,line))
{
int lg = int(line[0]-'0'),num=0;
for(int i = 1;i<line.length();i++){
int d = int(line[i] - '0');
num = max(num,10*lg + d);
lg=max(lg,d);
}
sum+=num;
}
cout<<sum<<endl;
}
