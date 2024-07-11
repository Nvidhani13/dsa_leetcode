/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (48.21%)
 * Likes:    5832
 * Dislikes: 284
 * Total Accepted:    433.7K
 * Total Submissions: 897.5K
 * Testcase Example:  '"()())()"'
 *
 * Given a string s that contains parentheses and letters, remove the minimum
 * number of invalid parentheses to make the input string valid.
 * 
 * Return a list of unique strings that are valid with the minimum number of
 * removals. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()())()"
 * Output: ["(())()","()()()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "(a)())()"
 * Output: ["(a())()","(a)()()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ")("
 * Output: [""]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 25
 * s consists of lowercase English letters and parentheses '(' and ')'.
 * There will be at most 20 parentheses in s.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_set<string> ans;
    
    bool isValid(string &str) {
        int n = str.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') cnt++;
            else if (str[i] == ')') cnt--;
            if (cnt < 0) return false;
        }
        return !cnt;
    }
    
    void recur(string &s, int idx, string str, int invalidCount, int &totalInvalid) {
        if (idx == s.size()) {
            // if string is valid we add it into our ans
            if (isValid(str)) {
                ans.insert(str);
            }
            return;
        }
        
        // if number of remaining characters to be invalidated is equal to the remaining length
        // then we skip the entire remaining string
        if (totalInvalid - invalidCount == s.size() - idx) {
            recur(s, s.size(), str, totalInvalid, totalInvalid);
            return;
        }
        
        // if no more characters need to be invalidated then we consider the entire remaining string
        if (invalidCount == totalInvalid) {
            string temp = str + s.substr(idx);
            recur(s, s.size(), temp, invalidCount, totalInvalid);
            return;
        }
        
        // case 1 - not invalidating the current charater by taking it into the string
        str += s[idx];
        recur(s, idx + 1, str, invalidCount, totalInvalid);
        
        // removing last character for case 2
        str.pop_back();
        
        // if current character is not a parentheses then we can't invalidate it
        // therefore we consider only case 1 by taking it into the string
        if (s[idx] != '(' and s[idx] != ')') {
            return;
        }
        
        // case 2 - invalidating the current character by not taking it into the string
        recur(s, idx + 1, str, invalidCount + 1, totalInvalid);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), cnt = 0, totalInvalid = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (cnt < 0) cnt = 1;
                else cnt++;
            }
            else if (s[i] == ')') cnt--;
            if (cnt < 0 and s[i] == ')') totalInvalid++;
        }
        
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                if (cnt < 0) cnt = 1;
                else cnt++;
            }
            else if (s[i] == '(') cnt--;
            if (cnt < 0 and s[i] == '(') totalInvalid++;
        }
        
        string str;
        recur(s, 0, str, 0, totalInvalid);
        vector<string> res;
        for (auto &i : ans) {
            res.push_back(i);
        }
        
        return res;
    }
};
// @lc code=end

