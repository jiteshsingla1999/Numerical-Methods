#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define mk make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int MOD = 1000000007;

signed main()
{
	int n;
	cin >> n;
	double coeff[n+1][n+1];
	
	
	
	for(int i=0;i<n;i++)
	{
		cout << "Enter the coeefficients of x's' respectively and b for equation " << i+1 << endl;
		for(int j=0;j<=n;j++)
		cin >> coeff[i][j];
	}
	
	
	for(int i=0;i<n-1;i++)
	{
		if(coeff[i][i]==0)
		{
			int ss=i+1;
			while(ss<n && coeff[ss][i]==0)
			{
				if(ss==n)
				break;
			}
			
			if(ss==n)
			break;
			
			for(int z=0;z<=n;z++)
			{
				double ee = coeff[i][z];
				coeff[i][z] = coeff[ss][z];
				coeff[i][z] = ee;
			}
		}
		
		if(coeff[i][i]==0 && coeff[i][n]!=0)
		{
			cout << "no solution";
			return 0;
		}
		if(coeff[i][i]==0 && coeff[i][n]==0)
		{
			cout << "Infinite Solution";
			return 0;
		}
		for(int j=i+1;j<n;j++)
		{
			double mulp = coeff[j][i]/coeff[i][i];
			
			for(int l=0;l<=n;l++)
			{
				coeff[j][l] -= mulp*coeff[i][l];			
			}
		}
		
	}
	
	cout << "The Upper diagonal matrix is \n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << coeff[i][j] << "x" << i+1;
			if(j<n-1)
			{
				if(coeff[i][j+1]<0)
					cout << " - ";
				else
					cout << " + ";
			}	
		}
		cout << " = " << coeff[i][n];
		cout << endl;
	
	}
	if(coeff[n-1][n-1]==0)
	{
		cout << "Coefficient of x" << n << " is 0. hence no solution is possible";
		return 0;
	}
	double result[n];
	memset(result, 0, sizeof(result));
	
	result[n-1] = coeff[n-1][n]/coeff[n-1][n-1];
	for(int l=n-2;l>=0;l--)
	{
		double sum=0;
		for(int m=l+1;m<n;m++)
		{
			sum+=coeff[l][m]*result[m];
		}
		if(coeff[l][l]==0)
		{
			cout << "No solution Possible\n";
		}
		result[l] = (coeff[l][n]-sum)/coeff[l][l];
	}
	
	for(int i=0;i<n;i++)
	{
		cout << "x" << i+1 << " = " << result[i] << endl;
	}
	return 0;
	
	
}
