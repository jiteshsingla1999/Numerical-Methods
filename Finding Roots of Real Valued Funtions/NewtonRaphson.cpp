#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define mk make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int MOD = 1000000007;
double fx(double val)
 {
 	return sin(val);
 }
 
double dfx(double val)
{
	return cos(val);
}
signed main()
{
	//Newton Raphson Algorithm

	double xo, eps, n;
	cout << "The Function is sin(x)\n";
	cout << "Enter the initial value: ";
	cin >> xo;
	cout << "Enter the value of epsilon: ";
	cin >>  eps;
	cout << "Enter number of iterations\n";
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		if(fabs(dfx(xo))<=eps)
		{
			cout << "Newton Raphson Method Fails\n";
			return 0;
		}
		
		double x1 = xo - fx(xo)/dfx(xo);
		
		if(fabs(fx(x1))<=eps)
		{
			cout << x1 << " is the root\n";
			return 0;
		}
		xo=x1;	
	}
	return 0;
}
