#include <iostream>
#include <cstdlib>
#include "alumniModle.h"
#include "Utils.h"
#include "alumni.h"
#include "myList.h"
using namespace std;
alumniModle::alumniModle(alumni_list current_alumni_list_, alumni current_alumni_) {
	current_alumni_list = current_alumni_list_;
	current_alumni = current_alumni_;

}
void alumniModle::run() {
	while (true) {
		cout << "У��¼����ϵͳV1.0\n"
			<< "-------------------------\n"
			<< "ѡ�\n"
			<< "1.����У��\n"
			<< "2.������Ϣ\n"
			<< "3.�˳���¼\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(3);
		int choice2 = Utils::getChoice(2);
		switch (choice) {
		case 1:
			current_alumni_list.show();
			break;
		case 2:
			current_alumni.show();
			cout << "-------------------------\n"
				<< "ѡ�\n"
				<< "1.�޸�����\n"
				<< "2.�޸�У����Ϣ\n"
				<< "3.������һ��\n"
				<< "-------------------------\n";
			switch (choice2) {
			case 1:
				current_alumni.modify_password();
				break;
			case 2:
				current_alumni.modify_information();
				break;
			case 3:
				break;
			}
			break;
		case 3:
			return;
		}

	}
}