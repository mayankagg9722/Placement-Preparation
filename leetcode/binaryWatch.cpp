/*
401. Binary Watch

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
*/
class Solution {
public:
    int countOne(int i){
        int c=0;
        while(i){
            if(i&1){
                c++;
            }
            i=i>>1;
        }
        return c;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        unordered_map<int,vector<int>> hr;
        unordered_map<int,vector<int>> min;
        for(int i=0;i<=11;i++){
            int c = countOne(i);
            // cout<<i<<" "<<c<<endl;
            hr[c].push_back(i);
            min[c].push_back(i);
        }
        for(int i=12;i<=59;i++){
            int c = countOne(i);
            min[c].push_back(i);
        }
        for(int i=0;i<=num;i++){
            for(int h : hr[i]){
                for(int m : min[num-i]){
                    string k="";
                    if( h>=0 && h<=9){
                        // k.append("0");
                        k.append(to_string(h));
                    }else{
                        k.append(to_string(h));
                    }
                    k.append(":");
                    if( m>=0 && m<=9){
                        k.append("0");
                        k.append(to_string(m));
                    }else{
                        k.append(to_string(m));
                    }
                    ans.push_back(k);       
                }
            }
        }
        return ans;
    }
};