class Solution {
public:
    map<int, int> accmulative(vector<int> nums) {
        map<int, int> hashmap;
        for (int num : nums) {
            hashmap[num]++;
        }
        return hashmap;
    }

    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> intersection;

        map<int, int> hashmap1 = accmulative(nums1);
        map<int, int> hashmap2 = accmulative(nums2);

        for (auto it = hashmap1.begin(); it != hashmap1.end(); ++it) {
            auto it2 = hashmap2.find(it->first);

            if (it2 != hashmap2.end()) {
                int count = it->second < it2->second ? it->second : it2->second;
                for (int i = 0; i < count; ++i) {
                    intersection.push_back(it->first);
                }
            }
        }

        return intersection;
    }
};