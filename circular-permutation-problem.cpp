#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
double minLength = 1e5; //��СԲ���г��� 
double x[maxn], r[maxn]; //�洢ÿ��Բ�ĵĺ������ÿ��Բ�İ뾶 
double bestR[maxn];
int n;

double get_center(int t){
	double tmp = 0;
	for (int i = 1; i < t; ++i){
		double val = x[i] + 2.0 * sqrt(r[t] * r[i]); //Ŀ��ԲT�п����ܹ���������֮ǰ������һ��Բ���У������Ҫ��һ�ж�ȡ���ֵ
		tmp = max(tmp, val);
	}
	return tmp;
}

void get_ans(){
	double minn = 0, maxx = 0; // ��������Բ���е�����˺����Ҷ�
	for (int i = 1; i <= n ; i++){
		if (x[i] - r[i] < minn) minn = x[i] - r[i];
		if (x[i] + r[i] > maxx) maxx = x[i] + r[i];
	}
	if (maxx - minn < minLength){
		minLength = maxx - minn; // ������СԲ����
		for (int i = 1; i <= n ; ++i)
			bestR[i] = r[i];
	}
}

void dfs(int pos){
	if (pos == n + 1)
		get_ans();
	else{
		for (int i = pos; i <= n; ++i){
			swap(r[pos], r[i]);//����ȫ����
			double X_pos = get_center(pos);//��ȡ��ǰ
			if (X_pos + r[pos] + r[1] < minLength){ //���㵱ǰ����µ�Բ���г��ȣ�������ȴ�����СԲ���г��ȣ��ɴ�Բ���������ɵ�Բ���г���һ����������СԲ���У��ɷ�������
				x[pos] = X_pos;
				dfs(pos + 1);
			}
			swap(r[pos], r[i]); //����ȫ����
		}
	}
}

int main(){
	cout << "������Բ������" << endl;
	cin >> n;
	cout << "������ÿ��Բ�İ뾶" << endl;
	for (int i = 1; i <= n; ++i)
		cin >> r[i];
	dfs(1);
	cout << "��СԲ���г���Ϊ��" << minLength << endl;
	cout << "����Բ���е�˳���Ӧ�İ뾶�ֱ��ǣ�";
	for (int i = 1; i <= n; ++i)
		cout << bestR[i] << " ";
	cout << endl;
	return 0;
}
