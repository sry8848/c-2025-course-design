#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "LoginSystem.h"
#include "visitor.h"
#include "List.h"
#include "alumni.h"
#include "alumni_list.h"
#include "manager.h"
#include "managerModle.h"
#include "alumniModle.h"
#include "fileManager.h"
#include "VisitorModle.h"
#include "alumniModle.h"
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
			List<visitor> current_visitor_list;
			alumni_list current_alumni_list;
			List<manager> current_manager_list;
			visitor current_visitor(account, password);
			manager current_manager(account, password);
			alumni current_alumni(account, password);
			switch (choice) {
			case 1:
				current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");//��Ҫָ������ֵ����
				cout << "ѧ����¼\n";
				if (current_visitor_list.count(current_visitor)) {
					cout<<"��¼�ɹ���\n";
					VisitorModle visitorModle(current_alumni_list, current_visitor);//����VisitorModle����
					visitorModle.run();
				}
				break;
			case 2:
				current_alumni_list = fileManager::load_alumni_list("alumni.txt");
				cout << "У�ѵ�¼\n";
				if (current_alumni_list.count(current_alumni)) {
					cout<<"��¼�ɹ���\n";
					alumniModle alumniModle(current_alumni_list, current_alumni);//����alumniModle����
					alumniModle.run();
				}
				break;
			case 3:
				current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");
				cout << "�ÿ͵�¼\n";
				if (current_visitor_list.count(current_visitor)) {
					cout<<"��¼�ɹ���\n";
					VisitorModle visitorModle(current_alumni_list, current_visitor);//����VisitorModle����
					visitorModle.run();
				}
				break;
			case 4:
				current_manager_list = fileManager::load_T_list<manager>("manager.txt");
				cout << "����Ա��¼\n";
				if (current_manager_list.count(current_manager)) {
					cout<<"��¼�ɹ���\n";
					managerModle managerModle(current_alumni_list, current_manager);//����managerModle����
					managerModle.run();
				}
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
}
