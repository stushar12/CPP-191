#include <iostream>
#include<algorithm>
using namespace std;
bool isPossible(int cook[],int n,int prata,int mid)
{
    int num = 0;
    for(int i=0;i<n;i++)
    {
        int t = 2;
        int next_time = cook[i];
        while(next_time<=mid)
        {
            num++;
            next_time=next_time+(cook[i]*t);
            t++;
            if(num >= prata)
                return true;
        }
    }
    return false;
}
long minTimeNeeded(int cook[],int n,int prata)
{
    int start = 0;
    int end = cook[n-1]*prata*(prata+1)/2;
    int mid,ans = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(isPossible(cook,n,prata,mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
            start = mid + 1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int prata;
        cin>>prata;
        int cook[51];
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>cook[i];
        sort(cook,cook+n);
        cout<<minTimeNeeded(cook,n,prata)<<endl;
    }
}
