/**
 * 给你一个字符串?date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

?

示例 1：

输入：date = "2019-01-09"
输出：9
示例 2：

输入：date = "2019-02-10"
输出：41
示例 3：

输入：date = "2003-03-01"
输出：60
示例 4：

输入：date = "2004-03-01"
输出：61


 * 
 * 
 * 
 * 
 * 
 * 
*/



class Solution {
public:
    int dayOfYear(string date) {
        //定义int类型年份，从string日期中获取年份
        int year = stoi(date.substr(0, 4));
        ///定义int类型月份，从string日期中获取月份
        int month = stoi(date.substr(5, 2));
        ///定义int类型日期，从string日期中获取日期
        int day = stoi(date.substr(8, 2));
        //定义月份包含天数的数组，方便加减
        int amount[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        //判读年份是否为闰年，如果是闰年，则2月份有29天
        if(year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
            amount[1]++;
        //定义返回结果int类型
        int ans = 0;
        //for循环月份，将每一个月的日期累加至结果
        for(int i = 0; i < month - 1 ; ++i){
            ans += amount[i];
        }
        //加最后一个月的具体日期，返回最终结果
        ans += day;
        return ans;
    }
};