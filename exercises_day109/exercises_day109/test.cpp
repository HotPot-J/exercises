#define _CRT_SECURE_NO_WARNINGS 1

/*
1、洗牌
	洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。现在需要洗2n张牌，从上到下依次是第一张，第二张，
	第三张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），
	右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，
	再放左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到
	放下左手的第一张牌。接着把牌合并即可。
	假设6张牌，最开始123456.分为2组 左：123 右：456 在洗牌过程中按顺序放下了635241，从上
	往下看牌序位:142536。现在给出一个原始牌组，请输出这副牌洗牌K次之后从上往下的序列
	输入描述:
		第一行 T 代表几组数据
		第二行 n k  代表2n个数据，洗牌k次
		第三行 2n张牌
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void func(vector<int>&arr,vector<int>&left,vector<int>&right){
	int i = left.size() - 1, j = right.size() - 1;
	arr.clear();
	while (i >=0 && j >=0){
		arr.push_back(right[j--]);
		arr.push_back(left[i--]);
	}
	reverse(arr.begin(), arr.end());
}
int main(){
	int group = 0, n = 0, k = 0;
	cin >> group;
	while (group--){
		cin >> n >> k;
		vector<int> arr;
		int tmp = 0;
		for (int i = 0; i < 2 * n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		while (k--){
			vector<int> left, right;
			for (int i = 0; i < 2 * n; ++i){
				if (i < n){
					left.push_back(arr[i]);
				}
				else{
					right.push_back(arr[i]);
				}
			}
			func(arr, left, right);
		}
		for (auto t : arr){
			cout << t<<" ";
		}
		cout<<endl;
	}

	return 0;
}

/*
2、MP3光标位置
MP3Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览
所有歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始位置为第一首歌。
现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：
	1.歌曲总数<=4的时候，不需要翻页，只是挪动光标的位置。
	光标在第一首歌曲上时候按up键光标移动到最后一首歌曲；光标在最后一首歌曲时，按Down键
	光标到第一首歌曲。
	其他情况，用户按Up，光标移动到上一首，Down挪动到下一首
	2.歌曲总数大于4(以一共10首为例)
	特殊翻页：屏幕显示的是第一页（即1-4），光标在第一首歌曲上，用户按UP键后，屏幕要
	显示最后一页(7-10)，同时光标放到最后一首歌曲上，用户按down，屏幕显示第一页，光标移动
	到第一首歌上。
	一般翻页:屏幕不是第一页，光标在当前屏幕显示的第一首歌曲时，用户按up键后，屏幕从当前
	歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的down键处理
	也类似。
*/