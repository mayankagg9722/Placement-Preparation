class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> myChar;
        int count=0;
        int i=0;
        int max=0;
        while(i<s.length()){
            if(myChar.size()==0){
                myChar.push_back(s[i]);
                count=1;
            }else{
                int flag=0;
                int h=0;
                for(int j=0;j<myChar.size();j++){
                    h=h+1;
                    if(s[i]==myChar[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    myChar.erase(myChar.begin(),myChar.begin()+h);
                    myChar.push_back(s[i]);
                    count=myChar.size();
                }else{
                    myChar.push_back(s[i]);
                    count=count+1;
                }
            }
            if(max < count){
                max=count;
            }
            i++;
        }
        return max;
    }
};