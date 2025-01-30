class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        nums3.insert(nums3.begin(), nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        double ans = 0.0;
        int n = nums3.size();
        int d = n / 2;
        if (n % 2 == 0){
            ans = (nums3[d - 1] + nums3[d])/2.0;
        }else{
            ans = nums3[d];
        }
        return ans;
    }
};