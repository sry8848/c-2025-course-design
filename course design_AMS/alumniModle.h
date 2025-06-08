#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include "alumni.h"
#include "myList.h"
#include "Utils.h"
#include "alumni_list.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class alumniModle {
public:
	alumniModle(alumni_list current_alumni_list_, alumni current_alumni_) {
		current_alumni_list = current_alumni_list_;
		current_alumni = current_alumni_;

	}
	void run() {
		while (true) {
			cout << "У��¼����ϵͳV1.0\n"
				<< "-------------------------\n"
				<< "ѡ�\n"
				<< "1.����У��\n"
				<< "2.������Ϣ\n"
				<< "3.�˳���¼\n"
				<< "-------------------------\n";
			vector<Department> current_department_vector = fileManager::load_department_list("department.txt");
			alumniFilter Filter(current_department_vector);
			int choice = Utils::getChoice(3);
			int choice1;
			int choice2;
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
						search_list.show();
					}
					break;
				case 2:
					Filter.modify_alumniFilter();
					Filter.show();//��ʾɸѡ����
					current_alumni_list.filter_show(Filter);//ɸѡ����ʾУ����Ϣ
					break;
				case 3:
					cout << "ѡ�\n"
						<< "1.����������\n"
						<< "2.����������\n"
						<< "3.���켶����\n"
						<< "4.���켶����\n"
						<< "-------------------------\n";
					choice2 = Utils::getChoice(4);
					switch (choice2) {
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
					current_alumni_list.show();
					break;
				case 4:
					break;
				}
				break;
			case 2:
				current_alumni.show();
				cout << "-------------------------\n"
					<< "ѡ�\n"
					<< "1.�޸�����\n"
					<< "2.�޸�У����Ϣ\n"
					<< "3.������һ��\n"
					<< "-------------------------\n";
				choice2 = Utils::getChoice(3);
				switch (choice2) {
				case 1:
					current_alumni.modify_password();
					for (auto& alumni : current_alumni_list) {
						if (alumni.getUserName() == current_alumni.getUserName()) {
							alumni = current_alumni;  // �����б��еĶ���
							break;
						}
					}
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 2:
					current_alumni.modify_information();
					for (auto& alumni : current_alumni_list) {
						if (alumni.getUserName() == current_alumni.getUserName()) {
							alumni = current_alumni;  // �����б��еĶ���
							break;
						}
					}
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 3:
					break;
				}
				break;
			case 3:
				fileManager::save_alumni_list("alumni.txt", current_alumni_list);
				cout << "��Ϣ�ѱ��棡\n";
				cout << "�˳���¼�ɹ���\n";
				return;
			}

		}
	}

private:
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	alumni current_alumni; // ��ǰ�ÿ�
};