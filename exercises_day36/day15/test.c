#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//v1：兔子速度  v2：乌龟速度 t：兔子领先距离   s：休息多少秒 l：跑道长度
void game(int v1,int v2,int t,int s,int l){
	int T = l / v2; //总时间 用来控制循环
	int tt = 0;//记录兔子的时间
	int s1 = s;
	int rabbit = 0, tortoise = 0;
	while (T){
		if (rabbit >= l){
			break;
		}
		if (rabbit - tortoise >= t){
			while (s1--){
				if (tortoise >= l){
					break;
				}
				tortoise += v2;
				T--;
				tt++;
			}
			s1 = s;
		}
		else{
			rabbit += v1;
			tortoise += v2;
			T--;
			tt++;
		}
	}
	T = l / v2;
	if (rabbit == l&&tortoise==l){
		printf("D\n");
		printf("%d", T);
	}
	else if(rabbit!=l&&tortoise==l){
		printf("T\n");
		printf("%d", T);
	}
	else if (rabbit==l&&tortoise!=l){
		printf("R\n");
		printf("%d", tt);
	}
}

int main(){
	int v1 = 0, v2 = 0, t = 0, s = 0, l = 0;
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	game(v1, v2, t, s, l);
	return 0;
}