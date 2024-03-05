#include <vector>
#include <unordered_map>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hashMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            hashMap[nums[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (hashMap[complement])
            {
                return { i, hashMap[complement] };
            }
        }
        return {};


        /*vector<int> results;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && (nums[i] + nums[j] == target))
                {
                    results.push_back(i);
                    results.push_back(j);
                    return results;
                }
            }
        }
        return results;*/
        //return i;
    }
};