#include <iostream>
#include <cstdlib>
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
	else if (choice == -1) {
		cout << "���˳�ϵͳ��" << endl;
		exit(1);
	}
	else if (choice == 0) {
		cout << "�ѱ����޸ģ�" << endl;
		return choice;
	}
	else{
		cout << "�����������ȷ����ѡ��ǰ��ţ�ʾ�����룺1��\n" << endl;
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
