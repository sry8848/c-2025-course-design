/*

#include <iostream>
#include <cstdlib>
#include "alumni.h"
#include "Utils.h"
using namespace std;
alumni::alumni(
	std::string userName_="",
	std::string password_="123456",
	std::string name="",
	std::string pinyin = "",
	char gender='\0',
	int age=0,
	int year_of_graduation=0,
	std::string department = "",
	std::string major = "",
	std::string Class = "",
	std::string address = "",
	std::string phoneNumber = "",
	std::string qq = "",
	std::string email = ""
):person(userName_, password_){
	this->name = name;
	this->pinyin = pinyin; // 姓名拼音
	this->gender = gender;
	this->age = age;
	this->year_of_graduation = year_of_graduation;
	this->department = department;
	this->major = major;
	this->Class = Class;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->qq = qq;
	this->email = email;
}
void alumni::create_information() {
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入姓名拼音(示例输入：guozhijin)：";
		cin >> pinyin;
		cout << "请选择性别(输入序号)：\n";
		cout << "1.男" << endl
			<< "2.女" << endl;
		int gender_choice = Utils::getChoice(2);
		if (gender_choice == 1) {
			gender = 'M';
		}
		else if (gender_choice == 2) {
			gender = 'W';
		}
		cout << "请输入年龄：";
		cin >> age;
		cout << "请输入毕业年份：";
		cin >> year_of_graduation;
		cout << "请输入系：";
		cin >> department;
		cout << "请输入专业：";
		cin >> major;
		cout << "请输入班级：";
		cin >> Class;
		cout << "是否显示地址？\n 1.是\n 2.否\n";
		int address_choice = Utils::getChoice(2);
		if (address_choice == 2) {
			address = "保密";
		}
		else {
			cout << "请输入地址：";
			cin >> address;
		}
		cout << "是否显示电话？\n 1.是\n 2.否\n";
		int phone_choice = Utils::getChoice(2);
		if (phone_choice == 2) {
			phoneNumber = "保密";
		}
		else {
			cout << "请输入电话：";
			cin >> phoneNumber;
		}
		cout << "是否显示QQ？\n 1.是\n 2.否\n";
		int qq_choice = Utils::getChoice(2);
		if (qq_choice == 2) {
			qq = "保密";
		}
		else {
			cout << "请输入QQ：";
			cin >> qq;
		}
		cout << "是否显示邮箱？\n 1.是\n 2.否\n";
		int email_choice = Utils::getChoice(2);
		if (email_choice == 2) {
			email = "保密";
		}
		else {
			cout << "请输入邮箱：";
			cin >> email;
		}
}
void alumni::modify_information() {
	cout << "输入要修改信息前的序号：";
	int choice=Utils::getChoice(11);
	int gender_choice = Utils::getChoice(2);
	int address_choice = Utils::getChoice(2);
	int phone_choice = Utils::getChoice(2);
	int qq_choice = Utils::getChoice(2);
	int email_choice = Utils::getChoice(2);
	int continue_choice = Utils::getChoice(2);
	switch (choice) {
	case 1:
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入姓名拼音(示例输入：guozhijin)：";
		cin >> pinyin;
		break;
	case 2:
		cout << "请选择性别(输入序号)：\n";
		cout << "1.男" << endl
			<< "2.女" << endl;
		if (gender_choice == 1) {
			gender = 'M';
		}
		else if (gender_choice == 2) {
			gender = 'W';
		}
		break;
	case 3:
		cout << "请输入年龄：";
		cin >> age;
		break;
	case 4:
		cout << "请输入毕业年份：";
		cin >> year_of_graduation;
		break;
	case 5:
		cout << "请输入系：";
		cin >> department;
		break;
	case 6:
		cout << "请输入专业：";
		cin >> major;
		break;
	case 7:
		cout << "请输入班级：";
		cin >> Class;
		break;
	case 8:
		cout << "是否显示地址？\n 1.是\n 2.否\n";
		if (address_choice == 2) {
			address = "保密";
		}
		else {
			cout << "请输入地址：";
			cin >> address;
		}
		break;

	case 9:
		cout << "是否显示电话？\n 1.是\n 2.否\n";
		
		if (phone_choice == 2) {
			phoneNumber = "保密";
		}
		else {
			cout << "请输入电话：";
			cin >> phoneNumber;
		}
		break;
	case 10:
		cout << "是否显示QQ？\n 1.是\n 2.否\n";
		
		if (qq_choice == 2) {
			qq = "保密";
		}
		else {
			cout << "请输入QQ：";
			cin >> qq;
		}
		break;
	case 11:
		cout << "是否显示邮箱？\n 1.是\n 2.否\n";
	
		if (email_choice == 2) {
			email = "保密";
		}
		else {
			cout << "请输入邮箱：";
			cin >> email;
		}
		break;
	}
	cout<<"是否继续修改？\n 1.是\n 2.否\n";
	
	if (continue_choice == 1) {
		modify_information();
	}
	else if (continue_choice == 2) {
		return;
	}
}
void alumni::show() {
	person::show();
	cout << "校友信息：\n";
	cout <<"1.姓名："<<name<<endl
		 <<"2.性别："<<gender<<endl
		 <<"3.年龄："<<age<<endl
		 <<"4.毕业年份："<<year_of_graduation<<endl
		 <<"5.系："<<department<<endl
		 <<"6.专业："<<major<<endl
		 <<"7.班级："<<Class<<endl
		 <<"8.地址："<<address<<endl
		 <<"9.电话："<<phoneNumber<<endl
		 <<"10.QQ："<<qq<<endl
		 <<"11.邮箱："<< email<<endl;
}
bool alumni::Compare_by_year_up(const alumni& left, const alumni& right){
	return left.year_of_graduation > right.year_of_graduation;
}
bool alumni::Compare_by_year_down(const alumni& left, const alumni& right) {
	return left.year_of_graduation < right.year_of_graduation;
}
bool alumni::Compare_by_name_up(const alumni& left, const alumni& right) {
	return left.pinyin > right.pinyin;
}
bool alumni::Compare_by_name_down(const alumni& left, const alumni& right) {
	return left.pinyin < right.pinyin;
}

*/