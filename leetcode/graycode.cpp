class Solution {
public:
    stack<int> toBinary(int n){
        stack<int> b;
        if(n==0){
            b.push(0);
            return b;
        }
        while(n>1){
            int r = n%2;
            b.push(r);
            n=n/2;
        }
        b.push(1);
        return b;
    }
    vector<int> grayCode(int n) {
        vector<int> finalVect;
        for(int i=0;i<(1<<n);i++){
            vector<int> a;
            stack<int> b = toBinary(i);
            while(b.size()>0){
                a.push_back(b.top());
                b.pop();
            }
            int binary=0;
            int k=a.size()-1;
            for(int i=0;i<a.size();i++){
                if(i==0){
                    binary=binary+(pow(2,k--)*a[i]);
                    continue;
                }
                if((a[i]==1 && a[i-1]==1) || (a[i]==0 && a[i-1]==0)){
                    binary=binary+(pow(2,k--)*0);
                }else{
                    binary=binary+(pow(2,k--)*1);
                }
            }
            finalVect.push_back(binary);
        }
        return finalVect;
    }
};