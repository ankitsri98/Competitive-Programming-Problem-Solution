#include <bits/stdc++.h>
using namespace std;

int subsum(int a[],int n,int *start ,int *end)
{
    *start=-1;
    *end=-1;
    int sp=INT_MIN;
    int max_so_far=0 , curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=a[i];
        if(curr_sum<0)
        {
            curr_sum=0;
            *start=i+1;//when sum becomes negative then restart
        }
        else
            *end=i;//till values are adding to the +ve value
        if(curr_sum>=max_so_far)
        {
            max_so_far=curr_sum;
        }
    }
    if(*end!=-1)
        return max_so_far;
    else
    {
        for(int i=0;i<n;i++)//THIS IS THE SPECIAL CASE WHEN SUM IS NEGATIVE THEN MAX SUM
        {                    //IS MAX OF ARRAY
            if(a[i]>sp)
                sp=a[i];
        }
        return sp;
    }

}
int main()
{
    int ti;
    cin>>ti;
    while(ti--)
    {
        int n,m,i,j,k,x,z,sum=INT_MIN,start,end;
        cin>>n>>m;
        int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        int t[n]={0};
        for(i=0;i<m;i++)
        {
            memset(t, 0, sizeof(t));
            for(j=i;j<m;j++)
            {
                for(k=0;k<n;k++)
                {
                    t[k]+=a[k][j];

                }
                x=subsum(t,n,&start,&end);//start and end just for the case they ask for co-ordinates

                if(x>sum)
                {
                    sum=x;
                }
            }
        }

        cout<<sum<<endl;
    }

    return 0;
}
