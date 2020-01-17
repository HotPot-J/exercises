#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
问题描述
　　Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。
  　比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。
	所以，他迫切地需要一个系统，然后当他输入12 3456 7009时，会给出相应的念法：
	十二亿三千四百五十六万七千零九
	用汉语拼音表示为
    shi er yi san qian si bai wu shi liu wan qi qian ling jiu
	这样他只需要照着念就可以了。
	你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。
     注意必须严格按照规范，比如说“10010”读作“yi wan ling yi shi”而不是“yi wan ling shi”，
	 “100000”读作“shi wan”而不是“yi shi wan”，“2000”读作“er qian”而不是“liang qian”。
				  输入格式
				  　　有一个数字串，数值大小不超过2,000,000,000。
					输出格式
					　　是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。
					  样例输入
					  1234567009
					  样例输出
					  shi er yi san qian si bai wu shi liu wan qi qian ling jiu
*/
void ReadSystem(int dig){
	char* num[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi" };
	char* wei[] = {  "shi", "bai", "qian", "wan", "yi" };
	char* ret[20];
	int i = 0, k = 0, j = 0, l[2] = {0};
	while (dig>0){
		k = dig % 10;
	    dig /= 10;
		if (k > 0){//k大于0的情况
			if (i>0)
			{
				if (i >= 4 && !l[i / 4 - 1]) //l[]用来记录是第几个4位 第一个4位是万 第二个四位是亿 该题只包含亿 所以定义l[2]
				{                            //i/4是4的几倍 即第几个四的倍数
					l[i / 4 - 1] = 1;
					ret[j++] = wei[i / 4 + 2];
				}
				if (i % 4 != 0){              //每四位又包含十 白 千 所以i%4-1 计算出应该填入十白千中的哪一个 -1是由wei指针数组的尺寸决定的  具体问题具体分析应该-几
					ret[j++] = wei[i % 4 - 1];
				}
			}

			ret[j++] = num[k];


		}
		else if (j>0 && ret[j - 1] != num[0]){ 
			                         //前一个是0后一个也是零 则不用在入0进入ret
				ret[j++] = num[0];
			}
			i++;	
	}
	//输出
	if ((ret[j - 1] == "yi"&&j > 1 && ret[j - 2] == "shi")){

		for (i = j - 2; i >= 0; i--)
			printf("%s ", ret[i]);
	}
	else{
		for (i = j - 1; i >= 0; i--){
			printf("%s ", ret[i]);
		}
	}
}
int main(){
	int dig = 0;
	scanf("%d", &dig);
	ReadSystem(dig);
	return 0;
}


