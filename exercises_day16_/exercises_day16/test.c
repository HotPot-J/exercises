#define _CRT_SECURE_NO_WARNINGS 1

/*
��������
���������������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��
  ����1�������ַ������Ȳ��ȡ����� Beijing �� Hebei
	��2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing
	  3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2�������� beijing �� BEIjing
	  4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing
		  ������ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
			�����ʽ
			�����������У�ÿ�ж���һ���ַ���
			  �����ʽ
			  ��������һ�����֣������������ַ����Ĺ�ϵ���
				��������
				BEIjing
				beiJing
				�������
				3
*/
//#include<stdio.h>
//#include<string.h>
//int main(){
//	char str1[10] = { '0' };
//	char str2[10] = { '0' };
//	char *strA = NULL;
//	char *strB = NULL;
//	int flag = 0;
//	int a = 0;
//	int b = 0;
//	scanf("%s", str1);
//	scanf("%s", str2);
//	a = strlen(str1);
//	b = strlen(str2);
//	if (a == b){//�������
//		strA = str1;
//		strB = str2;
//		while (*strA == *strB && *strA){ //����ض��ַ�
//			strA++;
//			strB++;
//			flag++;
//		}
//		if (flag == a){//����������ַ���ȫһ��
//			flag = 0;
//			strA = str1;
//			strB = str2;
//			printf("%d", 2);
//		}
//		else{//���ִ�Сд�����
//			while (*strA){
//				if (*strA == *strB){
//					strA++;
//					strB++;
//					flag++;
//				}
//				else{
//					if (*strA + 32 == *strB || *strA - 32 == *strB || *strB + 32 == *strA || *strB - 32 == *strA) {
//						strA++;
//						strB++;
//						flag++;
//					}
//					else{
//						strA++;
//						strB++;
//					}
//
//				}
//
//			}
//			if (flag == a){//������� ���ڲ����ִ�Сд����������ַ������
//				printf("%d", 3);
//			}
//			else{
//				printf("%d", 4); //���������
//			}
//			
//		}
//	}
//	else{//���Ȳ���
//		printf("%d", 1);
//	}
//	return 0;
//}
