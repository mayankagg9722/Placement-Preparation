#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
string data;
int size;
static string ans;
 
void print_subsets(string str, int level)    // recursive function
{
        if(level==size-1)
         {
              ans= ans +" " + str;return;
          }
 
print_subsets(str , level+1);
print_subsets(str +data[level], level+1);
}
 
 
int main()
{
cin>>data;                
cin>>size;
print_subsets(data, 0);
cout<<ans;
return 0;
}