/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (53.66%)
 * Likes:    10274
 * Dislikes: 484
 * Total Accepted:    697.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 * 
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * There may exists other ways to achieve this answer too.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0 ;
    
        int hash[26];
        int max_frequency=0;
        int answer=0;
        for( int r =0 ;r<s.size();r++){
            hash[s[r]-'A']++;
            max_frequency=max(max_frequency,hash[s[r]-'A']);

            if(r-l+1-max_frequency<=k){
                answer=max(r-l+1,answer);

            }else{
                hash[s[l]-'A']--;
                l++;
            }


        }
        return answer;
    }
};
// @lc code=end
