#ifndef MATHELP_H
#define MATHELP_H
#include<iostream>
#include<cmath>
#include <vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<climits>
using namespace std;
typedef long long ll;
typedef vector<long long> vi;
typedef vector<vi> v2i;

void print(vi &a){for(auto&e:a){cout<<e<<" ";}cout<<endl;}
void print(v2i &a){for(auto&ee:a){for(auto&e:ee){cout<<e<<" ";}cout<<endl;}}
void print(vector<bool> &a){for(int i =0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl;}

bool chkzero(v2i &A, vi&b , int i){
    for(int j = 0;j<A[i].size();j++)if(A[i][j]!=0)return true;
    return b[i]==0;
}

void row_sub(vi & pivot, vi &row, vi&b, int i, int j)
{
    if(row[i]==0)return;
    // if(i==4 && j == 5){
    //     cout<<endl;
    //     print(pivot);
    //     print(row);
    //     cout<<endl;
    // }
    ll g = gcd(abs(pivot[i]),abs(row[i]));
    ll subf = abs(row[i])/g;
    for(int k = 0;k<row.size();k++)row[k]*=(abs(pivot[i])/g);
    b[j] *= (abs(pivot[i])/g);
    if(row[i]*pivot[i]<0)subf*=-1;
    // if(i==4 && j == 5){
    //     cout<<endl;
    //     print(row);
    //     cout<<subf<<" "<<g<<endl;
    //     cout<<endl;
    // }
    for(int k=0;k<row.size();k++){
        row[k] -= (subf*pivot[k]);
    }
    b[j] -= (subf*b[i]);
    // if(i==4 && j == 5){
    //     print(pivot);
    //     print(row);
    //     cout<<endl;
    // }
}

bool row_reduce(v2i &A, vi &b,int n, int m, int i){
    int maxrow = i;
    for(int j = i;j<n;j++){
        if(abs(A[j][i])>abs(A[maxrow][i])){
            maxrow = j;
        }
    }
    if(A[maxrow][i]==0){
        // cout<<"ERROR IN ROW REDUCTION\n";
        // return false;
        return false;
    }
    swap(A[maxrow],A[i]);
    swap(b[maxrow],b[i]);
    for(int j =i+1;j<n;j++){
    row_sub(A[i],A[j],b,i,j);
    }
    return true;
}

bool satisfies(v2i &A,vi &x, vi &b){
    int n = A.size(),m=A[0].size();
    if(n!=b.size()||m!=x.size())return false;
    for(int i = 0;i<n;i++){
        ll sum =0;
        for(int j =0;j<m;j++){
            sum +=A[i][j]*x[j];
        }
        if(sum!=b[i])return false;
    }
    return true;
}

void recur(int in,v2i &A, vi &b, vi &lims,vector<bool> &isfree, int &n, int &m, ll &MINVAL, ll sum, vi &vars){
    if(in<0){
       if(satisfies(A,vars,b)){
        MINVAL = min(MINVAL,sum);
       }
        return;
    }
    if(sum > MINVAL ) return;
    if(isfree[in]){
        for(ll val = 0;val<=lims[in];val++){
            sum+=val;
            vars[in]=val;
            recur(in-1,A,b,lims,isfree,n,m,MINVAL,sum,vars);
            sum-=val;
        }
        return;
    }
    ll rhs = b[in];
    for(ll i = in+1;i<m;i++){
        rhs-=(A[in][i]*vars[i]);
    }
    if(rhs % A[in][in]!=0)return;
    ll lhs = rhs/A[in][in];
    if(lhs<0)return;
    vars[in]=lhs;
    sum+=lhs;
    recur(in-1,A,b,lims,isfree,n,m,MINVAL,sum,vars);
}

pair<ll,ll> num_free_vars(v2i &A, vi &b,ll &MINVAL){
    int n = A.size(),m = A[0].size();
    // cout<<n<<" "<<m<<endl;
    vi ogb =b;
    v2i ogA = A;
    if(n!=b.size()){
        cout<<"Inconsistent dimensions!"<<endl;
        return {-1,-1};
    }
    int li =0;
    vector<bool> isfree(m,true);
    ll ctf = m;
    for(int i = 0; i<min(m,n);i++){
        
       bool tfg = row_reduce(A,b,n,m,i);
       isfree[i]=(!tfg);
       if(tfg)ctf--;
    }
    
    for(int i = 0;i<n;i++){
        bool isok = chkzero(A,b,i);
        if(!isok){
            cout<<"Inconsistent zeroes.\n";
            return {-1,-1};
        }
    }
    ll p =1;
    vi lims(m,0);
    for(int i =0;i<m;i++){
        ll mn = INT_MAX;
        for(int j = 0;j<n;j++){
            if(ogA[j][i]!=0ll)mn=min(mn,ogb[j]);
        }
        lims[i]=mn;
        if(isfree[i])p*=mn;
    }
    vi vars(m,0);
    // print(A);
    // print(b);
    // print(isfree);
    recur(m-1,A,b,lims,isfree,n,m,MINVAL,0ll,vars);
    return {ctf,p};
}

v2i transpose(v2i & A){
    int n = A.size(),m= A[0].size();
    v2i TA(m,vi(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            TA[j][i]=A[i][j];
        }
    }
    return TA;
}
#endif