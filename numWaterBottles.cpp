/**
 * 小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。

?示例1
输入：numBottles = 9, numExchange = 3
输出：13
解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 9 + 3 + 1 = 13 瓶酒。


示例2
输入：numBottles = 15, numExchange = 4
输出：19
解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 15 + 3 + 1 = 19 瓶酒。

*/






class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;//定义结果，无论所买瓶数是否大于numExchange，结果都至少喝了所买瓶数
        int bottles = numBottles ;//定义空瓶数，一开始空瓶数是所买瓶数
        while(bottles >= numExchange){//设定循环条件，空瓶数大于等于numExchange才能继续换酒
            //if(bottles /numExchange > 0)这个判断条件上面已经判定了，多余
            ans += (bottles / numExchange);//结果加上bottles / numExchange，也就是加上空瓶兑换的酒
            bottles = bottles / numExchange + bottles % numExchange;//更新空瓶的数量
        }
        return ans;//返回结果
    }
};