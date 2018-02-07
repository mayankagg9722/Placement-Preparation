 #include<iostream>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
   		cout<<"i:"<<i<<"\n";
        curr_max = max(a[i], curr_max+a[i]);
        cout<<curr_max<<"\n";
        max_so_far = max(max_so_far, curr_max);
        cout<<max_so_far<<"\n";
        cout<<"@@@@@@"<<"\n";
   }
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}