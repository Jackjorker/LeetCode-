
/**
 * ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn����

 ʾ�� 1��

���룺x = 2.00000, n = 10
�����1024.00000
ʾ�� 2��

���룺x = 2.10000, n = 3
�����9.26100
ʾ�� 3��

���룺x = 2.00000, n = -2
�����0.25000
���ͣ�2-2 = 1/22 = 1/4 = 0.25


 * 
 * 
 * 
*/





class Solution {
public:
    double quickMul(double x, long long N){
       
        //���nΪ0������x��ָ��n����1��
        if( N == 0){
            return 1;
        }
        //����һ��yֵ���������µݹ��ֵ
        double y = quickMul(x,N/2);
        //���NΪż��������y*y�����NΪ����������y * y * x

        return (N % 2 == 0) ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        //���ָ��Ϊ�����������ݹ飬���ָ��Ϊ������ȡN�ĸ������еݹ飬��ȡ1.0���Ը�ֵ
        return N >= 0 ? quickMul(x , N) : 1.0 / quickMul(x , -N);
    }
};