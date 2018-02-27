class Solution {
public:
    bool findDict(string s, vector<string>& wd){
        for( string st : wd){
            if(s==st){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string str, vector<string>& wd) {

    int size = str.size();
    if (size == 0)   return true;
    bool wb[size+1];
    memset(wb, 0, sizeof(wb));
    for (int i=1; i<=size; i++)
    {
        if (wb[i] == false && findDict(str.substr(0, i),wd))
        wb[i] = true;

        if (wb[i] == true)
        {
            if (i == size)
                return true;
            for (int j = i+1; j <= size; j++)
            {
                if (wb[j] == false && findDict(str.substr(i, j-i),wd))
                    wb[j] = true;

                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
    }
};