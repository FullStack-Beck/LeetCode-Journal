/*
My version using nested loops
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            int currentnum = nums[i]; // 2
            int numbercheck = target - currentnum; // 7
            for(int z = i + 1; z < nums.size(); z++) // z = 0
            {
                if(nums[z] == numbercheck) // nums[z] = 2, loop again nums[z] = 7 it works
                {
                    return {i, z};
                }
            }
        }
        return {};
    }
};

/*
Optimized Version using hashmap lookups

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Key: Element value, Value: Element index
        std::unordered_map<int, int> seen_numbers; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the required matching number was already visited
            if (seen_numbers.find(complement) != seen_numbers.end()) {
                return {seen_numbers[complement], i};
            }
            
            // Store current number and its index in the hash map
            seen_numbers[nums[i]] = i;
        }
        
        return {};
    }
};
*/
