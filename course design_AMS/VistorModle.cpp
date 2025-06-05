#include <iostream>
#include <cstdlib>
#include "alumni_list.h"
#include "list.h"
#include "VisitorModle.h"
#include "Utils.h"
#include "alumni.h"
#include "alumniFilter.h"
using namespace std;
VisitorModle::VisitorModle(alumni_list current_alumni_list_, visitor current_visitor_) {
	current_alumni_list = current_alumni_list_;
	current_visitor = current_visitor_;
}
void VisitorModle::run() {
	while (true) {
		cout << "У��¼����ϵͳV1.0\n"
			<< "-------------------------\n"
			<< "ѡ�\n"
			<< "1.����У��\n"
			<< "2.������Ϣ\n"
			<< "3.�˳���¼\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(3);
		alumniFilter Filter;
		int choice1 = Utils::getChoice(4);
		int choice2 = Utils::getChoice(4);
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
				cout<< "������";
				getline(cin, keyword);
				search_list=current_alumni_list.search_form_line(keyword);
				if (search_list.empty()) {
					cout << "û���ҵ����У����Ϣ��\n";
				} else {
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
			current_visitor.show();
			cout << "-------------------------\n"
				<< "ѡ�\n"
				<< "1.�޸�����\n"
				<< "2.������һ��\n"
				<< "-------------------------\n";

			switch (choice3) {
			case 1:
				current_visitor.modify_password();
				break;
			case 2:
				break;
			}
			break;
		case 3:
			return;
		}

	}
}