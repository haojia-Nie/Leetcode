#include <iostream>
#include <string>


// Solution 1---- brute force, loop over all possibilities and then check palindrome
// Expected Runtime: O(N^3)

class Solution {
public:
    bool is_P(string s){
        int len = s.length();
        for (int i = 0; i < (len / 2); i++){
            if (s[i] != s[len - 1 - i]){
                return false;
            }
        }
        return true;      
    }
    
    
    string longestPalindrome(string s) {
        int len = s.length();
        int max_len = 0;
        string result;
        for (int i = 0; i < len; i ++){
            for (int j = i + 1; j <= len; j ++){
                string substr = s.substr(i, j - i);
                if (is_P(substr)){
                    if (substr.length() > max_len) {
                        max_len = substr.length();
                        result = substr;
                    }
                }
            }
        }
        return result;    
    }
};



// Solution2: Dynamic Programming 
// Expected Runtim: O (n^2)
class Solution {
public:
    
    string reverse_s (string s){
        int len = s.length();
        string result;
        for (int i = len; i >= 0; i--){
            result += s.substr(i, 1);
        }
        return result;
        
    }
    string longestPalindrome(string s) {
        
        // if s is empty string 
        if (s == ""){
            return "";
        }
        
        // else 
        int len = s.length();
        int maxlen = 0;
        int maxleft= 0;
        string reverse = reverse_s(s);
        cout << reverse ;
        int * a = new int [len];

        for (int i = 0; i < len; i ++){
            for (int j = len - 1; j >= 0; j--){
                if (s[i] == reverse[j]){
                    if (i == 0 || j == 0){
                        a[j] = 1;
                    }
                    else {
                        a[j] = a[j - 1] + 1;
                    }
                }
                else {
                    a[j] = 0;
                }
                
                if (a[j] > maxlen){
                    int orig_index = len - 1 - j;
                    if (orig_index + a[j] - 1 == i){
                        maxlen = a[j];
                        maxleft = i;
                    }     
                }         
            }
        }
        
        return s.substr(maxleft - maxlen + 1, maxlen);    
    }
};


