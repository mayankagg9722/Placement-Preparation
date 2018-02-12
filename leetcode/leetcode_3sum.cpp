class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        // vector<vector<int>> answer;
        sort(a.begin(),a.begin()+a.size());
        vector<vector<int>> bigList;
        for(int i=1;i<a.size()-1;i++){
            vector<int> list;
            int l=i-1;
            int r=i+1;
            int sum = a[l]+a[r];
            if(-sum==a[i]){
                list.push_back(a[l]);
                list.push_back(a[i]);
                list.push_back(a[r]);
                bigList.push_back(list);
            }
            else if(-sum>a[i]){
                while(r<a.size()){
                    sum = a[l]+a[r];
                    if(-sum==a[i]){
                        list.push_back(a[l]);
                        list.push_back(a[i]);
                        list.push_back(a[r]);
                        bigList.push_back(list);
                        break;
                    }
                    r++;
                }
            }else{
                while(l>=0){
                    sum = a[l]+a[r];
                    if(-sum==a[i]){
                        list.push_back(a[l]);
                        list.push_back(a[i]);
                        list.push_back(a[r]);
                        bigList.push_back(list);
                        break;
                    }
                    l--;
                }
            }
        }
        // vector<vector<int>> :: iterator it;
        // vector<int> :: iterator it1;
        // for(it=bigList.begin();it!=bigList.end();it++){
        //     for(it1=(*it).begin();it1!=(*it).end();it1++){
        //         // cout<<(*it1)<<" ";
        //     }
        //     cout<<endl;
        // }
        return bigList;
    }
};