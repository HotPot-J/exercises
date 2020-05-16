#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1344. 时钟指针的夹角
给你两个数 hour 和 minutes 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。



示例 1：



输入：hour = 12, minutes = 30
输出：165
示例 2：



输入：hour = 3, minutes = 30
输出；75
示例 3：



输入：hour = 3, minutes = 15
输出：7.5
示例 4：

输入：hour = 4, minutes = 50
输出：155
*/

class Solution {
public:
	double angleClock(int hour, int minutes) {
		int oneMinAngle = 6;
		int oneHourAngle = 30;

		double minutesAngle = oneMinAngle * minutes;
		double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

		double diff = abs(hourAngle - minutesAngle);
		return min(diff, 360 - diff);
	}
};
