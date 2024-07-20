class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> hashmap;

        vector<int> intersection;

        for (int num : nums1) {
            hashmap[num]++;
        }

        for (int num : nums2) {
            if (hashmap[num] > 0) {
                intersection.emplace_back(num);
                --hashmap[num];
            }
        }

        return intersection;
    }
};