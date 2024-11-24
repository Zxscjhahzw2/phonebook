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
int showpeople(phonebook* p) {
	if (p->total == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
		return -1;
	}
	else {
		for (int i = 0; i < p->total; i++) {
			cout << "����:" << p->peo[i].name<<"\t";
			cout << "����:" << p->peo[i].age << "\t";
			cout << "�绰:" << p->peo[i].number << "\t";
			cout << "�Ա�:" << (p->peo[i].sex==1?"��":"Ů") << "\t";
			cout << "סַ:" << p->peo[i].home << endl;
		}
	}

}
int isExist(phonebook* p, string name) {//���������Ƿ���ڣ������ڷ���1�������ڷ���0
	for (int i = 0; i <= p->total; i++) {
		if (name == p->peo[i].name)return i;
	}
	return -1;
}
void deltPeople(phonebook* p, string name) {
	
	if (isExist(p, name) == -1) {
		cout << "û�����" << endl;
	}
	else {
		cout << "��ɾ��" << endl;
		int state = isExist(p, name);
		for (int i = state; i < p->total; i++) {
			p->peo[i] = p->peo[i + 1];
		}
		p->total--;
	}
	system("pause");
	system("cls");
}

void findPeople(phonebook* p, string name) {
	int state;
	state = isExist(p, name);
	if (state == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "����:" << p->peo[state].name << "\t";
		cout << "����:" << p->peo[state].age << "\t";
		cout << "�绰:" << p->peo[state].number << "\t";
		cout << "�Ա�:" << (p->peo[state].sex == 1 ? "��" : "Ů") << "\t";
		cout << "סַ:" << p->peo[state].home << endl;
	}
}

void chanemessage(phonebook* p, string name) {
	int state = isExist(p, name);
	if (state == -1) {
		cout << "�����ڴ���" << endl;
	}
	else {
		int sex = 0;
		cout << "������������";
		cin >> p->peo[state].name;
		cout << "���������䣺";
		cin >> p->peo[state].age;
		while (sex != 1 && sex != 2) {
			cout << "�������Ա𣺣�1�����У�2����Ů��";
			cin >> sex;
			p->peo[state].sex = sex;
		}
		cout << "������סַ��";
		cin >> p->peo[state].home;
		cout << "������绰�ţ�";
		cin >> p->peo[state].number;
		cout << "�޸ĳɹ�" << endl;
	}
}

void clearPeople(phonebook* p) {
	p->total = 0;
	cout << "��ϵ���Ѿ����" << endl;
	system("pause");
	system("cls");
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
		{	
			showpeople(&book);
			system("pause");
			system("cls"); 
		}
			break;
		case 3://ɾ����ϵ��
		{
			int state;
			state=showpeople(&book);
			string name;
			if(state!=-1)
			{
				cout << "����������ɾ�����˵�����:";
				cin >> name;
				deltPeople(&book, name);
			}
		}
			break;
		case 4://������ϵ��
		{
			string name;
			cout << "������������ҵ��˵�����:";
			cin >> name;
			findPeople(&book, name);
			system("pause");
			system("cls");
		}
			
			break;
		case 5://�޸���ϵ��
		{
			showpeople(&book);
			string name;
			if(book.total!=0)
			{
				cout << "�����������޸ĵ��˵�����:";
				cin >> name;
				chanemessage(&book, name);
			}

			system("pause");
			system("cls");
		}
			break;
		case 6://�����ϵ��
			clearPeople(&book);
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