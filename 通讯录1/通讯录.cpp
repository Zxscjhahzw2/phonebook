#include <iostream>
using namespace std;
#include<string>
#define MAX 100

struct people {
	string name;
	int age;
	string number;
	int sex = 0;//性别1男，性别2女
	string home;
};
struct phonebook {
	struct people peo[MAX];
	int total = 0;//记录总人数

};
void show_menu() {
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

void addpeople(phonebook* p)
{
	//判断通讯录是否已满
	if (p->total == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//添加具体联系人
		/*string name;*/
		cout << "请输入姓名：";
		cin >> p->peo[p->total].name;
		/*p->peo[p->total].name = name;*/
		/*cout << p->peo[p->total].name << endl;*/
		cout << "请输入年龄：";
		cin >> p->peo[p->total].age;
		while (p->peo[p->total].sex != 1 && p->peo[p->total].sex != 2) {
			cout << "请输入性别：（1代表男，2代表女）";
			cin >> p->peo[p->total].sex;
		}
		cout << "请输入住址：";
		cin >> p->peo[p->total].home;
		cout << "请输入电话号：";
		cin >> p->peo[p->total].number;
		cout << "保存成功" << endl;

		//更新通讯录人数
		p->total++;
		cout << "添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");//	清屏
	}
}
int showpeople(phonebook* p) {
	if (p->total == 0) {
		cout << "当前记录为空" << endl;
		return -1;
	}
	else {
		for (int i = 0; i < p->total; i++) {
			cout << "姓名:" << p->peo[i].name<<"\t";
			cout << "年龄:" << p->peo[i].age << "\t";
			cout << "电话:" << p->peo[i].number << "\t";
			cout << "性别:" << (p->peo[i].sex==1?"男":"女") << "\t";
			cout << "住址:" << p->peo[i].home << endl;
		}
	}

}
int isExist(phonebook* p, string name) {//检查这个人是否存在，若存在返回1，不存在返回0
	for (int i = 0; i <= p->total; i++) {
		if (name == p->peo[i].name)return i;
	}
	return -1;
}
void deltPeople(phonebook* p, string name) {
	
	if (isExist(p, name) == -1) {
		cout << "没这个人" << endl;
	}
	else {
		cout << "已删除" << endl;
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
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名:" << p->peo[state].name << "\t";
		cout << "年龄:" << p->peo[state].age << "\t";
		cout << "电话:" << p->peo[state].number << "\t";
		cout << "性别:" << (p->peo[state].sex == 1 ? "男" : "女") << "\t";
		cout << "住址:" << p->peo[state].home << endl;
	}
}

void chanemessage(phonebook* p, string name) {
	int state = isExist(p, name);
	if (state == -1) {
		cout << "不存在此人" << endl;
	}
	else {
		int sex = 0;
		cout << "请输入姓名：";
		cin >> p->peo[state].name;
		cout << "请输入年龄：";
		cin >> p->peo[state].age;
		while (sex != 1 && sex != 2) {
			cout << "请输入性别：（1代表男，2代表女）";
			cin >> sex;
			p->peo[state].sex = sex;
		}
		cout << "请输入住址：";
		cin >> p->peo[state].home;
		cout << "请输入电话号：";
		cin >> p->peo[state].number;
		cout << "修改成功" << endl;
	}
}

void clearPeople(phonebook* p) {
	p->total = 0;
	cout << "联系人已经清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	int select_state = 1;
	int select = 0;//创建用户选择输入的变量
	phonebook book;
	while (select_state) {
		show_menu();
		cin >> select;
		if (select == 0)select_state = 0;
		switch (select)
		{
		case 1://添加联系人
			addpeople(&book);
			break;
		case 2://显示联系人
		{	
			showpeople(&book);
			system("pause");
			system("cls"); 
		}
			break;
		case 3://删除联系人
		{
			int state;
			state=showpeople(&book);
			string name;
			if(state!=-1)
			{
				cout << "请输入你想删除的人的姓名:";
				cin >> name;
				deltPeople(&book, name);
			}
		}
			break;
		case 4://查找联系人
		{
			string name;
			cout << "请输入你想查找的人的姓名:";
			cin >> name;
			findPeople(&book, name);
			system("pause");
			system("cls");
		}
			
			break;
		case 5://修改联系人
		{
			showpeople(&book);
			string name;
			if(book.total!=0)
			{
				cout << "请输入你想修改的人的姓名:";
				cin >> name;
				chanemessage(&book, name);
			}

			system("pause");
			system("cls");
		}
			break;
		case 6://清空联系人
			clearPeople(&book);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}