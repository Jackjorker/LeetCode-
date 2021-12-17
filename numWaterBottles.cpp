/**
 * С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�

����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�

������� ��� �ܺȵ�����ƿ�ơ�

?ʾ��1
���룺numBottles = 9, numExchange = 3
�����13
���ͣ�������� 3 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 9 + 3 + 1 = 13 ƿ�ơ�


ʾ��2
���룺numBottles = 15, numExchange = 4
�����19
���ͣ�������� 4 ���վ�ƿ�һ� 1 ƿ�ơ�
��������ܺȵ� 15 + 3 + 1 = 19 ƿ�ơ�

*/






class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;//����������������ƿ���Ƿ����numExchange����������ٺ�������ƿ��
        int bottles = numBottles ;//�����ƿ����һ��ʼ��ƿ��������ƿ��
        while(bottles >= numExchange){//�趨ѭ����������ƿ�����ڵ���numExchange���ܼ�������
            //if(bottles /numExchange > 0)����ж����������Ѿ��ж��ˣ�����
            ans += (bottles / numExchange);//�������bottles / numExchange��Ҳ���Ǽ��Ͽ�ƿ�һ��ľ�
            bottles = bottles / numExchange + bottles % numExchange;//���¿�ƿ������
        }
        return ans;//���ؽ��
    }
};