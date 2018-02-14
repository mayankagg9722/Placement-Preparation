 #include<iostream>
using namespace std;
void findAnswer(int dividend,int divisor,int &count){
    while(dividend>divisor){
        count++;
        dividend=dividend-divisor;
    }
}
 int divide(int dividend, int divisor) {
        int count=0;
        int f=0;
        if(divisor==1 || divisor==-1){
            if(divisor==-1){
                int k = -dividend;
                return k;
            }else{
                return dividend;
            }
        }
        if(divisor==2 || divisor==-2){
            if(divisor==-2){
                return -(dividend>>1);
            }
            return (dividend>>1);
        }
        if(dividend<0 && divisor<0){
            findAnswer(abs(dividend),abs(divisor),count);    
        }else if(dividend<0 || divisor<0){
            f=1;
            findAnswer(abs(dividend),abs(divisor),count);   
        }else{
            findAnswer(abs(dividend),abs(divisor),count); 
        }
        if(f==1){
            return -(count);
        }
        return count;
    }
int main()
{
    int c=divide(-2147483647,-1);  
    cout<<c<<endl;
    return 0;
}
