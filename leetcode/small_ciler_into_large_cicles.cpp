// how many small circles of radius r can exactly fit into large circle of clapital radius R.

#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.14159
void findnumbers(double R,double r,double &c){
	if(r>=R){
		return;
	}

	double f=(PI/asin(r/(R-r)));
	cout<<"f:"<<floor(f)<<endl;
	c=c+floor(f);
	findnumbers(R-(2*r),r,c);
}
int main()
{
	double R=6,r=2;
	double c=0;
	findnumbers(R,r,c);
	cout<<"final:"<<floor(c)<<endl;
	return 0;
}