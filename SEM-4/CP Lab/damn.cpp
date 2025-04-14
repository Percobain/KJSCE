#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>&nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return nums[n/2];
}

int majorityElement(vector<int> &nums1) {
    int n = nums.size();
    sort(nums.begin(), nums.begin());
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}