#include <iostream>
#include <cstdlib>
#include "alumni_list.h"
#include "Utils.h"
using namespace std;
int Utils::getChoice(int numberOfChoices) {//定义无需写static
	int choice;
	cin >> choice;
	cin.clear(); // 清除错误标志
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
	if (choice >= 1 && choice <= numberOfChoices) {
		return choice;
	}
	else {
		cout << "输入错误！请正确输入选项前序号（示例输入：1）\n" << endl;
		return getChoice(numberOfChoices);
	}
}
int Utils::getChoice_0stop(int numberOfChoices) {
	int choice;
	cin >> choice;
	cin.clear(); // 清除错误标志
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
	if (choice >= 0 && choice <= numberOfChoices) {
		return choice;
	}
	else {
		cout << "输入错误！请正确输入选项前序号（示例输入：1）\n" << endl;
		return getChoice(numberOfChoices);
	}
}
string Utils::pinyinInput(){
	string input;
	if (!getline(cin, input)) {//getline会吃掉换行符，导致后面有ignore就需要新输入换行符
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
	}
	for (char& c : input) {
		if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')&&!(c==' ')) {
			cin.clear(); // 清除错误标志
			cout << "输入错误！请重新输入拼音（只允许字母）:";
			return pinyinInput();
		}
		c = tolower(c); // 转换为小写字母
	}
	return input;
}
string Utils::onlyNumberInput() {
	string input;
	if (!getline(cin, input)) {//getline会吃掉换行符，导致后面有ignore就需要新输入换行符
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
	}
	for (char c : input) {
		if (!(c >= '0' && c <= '9')) {
			cin.clear(); // 清除错误标志
			cout << "输入错误！只允许输入数字，请重新输入:";
			return onlyNumberInput();
		}
	}
	return input;
}
string Utils::modifyPassword(string prePassword) {
	cout << "密码：";
	string new_password;
	getline(cin, new_password);//防止空格后残留字符
	if (new_password == prePassword) {
		cout << "新密码不能与原密码相同！\n" << endl;
		cout << "-------------------------\n"
			<< "选项：\n"
			<< "1.重新输入\n"
			<< "2.放弃输入\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modifyPassword(prePassword);
		}
		else if (choice == 2) {
			return prePassword;
		}
	}
	if (new_password.length() < 6) {
		cout << "密码长度不能小于6位！\n" << endl;
		cout << "-------------------------\n"
			<< "选项：\n"
			<< "1.重新输入\n"
			<< "2.放弃输入\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modifyPassword(prePassword);
		}
		else if (choice == 2) {
			return prePassword;
		}
	}
	else if (new_password.length() > 20) {
		cout << "密码长度不能大于20位！\n" << endl;
		cout << "-------------------------\n"
			<< "选项：\n"
			<< "1.重新输入\n"
			<< "2.放弃输入\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modifyPassword(prePassword);
		}
		else if (choice == 2) {
			return prePassword;
		}
	}
	else {
		return new_password;
	}
}
	int Utils::search_return_weight(const std::string& str, const std::string& key) {
		int weight = 0;
		if (str == key) {//完全匹配权重极高
			return 100;
		}
		// 2. 子串匹配：权重次高（返回2倍子串长度）
		if (str.find(key) != std::string::npos) {
			return key.size()*2;
		}
		for (char k : key) {
			if (str.find(k) != std::string::npos) {
				weight++;
			}
		}
		return weight;
	}
