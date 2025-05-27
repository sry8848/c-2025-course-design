#include <iostream>
#include <cstdlib>
#include "managerModle.h"
#include "Utils.h"
#include "manager.h"
#include "visitor.h"
#include "alumni.h"
#include "list.h"
using namespace std;
void managerModle::run() {
	while (true) {
		cout << "У��¼����ϵͳV1.0\n"
			<< "-------------------------\n"
			<< "ѡ�\n"
			<< "1.����У��\n"
			<< "2.������Ϣ\n"
			<<"3.�����˺�\n"
			<< "4.�˳���¼\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(4);
		string userName;
		string password;
		switch (choice) {
		case 1:
			manager_list->show();
			break;
		case 2:
			current_manager.show();
			cout << "-------------------------\n"
				<< "ѡ�\n"
				<< "1.�޸�����\n"
				<< "2.������һ��\n"
				<< "-------------------------\n";
			int choice2 = Utils::getChoice(2);
			switch (choice2) {
			case 1:
				current_manager.modify_password();
				break;
			case 2:
				break;
			}
		case 3:
			cout << "ѡ���˺����ͣ�\n";
			cout << "1.У���˺�\n";
			cout << "2.����Ա�˺�\n";
			cout << "3.�ÿ��˺�\n";
			int account_type = Utils::getChoice(3);
			if (account_type == 1) {
				cout << "��������У���˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				alumni new_alumni(userName, password);
				new_alumni.create_information();
			}
			else if (account_type == 2) {
				cout << "�������¹���Ա�˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				manager new_manager(userName, password);
			}
			else if (account_type == 3) {
				cout << "�������·ÿ��˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				visitor new_visitor(userName, password);
			}
			break;
		case 4:
			return;
		}
		}

	}
