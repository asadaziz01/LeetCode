// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 
// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

// 1. DRY RUN THIS, Two Pointers Approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = 0;
        int p = 0;
        for(int i = 0; i <  nums.size(); i++){
            p = (p + k) % nums.size();
            swap(nums[p], nums[s]);
            if(s == p){
                s++;
                p++;
            }
        }
    }
};

// 2. Using Modulus Function
// example:
// {1,2,3,4,5,6} k = 2
// => {5,6,1,2,3,4}
// 0 -> 2, 1 -> 3, 2 -> 4, 3 -> 5, 4 -> 0, 5 -> 1
// (index + k) % n

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int>ans(n);
//         for(int i=0;i<n;i++){
//             int newindex=(i+k)%(nums.size());  // 
//             ans[newindex]=nums[i];
             
//         }
//         nums=ans;
//     }
// };

// 3. Some Lame Approach using reverse
// just reverse the whole array, then reverse from 0 to k, then reverse k + 1 to n
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         reverse(nums.begin(), nums.end());
// 	    reverse(nums.begin(), nums.begin() + k);
// 	    reverse(nums.begin() + k, nums.end());
//     }
// };