#define _CRT_SECURE_NO_WARNINGS 1
/*��������
���Ĵ�����һ��������ַ��������������Ҷ��ʹ����������һ���ġ�С������Ϊ���Ĵ����������ġ����ڸ���һ����������һ���ǻ��ĵģ�����������ٵĽ�������ʹ�øô����һ�������Ļ��Ĵ���
�����Ķ����ǣ������������ڵ��ַ�
����mamad
��һ�ν��� ad : mamda
�ڶ��ν��� md : madma
�����ν��� ma : madam(���ģ�������)
�����ʽ
��һ����һ������N����ʾ���������ַ����ĳ���(N <= 8000)
�ڶ�����һ���ַ���������ΪN.ֻ����Сд��ĸ
�����ʽ
������ܣ�������ٵĽ���������
�������Impossible
��������
5
mamad
�������
3
*/
#include<stdio.h>
#include<stdlib.h>
//�����ɻ��ĵ������������ NΪ���� �������ַ��������� �򲻹���
//                         NΪż�� ��һ���ַ��������� �򲻹��� 
int main(){
	int N = 0;
	int n = 0;
	int alone = 0; //��¼�����ַ��ĸ���
	int ok = 1, time = 0 ;
	char tmp = '0';
	char* arr = NULL;
	int i = 0, j = 0, k = 0;
	scanf("%d", &N);
	n = N-1;
	arr = (char *)malloc((N + 1)*sizeof(char));
	scanf("%s", arr);
	for (i = 0; i < n; i++){ //������
		for (j = n; j>=i; j--){//���ҵ���
			if (i == j){ // ûƥ����
				alone++;
				if (N % 2 == 0 || alone >= 2){ //��ûƥ���ϵ������ ���N��Ϊż�� �� �������������ڵ���2���޷�����
					ok = 0;
					break;
				}
				else{
					time += (N / 2 - i); //�����ַ��Ƶ��м�����Ҫ�Ĳ���
					break;
				}
			}
			if (arr[i] == arr[j]){ // ƥ������
				for (k = j; k <n; k++){
					tmp=arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = tmp;
					time++;
				}
				n--;//ÿ�ν�j������һ�ξͲ��ùܸ���ĸ��
				break;
			}

		}
		if (!ok){
			break;
		}
	}
	if (!ok){
		printf("Impossible");
	}
	else{
		printf("%d", time);
	}
	free(arr);
	return 0;
}