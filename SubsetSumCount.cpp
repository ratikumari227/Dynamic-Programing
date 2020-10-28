#include <iostream>
using namespace std;

int subSetCount(int arr[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=1;
            else
                t[i][j]=0;
        }
    }
    
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main(void) {
    
	int arr[]={2,3,5,6,8,10};
	int sum=10;
	int n=6;
	cout << subSetCount(arr,(sum),n);
	return 0;
}

