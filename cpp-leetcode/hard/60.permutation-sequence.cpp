/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (46.70%)
 * Likes:    6546
 * Dislikes: 476
 * Total Accepted:    386.2K
 * Total Submissions: 826.3K
 * Testcase Example:  '3\n3'
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 1 <= k <= n!
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        //! so there is function named erase which erses the particular index 

        //first will create number list from 1 to n 
        vector<int> numbers ;
        string answer="";
        int fact=1;

        for(int i= 1 ;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k=k-1;//0 based indexing
        while(true){
            answer=answer+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0){
                //! introduce the base condition based on k 
                break;
            }
            k=k%fact;
            fact=fact/numbers.size();

        }
        return answer;

    }
};
// @lc code=end

