// LeetCode Problem 347 : Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/submissions/1595466228/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> hash;
        for(auto val : nums)
        {
            hash[val]++;
        }
        vector<pair<int,int>> vec(hash.begin(),hash.end());
        sort(vec.begin(), vec.end(), [](pair<int,int> &p1, pair<int,int> &p2)
        {
            return p1.second > p2.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};