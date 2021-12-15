/**
 * ��һ�� n ������Ϊʵ����󣬴� 0 �� n - 1 ��ţ�����ÿ���˶��в�ͬ��Ŀ��Ǯ���Լ���ͬ�̶ȵİ���ֵ��quietness����Ϊ�˷�����������ǽ����Ϊ?x?���˼��Ϊ "person?x?"��

����һ������ richer ������ richer[i] = [ai, bi] ��ʾ person?ai?�� person?bi?����Ǯ�������һ���������� quiet ������?quiet[i] �� person i �İ���ֵ��richer �������������� �߼���ǡ��Ҳ����˵���� person x �� person y ����Ǯ��ͬʱ��������� person y �� person x ����Ǯ����� ����

���ڣ�����һ���������� answer ��Ϊ�𰸣�����?answer[x] = y?��ǰ���ǣ�������ӵ�е�Ǯ�϶�������?person?x?�����У�person?y?��������ˣ�Ҳ���ǰ���ֵ?quiet[y]?��С���ˣ���

?

ʾ�� 1��

���룺richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
�����[5,5,2,5,4,5,6,7]
���ͣ� 
answer[0] = 5��
person 5 �� person 3 �и����Ǯ��person 3 �� person 1 �и����Ǯ��person 1 �� person 0 �и����Ǯ��
Ψһ��Ϊ�������нϵ͵İ���ֵ quiet[x]�������� person 7��
����Ŀǰ����������Ƿ�� person 0 ����Ǯ��
answer[7] = 7��
������ӵ�е�Ǯ�϶������� person 7 �����У�����ܰ��� person 3��4��5��6 �Լ� 7����
������нϵͰ���ֵ quiet[x]�������� person 7��
�����Ĵ�Ҳ���������Ƶ����������͡�
ʾ�� 2��

���룺richer = [], quiet = [0]
�����[0]

 * 
 * 
 * 
 * 
*/






class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        for (auto &r : richer) {
            g[r[1]].emplace_back(r[0]);
        }

        vector<int> ans(n, -1);
        function<void(int)> dfs = [&](int x) {
            if (ans[x] != -1) {
                return;
            }
            ans[x] = x;
            for (int y : g[x]) {
                dfs(y);
                if (quiet[ans[y]] < quiet[ans[x]]) {
                    ans[x] = ans[y];
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        return ans;
    }
};