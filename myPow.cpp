
/**
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

 示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25


 * 
 * 
 * 
*/





class Solution {
public:
    double quickMul(double x, long long N){
       
        //如果n为0，任意x的指数n都是1；
        if( N == 0){
            return 1;
        }
        //定义一个y值，返回向下递归的值
        double y = quickMul(x,N/2);
        //如果N为偶数，返回y*y，如果N为单数，返回y * y * x

        return (N % 2 == 0) ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        //如果指数为正数，正常递归，如果指数为负数，取N的负数进行递归，且取1.0除以该值
        return N >= 0 ? quickMul(x , N) : 1.0 / quickMul(x , -N);
    }
};