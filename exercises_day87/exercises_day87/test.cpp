#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
765. ����ǣ��
N �����������������е� 2N ����λ�ϣ���Ҫǣ���Է����֡� �������ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ�� һ�ν�����ѡ���������ˣ�������վ����������λ��

�˺���λ�� 0 �� 2N-1 ��������ʾ�������ǰ�˳���ţ���һ���� (0, 1)���ڶ����� (2, 3)���Դ����ƣ����һ���� (2N-2, 2N-1)��

��Щ���µĳ�ʼ��λ  row[i] �������ʼ���ڵ� i ����λ�ϵ��˾����ġ�

ʾ�� 1:

����: row = [0, 2, 1, 3]
���: 1
����: ����ֻ��Ҫ����row[1]��row[2]��λ�ü��ɡ�
ʾ�� 2:

����: row = [3, 2, 0, 1]
���: 0
����: ���轻����λ�����е����¶��Ѿ�������ǣ���ˡ�
˵��:

len(row) ��ż������ֵ�� [4, 60]��Χ�ڡ�
���Ա�֤row ������ 0...len(row)-1 ��һ��ȫ���С�
*/
class Solution {
public:
vector<int> parent, size;

int findroot(int x)
{
if (x != parent[x]) {
parent[x] = findroot(parent[x]);
}
return parent[x];
}

void uni(int x, int y)
{
int xroot = findroot(x);
int yroot = findroot(y);
if (xroot != yroot) {
if (size[xroot] < size[yroot]) {
parent[xroot] = yroot;
size[yroot] += size[xroot];
} else {
parent[yroot] = xroot;
size[xroot] += size[yroot];
}
}
}

int minSwapsCouples(vector<int> &row)
{
int N = row.size() / 2; // 2������
int N2 = row.size();
parent = vector<int>(N, 0);
size = vector<int>(N, 1);
for (int i = 0; i < N; i++) {
parent[i] = i;
}

for (int i = 0; i < N2; i += 2) {    // 2������
uni(row[i] / 2, row[i + 1] / 2);  // 2������
}

int circle = 0;
for (int i = 0; i < N; i++) {
// if(i != parent[i]){
if (i != findroot(i)) {
circle++;
}
}
return circle;
}
};


