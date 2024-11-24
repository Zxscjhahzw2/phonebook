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
			break;
		case 3://删除联系人
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 6://清空联系人
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