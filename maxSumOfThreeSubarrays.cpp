
/**
 * ����һ���������� nums ��һ������ k ���ҳ���������Ϊ k �������ص�����?3 * k ��ĺ����������飬�����������������顣

���±��������ʽ���ؽ���������е�ÿһ��ֱ�ָʾÿ�����������ʼλ�ã��±�� 0 ��ʼ��������ж������������ֵ�����С��һ����

?

ʾ�� 1��

���룺nums = [1,2,1,2,6,7,5,1], k = 2
�����[0,3,5]
���ͣ������� [1, 2], [2, 6], [7, 5] ��Ӧ����ʼ�±�Ϊ [0, 3, 5]��
Ҳ����ȡ [2, 1], ���ǽ�� [1, 3, 5] ���ֵ����ϸ���
ʾ�� 2��

���룺nums = [1,2,1,2,1,2,1,2,1], k = 2
�����[0,2,4]


 * 
 * 
*/






class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
       vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxTotal = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 3 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx;
                    maxSum12Idx2 = i - k * 2 + 1;
                }
                if (maxSum12 + sum3 > maxTotal) {
                    maxTotal = maxSum12 + sum3;
                    ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
