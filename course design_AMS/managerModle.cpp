/*


#include <iostream>
#include <cstdlib>
#include "managerModle.h"
#include "alumni.h"
using namespace std;
managerModle::managerModle(alumni_list current_alumni_list_, manager current_manager_) {
	current_alumni_list = current_alumni_list_;
	current_manager = current_manager_;

}
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
		int choice2 = Utils::getChoice(2);
		int account_type = Utils::getChoice(3);
		alumniFilter Filter;
		int choice1 = Utils::getChoice(4);
		int sort_choice = Utils::getChoice(4);
		int choice3 = Utils::getChoice(2);
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
				}
				break;
			case 2:
				Filter.modify_alumniFilter();
				Filter.show();//��ʾɸѡ����
				current_alumni_list.filter_show_allowChange(Filter);//ɸѡ����ʾУ����Ϣ
				break;
			case 3:
				cout << "ѡ�\n"
					<< "1.����������\n"
					<< "2.����������\n"
					<< "3.���켶����\n"
					<< "4.���켶����\n"
					<< "-------------------------\n";

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
			if (account_type == 1) {
				cout << "��������У���˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				alumni new_alumni(userName, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
				new_alumni.create_information();
				current_alumni_list.insert(new_alumni); // ����У����ӵ�У���б�
			}
			else if (account_type == 2) {
				cout << "�������¹���Ա�˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				manager new_manager(userName, password);
				current_manager_list.insert(new_manager); 
			}
			else if (account_type == 3) {
				cout << "�������·ÿ��˺���Ϣ��\n";
				cout << "�û�����";
				cin >> userName;
				cout << "���룺";
				cin >> password;
				visitor new_visitor(userName, password);
				current_visitor_list.insert(new_visitor);
			}
			break;
		case 4:
			return;
		}
		}
	}


	*/