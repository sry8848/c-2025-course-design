#include <iostream>
#include <cstdlib>
#include "LoginSystem.h"
#include "Utils.h"
using namespace std;
void LoginSystem::run() {
	while (true) {
		cout << "У��¼����ϵͳV1.0\n"
			<< "-------------------------\n"
			<< "������ѡ��ǰ�����ѡ���¼���\n"
			<< "1.����ѧ��\n"
			<< "2.����У��\n"
			<< "3.���Ƿÿ�\n"
			<< "4.���ǹ���Ա\n"
			<< "-1.�˳�ϵͳ\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(4);
		while (true) {
			cout << "�������˺ź����룺\n";
			string account, password;
			cout << "�˺ţ�";
			cin >> account;
			cout << "���룺";
			cin >> password;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			switch (choice) {
			case 1:
				cout << "ѧ����¼\n";
				break;
			case 2:
				cout << "У�ѵ�¼\n";
				break;
			case 3:
				cout << "�ÿ͵�¼\n";
				break;
			case 4:
				cout << "����Ա��¼\n";
				break;
			}
			cout << "�û������������\n"
				<< "-------------------------\n"
				<< "ѡ�\n"
				<< "1.��������\n"
				<< "2.������һ��\n"
				<< "-------------------------\n";
			int choice2 = Utils::getChoice(2);
			if (choice2 == 1) {
				continue;
			}
			else if (choice2 == 2) {
				break;
			}
		}
	}
