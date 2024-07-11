/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (32.48%)
 * Likes:    1724
 * Dislikes: 216
 * Total Accepted:    440.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words. All the strings of
 * words are of the same length.
 *
 * A concatenated string is a string that exactly contains all the strings of
 * any permutation of words concatenated.
 *
 *
 * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
 * "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
 * not a concatenated string because it is not the concatenation of any
 * permutation of words.
 *
 *
 * Return an array of the starting indices of all the concatenated substrings
 * in s. You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 *
 * Output: [0,9]
 *
 * Explanation:
 *
 * The substring starting at 0 is "barfoo". It is the concatenation of
 * ["bar","foo"] which is a permutation of words.
 * The substring starting at 9 is "foobar". It is the concatenation of
 * ["foo","bar"] which is a permutation of words.
 * The output order does not matter. Returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words =
 * ["word","good","best","word"]
 *
 * Output: []
 *
 * Explanation:
 *
 * There is no concatenated substring.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 *
 * Output: [6,9,12]
 *
 * Explanation:
 *
 * The substring starting at 6 is "foobarthe". It is the concatenation of
 * ["foo","bar","the"].
 * The substring starting at 9 is "barthefoo". It is the concatenation of
 * ["bar","the","foo"].
 * The substring starting at 12 is "thefoobar". It is the concatenation of
 * ["the","foo","bar"].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * s and words[i] consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool check(string &s, unordered_map<string, int> &wordFreq) {
        if (wordFreq.count(s)){
            return true;
        }
        return false;
    }

    bool compareMaps(const unordered_map<string, int> &map1, const unordered_map<string, int> &map2) {
        if (map1.size() != map2.size()) {
            return false; 
        }

        for (const auto &pair : map1) {
            auto it = map2.find(pair.first); // Find corresponding key in map2
            if (it == map2.end() || it->second != pair.second) {
                return false; 
            }
        }

        return true; // All keys and values are equal
    }

    vector<int> findSubstring(string s, vector<string> &words) {
        int windowSize = words[0].size();
        unordered_map<string, int> wordFreq;
        int n = s.size();
        for (string &word : words) {
            wordFreq[word]++;
        }
      
        vector<int> answer;
        int starting = 0;
        int i = 0;
        unordered_map<string, int> seen;
        int count=0 ;
        while (i < (n - windowSize)) {
            string dummyString = s.substr(i, windowSize);
            if (check(dummyString, wordFreq)) {
                i += windowSize;
                seen[dummyString]++;
                if (seen[dummyString] > wordFreq[dummyString]) {
                    seen.clear(); 
                    starting += windowSize;
                    break;
                }
            } else {
                if (compareMaps(seen, wordFreq)&& count==words.size()) {
                    answer.push_back(starting);
                    starting += windowSize;
                     i=starting;
                } else {
                    i++;
                    starting=i;
                }
               
                seen.clear();
            }
        }
        return answer;
    }
};
// @lc code=end
