//  Median of Two Sorted Arrays

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// ANSWERS

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;

        vector <int> v;

        while(i < nums1.size() && j < nums2.size()){

            if(nums1[i] < nums2[j]){

                v.push_back(nums1[i]);
                i++;

            } else {

                v.push_back(nums2[j]);
                j++;

            }

        }

        while(i < nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            v.push_back(nums2[j]);
            j++;
        }

        if(v.size()%2 != 0){
            return v[v.size()/2];
        }

        return (float) (v[v.size()/2] + v[(v.size()/2)-1])/2;
    }
};