// LeetCode Problem 387: First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1595149057/

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<int,int> hash;
            for(int i = 0; s[i] != '\0'; i++)
            {
                hash[s[i]]++;
            }
            for(int i = 0; s[i] != '\0'; i++)
            {
                if(hash[s[i]] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
    };