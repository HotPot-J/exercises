#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
1344. ʱ��ָ��ļн�
���������� hour �� minutes �����㷵����ʱ���ϣ��ɸ���ʱ���ʱ��ͷ�����ɵĽ�С�ǵĽǶȣ�60 ��λ�ƣ���



ʾ�� 1��



���룺hour = 12, minutes = 30
�����165
ʾ�� 2��



���룺hour = 3, minutes = 30
�����75
ʾ�� 3��



���룺hour = 3, minutes = 15
�����7.5
ʾ�� 4��

���룺hour = 4, minutes = 50
�����155
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
