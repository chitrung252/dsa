// https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/219.%20Contains%20Duplicate%20II.cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> hashmap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.find(nums[i]) != hashmap.end() && abs(hashmap[nums[i]] - i) <= k) {
                return true;
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return false;
    }
};