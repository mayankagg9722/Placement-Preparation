/*
331. Verify Preorder Serialization of a Binary Tree

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/
class Solution {
public:
    vector<string> split(string p){
        vector<string> ans;
        string a = "";
        int k=0;
        while(k<p.length()){
            if(p[k]==','){
                ans.push_back(a);
                a="";
                k+=1;
                continue;
            }
            a+=p[k];
            k+=1;
        }
        if(a.length()>0){
            ans.push_back(a);
        }
        return ans;
    }
    bool isValidSerialization(string preorder) {
        vector<string> b = split(preorder);
        vector<int> a(b.size(),0);
        for(int i=0;i<b.size();i++){
            if(b[i]!="#"){
                a[i]=2;
            }
            if(i>0){
                int f=0;
                for(int j=i-1;j>=0;j--){
                    if(a[j]>0){
                        f=1;
                        a[j]--;
                        break;
                    }
                }
                if(f==0){
                    return false;
                }
            }
        }
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<endl;
            if(a[i]!=0){
                return false;
            }
        }
        return true;
    }
};