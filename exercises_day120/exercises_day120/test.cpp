#define _CRT_SECURE_NO_WARNINGS 1

/*
1、淘宝网店(牛客)

NowCoder在淘宝上开了一家网店，他发现在月份为素数的时候，每天能赚1元，否则
每天2元
现在给你一段区间，请你帮他计算总收益有多少
*/

/*
思路：求素数  区别闰年平年 大月小月
*/
#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
	if (n < 2){
		return false;
	}
	if (n == 2){
		return true;
	}
	if (n % 2 == 0){
		return false;
	}
	for (int i = 3; i*i <= n; i += 2) {
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

//判断闰年
bool Year(int year){
	if (year%400==0||(year % 4 == 0 && year % 100 != 0)){
		return true;
	}
	
	return false;
}

void func(int* y,int year1,int year2,int month1,int month2,int day1,int day2,int& prime_day,int& _day){
	//计算年份相等时的prime_day和_day
	if (month1 == month2){
		if (isPrime(month1)){
			prime_day = day2 - day1 + 1;
		}
		else{
			_day = day2 - day1 + 1;
		}
	}
	else{
		for (int i = month1; i <= month2; ++i){
			if (i == 2){
				if (Year(year1)){
					if (i == month1){
						prime_day += (y[i] + 1 - day1 + 1);
					}
					else if (i == month2){
						prime_day += day2;
					}
					else{
						prime_day += (y[i] + 1);
					}
				}
				else{
					if (i == month1){
						prime_day += (y[i] - day1 + 1);
					}
					else if (i == month2){
						prime_day += day2;
					}
					else{
						prime_day += (y[i]);
					}
				}
			}
			else{
				if (isPrime(i)){
					if (i == month1){
						prime_day += (y[i] - day1 + 1);
					}
					else if (i == month2){
						prime_day += day2;
					}
					else{
						prime_day += y[i];
					}
				}
				else{
					if (i == month1){
						_day += (y[i] - day1 + 1);
					}
					else if (i == month2){
						_day += day2;
					}
					else
					{
						_day += y[i];
					}

				}
			}
		}
	}
}

//int main(){
//	int year1 = 0,year2 = 0, month1 = 0,month2 = 0, day1 = 0,day2 = 0;
//	int y[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin>>year1>>month1>>day1>>year2>>month2>>day2){
//		int prime_day = 0, _day = 0;
//		if (year1 == year2){
//			func(y, year1, year2, month1, month2, day1, day2, prime_day, _day);
//		}
//		else{
//			for (int i = year1; i <= year2; ++i){
//				if (i == year1){
//					func(y, i, i, month1, 12, day1, 31, prime_day, _day);
//				}
//				else if (i == year2){
//					func(y, i, i, 1, month2, 1, day2, prime_day, _day);
//				}
//				else{
//					func(y, i, i, 1, 12, 1, 31, prime_day, _day);
//				}
//			}
//		}
//		int res = prime_day + _day * 2;
//		cout << res << endl;
//	}
//	return 0;
//}


/*
2、斐波那契凤尾
*/

/*
思路:求斐波那契数  非递归 (递归肯定超时	)
*/

#include<iostream>
using namespace std;

int main(){
	int n = 0;
	int arr[100001] = { 0 };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 100001; ++i){
		//后6位即只需要存后六位的加法进位后的结果
			arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000;
	}
	while (cin >> n){
		printf((n < 25 ? "%d\n" : "%06d\n"), arr[n]);
	}
	return 0;
}