#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v{1,2,3,4};
     for( auto it=v.end()-1;it>=v.begin();it--)
 {
    cout<<*it<<" ";
 }

 v.insert(v.begin(),8);
 cout<<endl;

 for( auto it=v.cbegin();it!=v.cend();++it)
 {
    cout<<*it<<" ";
 }
 cout<<endl<<v.back();

 v.insert(v.begin()+2,v.begin(),v.begin()+2);
  cout<<endl;
 for( auto it=v.rend()-1;it>=v.rbegin();it--)
 {
    cout<<*it<<" ";
 }
 list<int> ls1{1,2,3};
 list<int> ls2{6,4,5};
 list<int>::iterator it=ls1.begin();

 ls2.splice(ls2.end(),ls1,it);

  cout<<endl<<ls1.empty()<<endl;

 for(auto it:ls1)
 {
   cout<<it<<" ";
 }
 cout<<endl;
 for(auto it:ls2)
 {
   cout<<it<<" ";
 }

  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(3);
  cout<<endl<<"Stack"<<endl<<st.top();
  cout<<endl<<st.size();
  cout<<endl<<st.empty();

  queue<int> q;
  q.push(1); 
  q.push(2); 
  q.push(3); 
  q.emplace(4);
  cout<<endl<<"Queue"<<endl<<q.back(); 
  q.back()+=5;
  cout<<endl<<q.back(); 

  priority_queue<int> pq;
  pq.push(5);
 cout<<endl<<"Priority Queue"<<endl<<pq.top();
  pq.push(2);
  cout<<endl<<pq.top();
  pq.push(8);
  cout<<endl<<pq.top();
  pq.push(10);
  cout<<endl<<pq.top();
  
  cout<<endl;
  while(!pq.empty())
{
  cout<<pq.top()<<" ";
  pq.pop();
}

set <int> s;  //stores only unique values
s.insert(1);
s.emplace(2);
s.emplace(4);
s.emplace(4);
cout<<endl;
// s.erase(2);
for( auto it:s)
{
   cout<<it<<" ";
}
auto it1=s.lower_bound(2);
   cout<<endl<<*it1<<" ";
   auto it3=s.lower_bound(3);
   cout<<endl<<*it3<<" ";
   auto it4=s.lower_bound(4);
   cout<<endl<<*it4<<" ";
auto it2=s.upper_bound(3);
   cout<<endl<<*it2<<" ";

   auto ite = s.lower_bound(2);
   cout<<endl<<"hhh"<<*ite;

   multiset<int> ms;
   ms.insert(1);
   ms.insert(1);
   ms.insert(1);
    int cnt=ms.count(1);
    cout<<endl<<""<<cnt;

    ms.erase(ms.find(1));
    for(auto i:ms)
      cout<<endl<<""<<i;

      map<pair <int,int> , int> mpp;
      mpp.insert({{2,3},3});
 map<int,int> mpp2;
 mpp2.insert({1,3});
 mpp2.insert({2,4});
 mpp2.insert({3,6});
 mpp2[4]=10;

   for(auto it:mpp)
     { cout<<endl<<it.first.first<<" "<<it.first.second<<" "<<it.second;}

cout<<endl<<"map size"<<mpp2.size()<<endl;
     for(int i=1;i<=mpp2.size();i++)
     {
      cout<<mpp2[i]<<" ";
     }
      cout<<mpp2[5]<<" ";
      auto itera =mpp2.find(3);
        cout<<endl<<(itera)->second;

   auto itt=mpp2.lower_bound(2);
   cout<<endl<<itt->first;


   multimap <int,int> multimpp;
   multimpp.insert({2,3});
   multimpp.insert({2,3});

   for(auto it:multimpp)
   {
      cout<<endl<<it.first<<" "<<it.second;
   }


 int num=7;
 int cnt1= __builtin_popcount(num);
  int num2=1236484;
  cout<<endl<<"Num 1 cnt"<<cnt1;
 long cnt2= __builtin_popcountl(num2);
  cout<<endl<<"Num 1 cnt"<<cnt2;
 long long num3=9678578747;
 int cnt3= __builtin_popcountll(num3);
  cout<<endl<<"Num 1 cnt"<<cnt3;

   return 0;
}