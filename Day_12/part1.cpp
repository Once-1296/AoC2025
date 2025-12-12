#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> v2i;
void reduce(int &c3,int &c4, int &c5, int n){

    while((n>=3&&c3>0)||(n>=4&&c4>0)||(n>=5&&c5>0)){
        if(n>=5 && c5 > 0){
            n-=5;
            c5--;
        }
        else if(n>=4 && c4 > 0){
            n-=4;
            c4--;
        }
        else{
            n-=3;
            c3--;
        }
    }
}
bool solver(vi costs,int n,int m)
{
    int m13 = min(costs[1],costs[3]);
    costs[1]-=m13,costs[3]-=m13;
    int m25 = min(costs[2],costs[5]);
    costs[2]-=m25,costs[5]-=m25;
    int e1 = (costs[1]/2),eo1 = (costs[1]&1);
    int e3 = (costs[3]/2),eo3 = (costs[3]&1);
    int e5 = (costs[5]/2),eo5 = (costs[5]&1);
    int e4 = (costs[4]/2),eo4 = (costs[4]&1);
    int e0 = costs[0];
    int e2 = costs[2];
    int c33 = e0+e2+eo1+eo3+eo5+eo4;
    int c53 = m25 +e5;
    int c43 = m13 + e1 + e3 + e4;
    int rc = n/3;
    int tc33=c33,tc43=c43,tc53=c53;
    while(rc--){
        reduce(tc33,tc43,tc53,m);
    }
    if(tc33==0&&tc43==0&&tc53==0){
        return true;
    }
    int cr = m/3;
     tc33=c33,tc43=c43,tc53=c53;
    while(cr--){
        reduce(tc33,tc43,tc53,n);
    }
    if(tc33==0&&tc43==0&&tc53==0){
        return true;
    }
    return false;
}
int main(){
fstream file("input.txt",ios::in);
string line;
int sum =0;
while(getline(file,line))
{
    vi arr,costs;
    stringstream obj(line);
    string word ="";
    getline(obj,word,':');
    string part="";
    stringstream o2(word);
    while(getline(o2,part,'x')){
        arr.push_back(stoi(part));
    }
    getline(obj,word,':');
    word = word.substr(1,word.length()-1);
    part="";
    stringstream o3(word);
    while(getline(o3,part,' ')){
        costs.push_back(stoi(part));
    }
    if(solver(costs,arr[0],arr[1]))sum++;
}
cout<<sum<<endl;
}
