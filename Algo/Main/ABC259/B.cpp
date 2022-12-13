#include <bits/stdc++.h>
using namespace std;

int main() {
	double a,b,d;
	cin>>a>>b>>d;

	double r = sqrt(a*a+b*b);
	double t = atan2(b,a);
	t += d *3.14159265359/180.0;
	double x = cos(t) * r;
	double y = sin(t) * r;
	cout<<fixed<<setprecision(20);
    cout<<x<<' '<<y<<endl;
}
