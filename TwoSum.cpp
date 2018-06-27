#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            const int diff = target - nums[i];
            if(m.find(diff) != m.end() && m[diff] > i){
                res.push_back(i);
                res.push_back(m[diff]);
                break;
            }
        }
        return res;
    }
};
int main(){
    int a[] = {2,7,11,15};
    vector<int> nums(a,a + 4);
    int target = 9;
    vector<int> res;
    Solution s;
    res = s.twoSum(nums, target);
    for(int i=0;i<2;i++){
        cout << res[i] << endl;
    }
    return 0;
}