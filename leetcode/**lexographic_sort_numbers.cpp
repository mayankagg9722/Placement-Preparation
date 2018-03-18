class Solution {
public:
    // int tointeger(string a){
    //     stringstream geek(a);
    //     int x = 0;
    //     geek >> x;
    //     return x;
    // }
    // vector<int> t;
    // void addString(string a,int n){
    //     if(tointeger(a)>n){
    //         return;
    //     }
    //     t.push_back(tointeger(a));
    //     for(int i=0;i<=9;i++){
    //         a.append(to_string(i));
    //         addString(a,n);
    //         a.pop_back();
    //     }
    // }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // int p = tointeger(to_string(to_string(n)[0]));
        // for(int i=1;i<=9;i++){
        //     string a = to_string(i);
        //     addString(a,n);   
        // }
        int a=1;
        for(int i=1;i<=n;i++){
            ans.push_back(a);
            if(a*10<=n){
                a=a*10;
            }else if(a%10!=9 && a+1<=n){
                a=a+1;
            }else{
                while((a/10)%10==9){
                    a=a/10;
                }
                a=a/10+1;
            }
        }
        return ans;
    }
};