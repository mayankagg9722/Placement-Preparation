// A simple algorithm from Wikipedia with C++ implementation (can be used in Permutations and Permutations II)


// Well, in fact the problem of next permutation has been studied long ago. From the Wikipedia page, in the 14th century, a man named Narayana Pandita gives the following classic and yet quite simple algorithm (with minor modifications in notations to fit the problem statement):

// Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
// Find the largest index l greater than k such that nums[k] < nums[l].
// Swap the value of nums[k] with that of nums[l].
// Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
// Quite simple, yeah? Now comes the following code, which is barely a translation.

// Well, a final note here, the above algorithm is indeed powerful — it can handle the cases of duplicates! If you have tried the problems Permutations and Permutations II, then the following function is also useful. Both of Permutations and Permutations II can be solved easily using this function. Hints: sort nums in ascending order, add it to the result of all permutations and then repeatedly generate the next permutation and add it … until we get back to the original sorted condition.
//  If you want to learn more, please visit this solution and that solution.

class Solution {
    void nextPermutation(vector<int>& nums) {
    	int k = -1;
    	for (int i = nums.size() - 2; i >= 0; i--) {
    		if (nums[i] < nums[i + 1]) {
    			k = i;
    			break;
    		}
    	} 
    	if (k == -1) {
    	    reverse(nums.begin(), nums.end());
    	    return;
    	}
    	int l = -1;
    	for (int i = nums.size() - 1; i > k; i--) {
    		if (nums[i] > nums[k]) {
    			l = i;
    			break;
    		} 
    	} 
    	swap(nums[k], nums[l]);
    	reverse(nums.begin() + k + 1, nums.end()); 
    }
}; 