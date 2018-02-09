#include <iostream>
using namespace std;

int greedy(int a[],int b[],int n,int m)
{
    int ans = 0;
    int pa=0,pb=0;
    long int suma=0,sumb=0;
    while(pa<n && pb<m)
    {
        while(pa<n && pb<m && a[pa]!=b[pb])
        {
            if(a[pa]>b[pb])
            {
                sumb+=b[pb];
                pb++;
            }
            else
            {
                suma+=a[pa];
                pa++;
            }
            cout<<"a:"<<suma<<"\n";
            cout<<"b:"<<sumb<<"\n";
        }
        cout<<"break\n";
        if(pa<n && pb<m)
        {
            ans += max(suma,sumb);
            ans+=a[pa];
            suma =0;sumb=0;
            pa++;pb++;
        }
        cout<<"ans:"<<ans<<"\n";
    }
    while(pa<n){suma+=a[pa];pa++;}
    while(pb<m){sumb+=b[pb];pb++;}
    ans+=max(suma,sumb);
    return ans;
}


int main() {
	//code
	// int t,n,m;
	// cin>>t;
	// while(t>0)
	// {
	//     cin>>n>>m;
	//     int a[n],b[m];
	//     for(int i=0;i<n;i++)
	//     {
	//         cin>>a[i];
	//     }
	//     for(int j=0;j<m;j++)
	//     {
	//         cin>>b[j];
	//     }
	//     cout<<greedy(a,b,n,m)<<endl;
	    
	//     t--;

	// }

    int a[5]={1,4,5,6,8};
    int b[5]={2,3,4,6,9};

    cout<<greedy(a,b,5,5)<<endl;
    return 1;

}

