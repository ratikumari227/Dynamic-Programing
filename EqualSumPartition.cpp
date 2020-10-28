#include <iostream>
using namespace std;

bool subSetSum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=true;
            else
                t[i][j]=false;
        }
    }
    
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main(void) {
    
	int arr[]={2,3,8,7};
	int sum=0;
	int n=4;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	if(sum%2!=0)
	    cout<<"Not Possible";
	else
	    cout << subSetSum(arr,(sum/2),n);
	return 0;
}

