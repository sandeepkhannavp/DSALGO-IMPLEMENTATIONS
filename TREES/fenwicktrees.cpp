#include <bits/stdc++.h>
using namespace std;
//all the queries must be 0 based , but all the internal working is 1 based

struct FenwickTree{
    vector<int> bit;
    int n;

    FenwickTree(int n)
    {
      this->n=n;
      bit.assign(n+1,0);
    }

    void update(int i , int val)
    {
      for(++i ; i<n ; i+=i&-i)
      {
        bit[i]+=val;
      }
    }
    void range_add(int l ,int r , int val)
    {
      update(l,val);
      update(r+1,val);
    }
    int sum(int i)
    {
      int ans=0;
      for (++i ; i>0 ; i-=i&-i) 
      {
        ans+=bit[i];
      }
      return ans;
    }

};













int main()
{
  
}