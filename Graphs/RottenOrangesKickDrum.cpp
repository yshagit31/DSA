//Ek visited array le lenge isme nhi li kyunki matrix hmari hi hai. Jitne bhi 2's hai unke index ke sath aur unka tinmer jo ki intially 0 hai usko push kr denge queue me
//Ab queue ke empty hone tab loop chalega har 2 pop krenge(mtlb basically queue kyunki usme vhi hai) aur uske saare values store krenge usme add krke dekhenge adjacent 
//index tak jane wali value. Agar wo valid index ban raha to check krenge ki wo agar 1 hai to usko 2 bana ke queue me push else leave. Cnt ek badhega har bar jab
// queue wala loop chalega aur yhi total ke equal hona cahiye for all oranges to be rotten

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int grid[m][n];
    queue<pair<pair<int,int>,int>> q;
    int total=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
         cin>>grid[i][j];   // input lete time yaha m and n likh raha tha mai
         if(grid[i][j]==2)
         {
            q.push({{i,j},0});
         }   
         if(grid[i][j]!=0)  // yaha pr '==1' likha tha kyunki i thought khali 1's jo change honge unhi ke toal ke equal to hoga count but count hamara queue ke saare elements ke liye badh raha hai. To initilly to hum queue me saare 2's dal re na so total is cnt of 2 + cnt 1  
         {
            total++;
         }
        }
    }
     //total stores total 1 and 2's
     //cnt stores total elements that q will process means all 1 and 2 that are reachable
    // t is the timer naya element push hone pr badhega aur har naye time pr badhega bs

    int row[]={1,-1,0,0};
    int col[]={0,0,-1,1};
    int time=0;
    int t;
    
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        t=q.front().second;
        cout<<endl<<"Cnt is "<<cnt<<endl;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=r+row[i];
            int ncol=c+col[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n)
            {
                if(grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    cout<<t+1;
                    grid[nrow][ncol]=2;
                }
            }
        }
        cnt++;
    }


    // I was returning cnt in exam and here as well initially but cnt is the total elements that went in queue which will be all 2's + 1's. Initially we have
    // all 2's in the queue so we have to add them as well in cnt, then all the 1s are converted to 2 if possible so  those 1's also increase count

    if(total!=cnt) cout<<-1;
    else cout<<t;

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //    cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    
return 0;

}