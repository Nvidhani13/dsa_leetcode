/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    11129
 * Dislikes: 397
 * Total Accepted:    836.2K
 * Total Submissions: 1.9M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;


        unordered_map<char,int>s1_freq,window_freq;
        int window_size=s1.size();
        for(int i =0;i<s1.size();i++){
            s1_freq[s1[i]]++;
        }
        for(int i =0;i<window_size;i++)
        window_freq[s2[i]]++;
     if(s1_freq==window_freq) return true;
    for(int i = window_size; i < s2.size(); i++) {
    if(--window_freq[s2[i - window_size]]==0)
    window_freq.erase(s2[i - window_size]); // Remove the character going out of the window
    window_freq[s2[i]]++; // Add the character coming into the window

    if(s1_freq == window_freq) return true;
}

        return false ;
    }
};
// @lc code=end

