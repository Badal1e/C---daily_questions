//  Longest Palindromic Substring
// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// ANSWERS

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "" ;
        int sum = 0 ;

        if (s.length() == 1){
            return s ;
        }

        for (int i = 0; i < s.length(); i++) {
            int l, r ;
            l= i ;
            r = i ;
            while (l>= 0 && r <= s.length() && s[l] == s[r]) {
                if (r - l + 1 > sum) {
                    sum = r - l + 1 ;
                    ans = s.substr(l, sum) ;
                }
                l-- ;
                r++ ;
            }
            l = i ;
            r= i+1 ;
            while (l >= 0 && r <= s.length() && s[l] == s[r]) {
                if (r - l + 1 > sum) {
                    sum = r - l + 1 ;
                    ans = s.substr(l, sum) ;
                }
                l-- ;
                r++ ;
            }
        }
        return ans ; 
    }
};