#include <iostream>
#include <cstdlib>
#include "person.h"
#include "Utils.h"
using namespace std;
person::person(std::string userName_, std::string password_) {
	userName = userName_;
	password = password_;
}
void person::show() {
	cout << "-------------------------\n";
	cout<< "�û���Ϣ��\n";
	cout << "�û����� " << userName << endl;
}
void person::modify_password() {
	cout<< "�����������룺";
	string new_password;
	getline(cin, new_password);//��ֹ�ո������ַ�
	if (new_password == password) {
		cout << "�����벻����ԭ������ͬ��\n" << endl;
		cout<<"ѡ�\n 1.��������\n 2.������һ��\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.length() < 6) {
		cout << "���볤�Ȳ���С��6λ��\n" << endl;
		cout<<"ѡ�\n 1.��������\n 2.������һ��\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.length() > 20) {
		cout << "���볤�Ȳ��ܴ���20λ��\n" << endl;
		cout<<"ѡ�\n 1.��������\n 2.������һ��\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos|| new_password.find_first_of("0123456789") == string::npos) {
		cout << "�������Ϊ��ĸ�����ֵ���ϣ�\n" << endl;
		cout<<"ѡ�\n 1.��������\n 2.������һ��\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else {
		password = new_password;
		cout << "�޸ĳɹ���\n" << endl;
	}
}