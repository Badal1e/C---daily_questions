// 22. Generate Parentheses
// Medium
// Topics
// Companies
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]


class Solution {
public:
    void createStr(vector<string>& ans,string& substr,int n,int i,int cnt){
        if(i==n && cnt==n){
            ans.push_back(substr);
            return;
        }
        if(i==0 || i==cnt){
           substr.push_back('(');
           createStr(ans,substr,n,i+1,cnt);
           substr.pop_back();
        } else if(i==n && cnt<n){
           substr.push_back(')');
           createStr(ans,substr,n,i,cnt+1);
           substr.pop_back();
        } else{
           substr.push_back('(');
           createStr(ans,substr,n,i+1,cnt);
           substr.pop_back();
           substr.push_back(')');
           createStr(ans,substr,n,i,cnt+1);
           substr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string substr;
        createStr(ans,substr,n,0,0);
        return ans;
    }
};