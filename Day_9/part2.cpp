#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
ll help(ll x1, ll y1, ll x2, ll y2){
return (1+abs(x1-x2))*(1+abs(y1-y2));
}
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
typedef pair<int,int> i2;
typedef pair<i2,i2> i22;
typedef vector<i2> vi2;
typedef vector<i22> vi22;
vector<vector<vector<int>>> proc(vector<vector<int>>&gd){
int n = gd.size(), m = gd[0].size();
vector<vector<vector<int>>> mat(n,vector<vector<int>>(m,vector<int>(4,-1)));
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<m;j++){
			if(gd[i][j] == 1){
				mat[i][j][0] = j;
			}
			else if(j>0)mat[i][j][0]=mat[i][j-1][0];
		}
		for(int j =m-1;j>=0;j--){
			if(gd[i][j] == 1){
				mat[i][j][1] = j;
			}
			else if(j<m-1)mat[i][j][1]=mat[i][j+1][1];
		}
	}
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++){
			if(gd[j][i] == 1){
				mat[j][i][2] = j;
			}
			else if(j>0)mat[j][i][2]=mat[j-1][i][2];
		}
		for(int j =n-1;j>=0;j--){
			if(gd[j][i] == 1){
				mat[j][i][3] = j;
			}
			else if(j<n-1)mat[j][i][3]=mat[j+1][i][3];
		}
	}

return mat;
}
bool isok(int i, int j, v3i &mat){
for(int k =0;k<4;k++)if(mat[i][j][k]==-1)return false;
return true;
}
bool mainok(int i1,int j1, int i2, int j2, v3i &mat){
	for(int i = min(i1,i2);i<=max(i1,i2);i++){
		if(!(isok(i,j1,mat))||!(isok(i,j2,mat)))return false;
	}
	for(int j = min(j1,j2);j<=max(j1,j2);j++){
		if(!(isok(i1,j,mat))||!(isok(i2,j,mat)))return false;
	}
return true;
}
v2i makegd(int n, int m, vector<pair<int,int>>&pts){
v2i gd(n,vi(m,0));
int sz = pts.size();
	for(int i = 0; i < sz;i++){
		int j =(i+1)%sz;
		int i1 = pts[i].first,j1=pts[i].second;
		int i2 = pts[j].first,j2=pts[j].second;
		if(i1==i2){
			for(int k = min(j1,j2);k<=max(j1,j2);k++)gd[i1][k]=1;
		}
		else{
			for(int k = min(i1,i2);k<=max(i1,i2);k++)gd[k][j1]=1;
		}
	}
return gd;
}
vi22 solve(vi2 &pts, int n, int m){
v2i gd = makegd(n,m,pts);
v3i mat = proc(gd);
int sz = pts.size();
vi22 res;
for(int i =0;i<sz;i++){
	for(int j = i+1;j<sz;j++){
		int i1 = pts[i].first,j1=pts[i].second;
		int i2 = pts[j].first,j2=pts[j].second;
		bool fg = mainok(i1,j1,i2,j2,mat);
		if(fg){res.push_back({pts[i],pts[j]});}
	}
}
return res;
}
int main(){
fstream file("input.txt",ios::in);
string line;
map<ll,int> imp,jmp;
map<int,ll>rimp,rjmp;
int ic=1,jc=1;
vi2 pts;
set<ll>ist,jst;
vector<pair<ll,ll>> lpts;
ll ans =0;
while(getline(file,line))
{
	vector<ll> arr;
	stringstream obj(line);
	string word="";
	while(getline(obj,word,',')){
		arr.push_back(stoll(word));
	}
	lpts.push_back({arr[1],arr[0]});
	ist.insert(arr[1]);
	jst.insert(arr[0]);
}
	for(auto&e:ist){
		imp[e] = ic;
		rimp[ic] = e;
		ic++;		
	}
	for(auto&e:jst){
		jmp[e] = jc;
		rjmp[jc] = e;
		jc++;		
	}
	for(auto&e:lpts){
		pts.push_back({imp[e.first],jmp[e.second]});
	}
vi22 res = solve(pts,ic+5,jc+5);
	for(auto&e:res){
		i2 p1 = e.first,p2=e.second;
		ll i1 = rimp[p1.first],j1=rjmp[p1.second];
		ll i2 = rimp[p2.first],j2=rjmp[p2.second];
		ans = max(ans,help(i1,j1,i2,j2));
	}
cout<<ans<<endl;
}
