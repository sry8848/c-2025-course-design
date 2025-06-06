#include <iostream>
#include <cstdlib>
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
	else if (choice == -1) {
		cout << "已退出系统！" << endl;
		exit(1);
	}
	else if (choice == 0) {
		cout << "已保存修改！" << endl;
		return choice;
	}
	else{
		cout << "输入错误！请正确输入选项前序号（示例输入：1）\n" << endl;
		return getChoice(numberOfChoices);
	}
}
	int Utils::serach_return_weight(const std::string& str, const std::string& key) {
		size_t strp = 0, keyp = 0;
		int weight = 0;
		while (keyp < str.size()) {
			while (strp < str.size()) {
				if (str[strp] == key[keyp]) {
					weight += 1;
					keyp++;
					if (keyp == key.size()) {
						return weight;
					}
				}
				strp++;
			}
		}
		return weight;
	}
