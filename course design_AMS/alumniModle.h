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

private:
	alumni_list current_alumni_list; // У���б�,ע�����һ����Ҫ������ͬ����
	alumni current_alumni; // ��ǰ�ÿ�
};