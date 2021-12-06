#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
int main()
{
    int n, W;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    int wt[n], val[n];
    cout<<"\nEnter the weight and value of each item"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i]>>val[i];
    }
    
    cout<<"\nEnter the total weight to be filled in bag: ";
    cin>>W;
    
    int i, j;
    vector<vector<int>> knap(n + 1, vector<int>(W + 1));
 
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (wt[i - 1] <= j)
                knap[i][j] = max(val[i - 1]+knap[i - 1][j - wt[i - 1]],knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    cout<<"\nTotal Profit: "<<knap[n][W];
     
    return 0;
}