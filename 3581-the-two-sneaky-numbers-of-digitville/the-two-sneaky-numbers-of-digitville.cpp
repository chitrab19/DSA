class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> freq(n, 0);
        vector<int> result;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) {
                result.push_back(x);
            }
        }

        return result;
    }
};