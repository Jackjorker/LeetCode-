/**
 * ��������Ǽ��� ab �� 1337 ȡģ��a ��һ����������b ��һ���ǳ�����������һ���������ʽ������
 * 
 * 
ʾ�� 1��

���룺a = 2, b = [3]
�����8
ʾ�� 2��

���룺a = 2, b = [1,0]
�����1024
ʾ�� 3��

���룺a = 1, b = [4,3,3,8,5,2]
�����1
ʾ�� 4��

���룺a = 2147483647, b = [2,0,0]
�����1198

*/

class Solution {
    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }

public:
    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = (long) ans * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }
};