#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cout<<"Enter the number of items: ";
    cin>>n;
    int profit[n], weight[n]; double res[n];
    cout<<"Enter the profit and weight of all items: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>profit[i]>>weight[i];
    }
    
    cout<<"\nEnter the capacity of the bag: ";
    cin>>w;
    
    for(int i=0; i<n; i++)
    {
        res[i]= profit[i]/weight[i];
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(res[i]<res[j])
            {
                int t1= profit[i];
                profit[i]= profit[j];
                profit[j]= t1;
                
                int t2= weight[i];
                weight[i]= weight[j];
                weight[j]= t2;
                
                int t3= res[i];
                res[i]= res[j];
                res[j]= t3;
            }
        }
    }

    
    int d=1, result=0,i=0;
    while(d==1 && i<n)
    {
        if(weight[i]<w)
        {
            result= result+profit[i];
            w= w-weight[i];
            i++;
        }
        else if(weight[i]>=w && w>0)
        {
            result= result+((w*profit[i])/weight[i]);
            d=0;
        }
    }
    
    cout<<"Total Profit: "<<result;
}
