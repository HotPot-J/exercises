#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//v1�������ٶ�  v2���ڹ��ٶ� t���������Ⱦ���   s����Ϣ������ l���ܵ�����
void game(int v1,int v2,int t,int s,int l){
	int T = l / v2; //��ʱ�� ��������ѭ��
	int tt = 0;//��¼���ӵ�ʱ��
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