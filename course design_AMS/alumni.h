#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
#include <iostream>
#include <cstdlib>
#include "alumni.h"
#include "Utils.h"
using namespace std;
class alumni :public person {
public:
	std::string getName() const { return name; }
	std::string getPinyin() const { return pinyin; } // 获取姓名拼音
	std::string getDepartment() const { return department; }
	std::string getMajor() const { return major; }
	std::string getClass() const { return Class; }
	int getAge() const { return age; }
	int getGraduationYear() const { return year_of_graduation; }
	std::string getAddress() const { return address; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getQQ() const { return qq; }
	std::string getEmail() const { return email; }
	int getGender() const { return gender; }

	alumni(
		std::string userName_ = "",
		std::string password_ = "123456",
		std::string name = "",
		std::string pinyin = "",
		char gender = '\0',
		int age = 0,
		int year_of_graduation = 0,
		std::string department = "",
		std::string major = "",
		std::string Class = "",
		std::string address = "",
		std::string phoneNumber = "",
		std::string qq = "",
		std::string email = ""
	) :person(userName_, password_) {
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
	void create_information() {
		cout << "请输入姓名：";
		cin >> name;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
		cout << "请输入姓名拼音(示例输入：guozhijin)：";
		pinyin= Utils::pinyinInput(); //验证是否全为字母输入，转换为string类型
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
		age = stoi(Utils::onlyNumberInput());//验证是否全为数字输入，转换为int类型
		cout << "请输入毕业年份：";
		year_of_graduation = stoi(Utils::onlyNumberInput());
		cout << "请输入系：";
		cin >> department;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
		cout << "请输入专业：";
		cin >> major;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
		cout << "请输入班级(示例输入：01)：";
		Class = (Utils::onlyNumberInput());
		cout << "是否显示地址？\n 1.是\n 2.否\n";
		int address_choice = Utils::getChoice(2);
		if (address_choice == 2) {
			address = "保密";
		}
		else {
			cout << "请输入地址：";
			cin >> address;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
		}
		cout << "是否显示电话？\n 1.是\n 2.否\n";
		int phone_choice = Utils::getChoice(2);
		if (phone_choice == 2) {
			phoneNumber = "保密";
		}
		else {
			cout << "请输入电话：";
			phoneNumber = (Utils::onlyNumberInput());
		}
		cout << "是否显示QQ？\n 1.是\n 2.否\n";
		int qq_choice = Utils::getChoice(2);
		if (qq_choice == 2) {
			qq = "保密";
		}
		else {
			cout << "请输入QQ：";
			qq = (Utils::onlyNumberInput());
		}
		cout << "是否显示邮箱？\n 1.是\n 2.否\n";
		int email_choice = Utils::getChoice(2);
		if (email_choice == 2) {
			email = "保密";
		}
		else {
			cout << "请输入邮箱：";
			cin >> email;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
		}
	}
	void modify_information() {
		cout << "输入要修改信息前的序号：";
		int choice = Utils::getChoice(11);
		int gender_choice;
		int address_choice;
		int phone_choice;
		int qq_choice;
		int email_choice;
		int continue_choice;
		string name_;
		string department_;
		string major_;
		string address_;
		string email_;
		switch (choice) {
		case 1:
			cout << "请输入姓名：";
			cin >> name_;
			name = name_; // 更新person类中的用户名
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			cout << "请输入姓名拼音(示例输入：guozhijin)：";
			pinyin = Utils::pinyinInput(); //验证是否全为字母输入，转换为string类型
			break;
		case 2:
			gender_choice = Utils::getChoice(2);
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
			age = stoi(Utils::onlyNumberInput());//验证是否全为数字输入，转换为int类型
			break;
		case 4:
			cout << "请输入毕业年份：";
			year_of_graduation = stoi(Utils::onlyNumberInput());
			break;
		case 5:
			cout << "请输入系：";
			cin >> department_;
			department = department_;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			break;
		case 6:
			cout << "请输入专业：";
			cin >> major_;
			major = major_;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			break;
		case 7:
			cout << "请输入班级：";
			Class = (Utils::onlyNumberInput());
			break;
		case 8:
			cout << "是否显示地址？\n 1.是\n 2.否\n";
			address_choice = Utils::getChoice(2);
			if (address_choice == 2) {
				address = "保密";
			}
			else {
				cout << "请输入地址：";
				cin >> address_;
				address = address_; // 更新地址信息
				cin.clear(); // 清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			}
			break;

		case 9:
			cout << "是否显示电话？\n 1.是\n 2.否\n";
			phone_choice = Utils::getChoice(2);
			if (phone_choice == 2) {
				phoneNumber = "保密";
			}
			else {
				cout << "请输入电话：";
				phoneNumber = (Utils::onlyNumberInput());//验证是否全为数字输入，转换为string类型
			}
			break;
		case 10:
			cout << "是否显示QQ？\n 1.是\n 2.否\n";
			qq_choice = Utils::getChoice(2);
			if (qq_choice == 2) {
				qq = "保密";
			}
			else {
				cout << "请输入QQ：";
				qq = (Utils::onlyNumberInput());//验证是否全为数字输入，转换为string类型
			}
			break;
		case 11:
			cout << "是否显示邮箱？\n 1.是\n 2.否\n";
			email_choice = Utils::getChoice(2);
			if (email_choice == 2) {
				email = "保密";
			}
			else {
				cout << "请输入邮箱：";
				cin >> email_;
				email = email_; // 更新邮箱信息
				cin.clear(); // 清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			}
			break;
		}
		cout << "是否继续修改？\n 1.是\n 2.否\n";
		continue_choice = Utils::getChoice(2);
		if (continue_choice == 1) {
			modify_information();
		}
		else if (continue_choice == 2) {
			return;
		}
	}
	void show() {
		person::show();
		cout << "校友信息：\n";
		cout << "1.姓名：" << name << endl;
		if (gender == 'M') {
			cout << "2.性别：男"<< endl;
		}
		else if (gender == 'W') {
			cout << "2.性别：女" << endl;
		}
		else {
			cout << "2.性别：未知" << endl;
		}
		cout<< "3.年龄：" << age << endl
			<< "4.毕业年份：" << year_of_graduation << endl
			<< "5.系：" << department << endl
			<< "6.专业：" << major << endl
			<< "7.班级：" << Class << endl
			<< "8.地址：" << address << endl
			<< "9.电话：" << phoneNumber << endl
			<< "10.QQ：" << qq << endl
			<< "11.邮箱：" << email << endl;
		cout << endl;
	}
	static bool Compare_by_year_up(const alumni& left, const alumni& right) {
		return left.year_of_graduation > right.year_of_graduation;
	}
	static bool Compare_by_year_down(const alumni& left, const alumni& right) {
		return left.year_of_graduation < right.year_of_graduation;
	}
	static bool Compare_by_name_up(const alumni& left, const alumni& right) {
		return left.pinyin > right.pinyin;
	}
	static bool Compare_by_name_down(const alumni& left, const alumni& right) {
		return left.pinyin < right.pinyin;
	}

private:
	std::string name;
	std::string pinyin; // 姓名拼音
	char gender='\0';//非string,要设置初始值,否则编译器会报错
	int age=0;
	int year_of_graduation=0;
	std::string department;//系
	std::string major;//专业
	std::string Class;//班级
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
};
