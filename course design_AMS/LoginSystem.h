#pragma once//ͷ�ļ���������ֹ�ظ�����
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "LoginSystem.h"
#include "visitor.h"
#include "myList.h"
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
//������ͷ�ļ�����#include<iostream>������ʹ��std::
class LoginSystem {
	public:
		void run() {
			while (true) {
				cout << "\nУ��¼����ϵͳV1.0\n"
					<< "------------------------------\n"
					<< "������ѡ��ǰ�����ѡ���¼���\n"
					<< "1.����ѧ��\n"
					<< "2.����У��\n"
					<< "3.���Ƿÿ�\n"
					<< "4.���ǹ���Ա\n"
					<< "5.�˳�ϵͳ\n"
					<< "------------------------------\n";
				int choice = Utils::getChoice(5);
				if (choice == 5) {
					cout << "�˳�ϵͳ��\n";
					exit(0);
				}
				while (true) {
					cout << "�������˺ź����룺\n";
					string account, password;
					cout << "�˺ţ�";
					cin >> account;
					cout << "���룺";
					cin >> password;
					cin.clear(); // ��������־
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
					std::string name = "";
					std::string pinyin = "";
					char gender = '\0';
					int age = 0;
					int year_of_graduation = 0;
					std::string department = "";
					std::string major = "";
					std::string Class = "";
					std::string address = "";
					std::string phoneNumber = "";
					std::string qq = "";
					std::string email = "";
					List<visitor> current_visitor_list;
					alumni_list current_alumni_list;
					List<manager> current_manager_list;
					current_alumni_list = fileManager::load_alumni_list("alumni.txt");
					current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");//��Ҫָ������ֵ����
					current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");
					current_manager_list = fileManager::load_T_list<manager>("manager.txt");
					visitor current_visitor(account, password);
					manager current_manager(account, password);
					bool lgout = 0;
					alumni current_alumni(account, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
					switch (choice) {
					case 1:
	
						if (current_visitor_list.count(current_visitor)) {
							cout << "��¼�ɹ���\n";
							VisitorModle visitorModle(current_visitor_list,current_alumni_list, current_visitor);//����VisitorModle����
							visitorModle.run();
							lgout = 1;
						}
						else {
							cout << "�û������������\n"
								<< "-------------------------\n"
								<< "ѡ�\n"
								<< "1.��������\n"
								<< "2.������һ��\n"
								<< "-------------------------\n";
	
						}
						break;
					case 2:

						if (current_alumni_list.count(current_alumni)) {//ֻ��person����==�����ֻ�Ƚ��˺�����
							current_alumni = current_alumni_list.find(current_alumni);
							cout << "��¼�ɹ���\n";
							alumniModle alumniModle(current_alumni_list, current_alumni);//����alumniModle����
							alumniModle.run();
							lgout = 1;
						}
						else {
							cout << "�û������������\n"
								<< "-------------------------\n"
								<< "ѡ�\n"
								<< "1.��������\n"
								<< "2.������һ��\n"
								<< "-------------------------\n";
	
						}
						break;
					case 3:
					
						if (current_visitor_list.count(current_visitor)) {
							cout << "��¼�ɹ���\n";
							VisitorModle visitorModle(current_visitor_list, current_alumni_list, current_visitor);//����VisitorModle����
							visitorModle.run();
							lgout = 1;
						}
						else {
							cout << "�û������������\n"
								<< "-------------------------\n"
								<< "ѡ�\n"
								<< "1.��������\n"
								<< "2.������һ��\n"
								<< "-------------------------\n";
	
						}
						break;
					case 4:
		
						if (current_manager_list.count(current_manager)) {
							cout << "��¼�ɹ���\n";
							managerModle managerModle(current_visitor_list, current_manager_list,current_alumni_list, current_manager);//����managerModle����
							managerModle.run();
							lgout = 1;
						}
						else {
							cout << "�û������������\n"
								<< "-------------------------\n"
								<< "ѡ�\n"
								<< "1.��������\n"
								<< "2.������һ��\n"
								<< "-------------------------\n";
							
						}
						break;
					}
					if (!lgout) {
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
		}

};