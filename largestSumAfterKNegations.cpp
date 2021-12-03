/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i?并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

?

示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2：

输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：

输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。



*/



class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        //先对数组进行排序，将负数提到数组前面
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); ++i){
            //在k的范围内按照贪心算法将nums按照负数从小到大取正
            if(nums[i] < 0 && k > 0){
                nums[i] = - nums[i];
                k--;
            }
        }
        //res取得数组之和
        for(int i = 0; i < nums.size(); ++i){
            res += nums[i];
        }
        //负数取正之后进行二次排序，将取得最小正数
        sort(nums.begin(),nums.end());
        //如果k还有剩，如果k为偶数，对最小正数取两次反，如果k为奇数，对最小正数取反 res - 2 * nums[0];
        return res - (k % 2 == 0 ? 0 : 2 * nums[0] )  ;
        
    }
};