
/**
 * ������ n �Ų�ͬ�����߿γ̣����� 1 �� n?��š�����һ������ courses ������ courses[i] = [durationi, lastDayi] ��ʾ�� i �ſν��� ���� �� durationi ��Σ����ұ����ڲ����� lastDayi ��ʱ����ɡ�

���ѧ�ڴӵ� 1 �쿪ʼ���Ҳ���ͬʱ�޶����ż��������ϵĿγ̡�

�������������޶��Ŀγ���Ŀ��

?

ʾ�� 1��

���룺courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
�����3
���ͣ�
����һ���� 4 �ſγ̣��������������� 3 �ţ�
���ȣ��޵� 1 �ſΣ��ķ� 100 �죬�ڵ� 100 ����ɣ��ڵ� 101 �쿪ʼ���ſΡ�
�ڶ����޵� 3 �ſΣ��ķ� 1000 �죬�ڵ� 1100 ����ɣ��ڵ� 1101 �쿪ʼ���ſγ̡�
�������޵� 2 �ſΣ���ʱ 200 �죬�ڵ� 1300 ����ɡ�
�� 4 �ſ����ڲ����ޣ���Ϊ�����ڵ� 3300 ������������Ѿ������˹ر����ڡ�
ʾ�� 2��

���룺courses = [[1,2]]
�����1
ʾ�� 3��

���룺courses = [[3,2],[4,3]]
�����0


 * 
 * 
 * 
 * 
*/





class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
        });

        priority_queue<int> q;
        // ���ȶ��������пγ̵���ʱ��
        int total = 0;

        for (const auto& course: courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            }
            else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }

        return q.size();
    }
};

