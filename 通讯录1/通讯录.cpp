#include <iostream>
using namespace std;
#include<string>
#define MAX 100

struct people {
	string name;
	int age;
	string number;
	int sex = 0;//�Ա�1�У��Ա�2Ů
	string home;
};
struct phonebook {
	struct people peo[MAX];
	int total = 0;//��¼������

};
void show_menu() {
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

void addpeople(phonebook* p)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (p->total == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��
		/*string name;*/
		cout << "������������";
		cin >> p->peo[p->total].name;
		/*p->peo[p->total].name = name;*/
		/*cout << p->peo[p->total].name << endl;*/
		cout << "���������䣺";
		cin >> p->peo[p->total].age;
		while (p->peo[p->total].sex != 1 && p->peo[p->total].sex != 2) {
			cout << "�������Ա𣺣�1�����У�2����Ů��";
			cin >> p->peo[p->total].sex;
		}
		cout << "������סַ��";
		cin >> p->peo[p->total].home;
		cout << "������绰�ţ�";
		cin >> p->peo[p->total].number;
		cout << "����ɹ�" << endl;

		//����ͨѶ¼����
		p->total++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�����������
		system("cls");//	����
	}
}

int main() {
	int select_state = 1;
	int select = 0;//�����û�ѡ������ı���
	phonebook book;
	while (select_state) {
		show_menu();
		cin >> select;
		if (select == 0)select_state = 0;
		switch (select)
		{
		case 1://�����ϵ��
			addpeople(&book);
			break;
		case 2://��ʾ��ϵ��
			break;
		case 3://ɾ����ϵ��
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 6://�����ϵ��
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}