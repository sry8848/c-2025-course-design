#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "manager.h"
#include "alumni.h"
#include "myList.h"
#include "Utils.h"
#include "visitor.h"
#include "alumni_list.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class managerModle {
public:
	managerModle(List<visitor> current_visitor_list_,List<manager> current_manager_list, alumni_list current_alumni_list_, manager current_manager_) {
		current_visitor_list = current_visitor_list_;
		current_manager_list = current_manager_list;
		current_alumni_list = current_alumni_list_;
		current_manager = current_manager_;
	}
	void run() {
		while (true) {
			cout << "\nУ��¼����ϵͳV1.0\n"
				<< "-------------------------\n"
				<< "ѡ�\n"
				<< "1.����У��\n"
				<< "2.������Ϣ\n"
				<< "3.�����˺�\n"
				<< "4.�˳���¼\n"
				<< "-------------------------\n";
			int choice = Utils::getChoice(4);
			string userName;
			string password;
			int choice2;
			int account_type;
			alumniFilter Filter(fileManager::load_department_list("department.txt"));
			int choice1;
			int sort_choice;
			//int choice3 = Utils::getChoice(2);�Ҳ���choice3�Ķ��壬������֮ǰ�Ĵ���Ƭ��û�а���
			string keyword;
			alumni_list search_list;
			switch (choice) {
			case 1:
				cout << "ѡ�\n"
					<< "1.��������\n"
					<< "2.ɸѡ\n"
					<< "3.����ʽ\n"
					<< "4.������һ��\n"
					<< "-------------------------\n";
				choice1 = Utils::getChoice(4);
				switch (choice1) {
				case 1:
					cout << "������";
					getline(cin, keyword);
					search_list = current_alumni_list.search_form_line(keyword);
					if (search_list.empty()) {
						cout << "û���ҵ����У����Ϣ��\n";
					}
					else {
						search_list.show_allowChange();
						fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					}
					break;
				case 2:
					Filter.modify_alumniFilter();
					Filter.show();//��ʾɸѡ����
					current_alumni_list.filter_show_allowChange(Filter);//ɸѡ����ʾУ����Ϣ
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 3:
					cout << "ѡ�\n"
						<< "1.����������\n"
						<< "2.����������\n"
						<< "3.���켶����\n"
						<< "4.���켶����\n"
						<< "-------------------------\n";
					sort_choice = Utils::getChoice(4);
					switch (sort_choice) {
					case 1:
						current_alumni_list.sort(alumni::Compare_by_name_up);
						break;
					case 2:
						current_alumni_list.sort(alumni::Compare_by_name_down);
						break;
					case 3:
						current_alumni_list.sort(alumni::Compare_by_year_up);
						break;
					case 4:
						current_alumni_list.sort(alumni::Compare_by_year_down);
						break;
					}
					current_alumni_list.show_allowChange();
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 4:
					break;
				}
				break;
			case 2:
				current_manager.show();
				cout << "-------------------------\n"
					<< "ѡ�\n"
					<< "1.�޸�����\n"
					<< "2.������һ��\n"
					<< "-------------------------\n";
				choice2 = Utils::getChoice(2);
				switch (choice2) {
				case 1:
					current_manager.modify_password();
					for (auto& manager : current_manager_list) {
						if (manager.getUserName() == current_manager.getUserName()) {
							manager = current_manager;  // �����б��еĶ���
							break;
						}
					}
					fileManager::save_T_list("manager.txt", current_manager_list);
					break;
				case 2:
					break;
				}
				break;
			case 3:
				cout << "ѡ���˺����ͣ�\n";
				cout << endl;
				cout << "-------------------------\n";
				cout << "ѡ�\n";
				cout << "1.У���˺�\n";
				cout << "2.����Ա�˺�\n";
				cout << "3.�ÿ��˺�\n";
				cout << "4.������һ��\n";
				cout << "-------------------------\n";
				account_type = Utils::getChoice(4);
				cout << "(ע�⣺���˺ŵĳ�ʼ����Ϊ123456)\n";
				if (account_type == 1) {
					cout << "��������У���˺���Ϣ��\n";
					cout << "�û�����";
					cin >> userName;
					cin.clear(); // ������뻺�����еĻ��з�
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺�����еĻ��з�
					password = Utils::modifyPassword("123456");
					alumni new_alumni(userName, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
					new_alumni.create_information();
					current_alumni_list.insert(new_alumni); // ����У����ӵ�У���б�
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					cout << "�����ɹ���\n";
				}
				else if (account_type == 2) {
					cout << "�������¹���Ա�˺���Ϣ��\n";
					cout << "�û�����";
					cin >> userName;
					cin.clear(); // ��������־
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
					password = Utils::modifyPassword("123456");
					manager new_manager(userName, password);
					current_manager_list.insert(new_manager);
					fileManager::save_T_list("manager.txt", current_manager_list);
					cout << "�����ɹ���\n";
				}
				else if (account_type == 3) {
					cout << "�������·ÿ��˺���Ϣ��\n";
					cout << "�û�����";
					cin >> userName;
					cin.clear(); // ��������־
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
					password = Utils::modifyPassword("123456");
					visitor new_visitor(userName, password);
					current_visitor_list.insert(new_visitor);
					fileManager::save_T_list("visitor.txt", current_visitor_list);
					cout<< "�����ɹ���\n";
				}
				break;
			case 4:
				fileManager::save_T_list("visitor.txt", current_visitor_list);
				fileManager::save_T_list("manager.txt", current_manager_list);
				fileManager::save_alumni_list("alumni.txt", current_alumni_list);
				cout << "��Ϣ�ѱ��棡\n";
				cout << "�˳���¼�ɹ���\n";
				return;
			}
		}
	}
private:
	List<visitor> current_visitor_list;
	List<manager> current_manager_list;
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	manager current_manager; // ��ǰ�ÿ�
};