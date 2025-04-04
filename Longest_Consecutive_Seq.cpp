// LeetCode Problem 128 : Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/submissions/1594507866/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int,int>hash;
            unordered_map<int,bool>visited;
            for(auto val : nums)
            {
                hash[val] = 1;
            }
            int maxLength = 0;
            for(auto val : nums)
            {
                if(visited[val])
                {
                    continue;
                }
                visited[val] = true;
                int len = 1;
                bool stoppedfront = false,stoppedrear = false;
                for(int i = 1;;i++)
                {
                    if(hash.find(val - i) != hash.end() && !stoppedrear)
                    {
                        len++;
                        visited[val - i] = true;
                    }
                    else
                    {
                        stoppedrear = true;
                    }
                    if(hash.find(val + i) != hash.end() && !stoppedfront)
                    {
                        visited[val + i] = true;
                        len++;
                    }
                    else
                    {
                        stoppedfront = true;
                    }
                    if(stoppedfront && stoppedrear)
                    {
                        maxLength = max(maxLength,len);
                        break;
                    }
                }
            }
            return maxLength;
        }
    };