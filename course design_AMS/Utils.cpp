#include <iostream>
#include <cstdlib>
#include "alumni_list.h"
#include "Utils.h"
using namespace std;
int Utils::getChoice(int numberOfChoices) {//��������дstatic
	int choice;
	cin >> choice;
	cin.clear(); // ��������־
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
	if (choice >= 1 && choice <= numberOfChoices) {
		return choice;
	}
	else {
		cout << "�����������ȷ����ѡ��ǰ��ţ�ʾ�����룺1��\n" << endl;
		return getChoice(numberOfChoices);
	}
}
string Utils::pinyinInput(){
	string input;
	if (!getline(cin, input)) {//getline��Ե����з������º�����ignore����Ҫ�����뻻�з�
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
	}
	for (char& c : input) {
		if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')&&!(c==' ')) {
			cin.clear(); // ��������־
			cout << "�����������������ƴ����ֻ������ĸ��:";
			return pinyinInput();
		}
		c = tolower(c); // ת��ΪСд��ĸ
	}
	return input;
}
string Utils::onlyNumberInput() {
	string input;
	if (!getline(cin, input)) {//getline��Ե����з������º�����ignore����Ҫ�����뻻�з�
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
	}
	for (char c : input) {
		if (!(c >= '0' && c <= '9')) {
			cin.clear(); // ��������־
			cout << "�������ֻ�����������֣�����������:";
			return onlyNumberInput();
		}
	}
	return input;
}
string Utils::modifyPassword(string prePassword) {
	cout << "���룺";
	string new_password;
	getline(cin, new_password);//��ֹ�ո������ַ�
	if (new_password == prePassword) {
		cout << "�����벻����ԭ������ͬ��\n" << endl;
		cout << "-------------------------\n"
			<< "ѡ�\n"
			<< "1.��������\n"
			<< "2.��������\n"
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
		cout << "���볤�Ȳ���С��6λ��\n" << endl;
		cout << "-------------------------\n"
			<< "ѡ�\n"
			<< "1.��������\n"
			<< "2.��������\n"
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
		cout << "���볤�Ȳ��ܴ���20λ��\n" << endl;
		cout << "-------------------------\n"
			<< "ѡ�\n"
			<< "1.��������\n"
			<< "2.��������\n"
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
