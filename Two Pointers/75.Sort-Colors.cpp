// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.


// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

// Approach:
// 1. We have two pointers(or variables) left and right, pointing each of the extreme indexes
// and a looping variable index which traverses through the index.
// 2. When we encounter a 0 then we switch it with the value with the left index and increment left
// 3. When we encounter a 2 then we switch it with the value with the right index and decrement right
// Since we are moving 0s and 2s so automatically 1 will be in the middle

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for(int index = 0; index <= right; index++){
            if(nums[index] == 0){
                swap(nums[index], nums[left]);
                left++;
            }

            else if(nums[index] == 2){
                swap(nums[index], nums[right]);
                right--;
                //VERY IMPORTANT
                index--;       //We do this because we dont know what element is coming from the right index
                //it can be 0 or 1, so we need to verify that value too, so to keep the index same for next loop, we decrement it
                //This doesnt apply to left as we know only 0s and 1s will be coming, 2 will be shifting to the right end

                //My Mistake
                //     if(nums[index] == 0){
                //          swap(nums[index], nums[left]);
                //          left++;
                //     }
                // I tried adding this to check if the element is 0 so that we can swap it again
                // But it doesnt work for cases like, {2,1,2} or any array with no 0s
            }
        }
    }
};