#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include "person.h"
#include <iostream>
#include <cstdlib>
#include "alumni.h"
#include "Utils.h"
using namespace std;
class alumni :public person {
public:
	std::string getName() const { return name; }
	std::string getPinyin() const { return pinyin; } // ��ȡ����ƴ��
	std::string getDepartment() const { return department; }
	std::string getMajor() const { return major; }
	std::string getClass() const { return Class; }
	int getAge() const { return age; }
	int getGraduationYear() const { return year_of_graduation; }
	std::string getAddress() const { return address; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getQQ() const { return qq; }
	std::string getEmail() const { return email; }
	int getGender() const { return gender; }

	alumni(
		std::string userName_ = "",
		std::string password_ = "123456",
		std::string name = "",
		std::string pinyin = "",
		char gender = '\0',
		int age = 0,
		int year_of_graduation = 0,
		std::string department = "",
		std::string major = "",
		std::string Class = "",
		std::string address = "",
		std::string phoneNumber = "",
		std::string qq = "",
		std::string email = ""
	) :person(userName_, password_) {
		this->name = name;
		this->pinyin = pinyin; // ����ƴ��
		this->gender = gender;
		this->age = age;
		this->year_of_graduation = year_of_graduation;
		this->department = department;
		this->major = major;
		this->Class = Class;
		this->address = address;
		this->phoneNumber = phoneNumber;
		this->qq = qq;
		this->email = email;
	}
	void create_information() {
		cout << "������������";
		cin >> name;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		cout << "����������ƴ��(ʾ�����룺guozhijin)��";
		pinyin= Utils::pinyinInput(); //��֤�Ƿ�ȫΪ��ĸ���룬ת��Ϊstring����
		cout << "��ѡ���Ա�(�������)��\n";
		cout << "1.��" << endl
			<< "2.Ů" << endl;
		int gender_choice = Utils::getChoice(2);
		if (gender_choice == 1) {
			gender = 'M';
		}
		else if (gender_choice == 2) {
			gender = 'W';
		}
		cout << "���������䣺";
		age = stoi(Utils::onlyNumberInput());//��֤�Ƿ�ȫΪ�������룬ת��Ϊint����
		cout << "�������ҵ��ݣ�";
		year_of_graduation = stoi(Utils::onlyNumberInput());
		cout << "������ϵ��";
		cin >> department;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		cout << "������רҵ��";
		cin >> major;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		cout << "������༶(ʾ�����룺01)��";
		Class = (Utils::onlyNumberInput());
		cout << "�Ƿ���ʾ��ַ��\n 1.��\n 2.��\n";
		int address_choice = Utils::getChoice(2);
		if (address_choice == 2) {
			address = "����";
		}
		else {
			cout << "�������ַ��";
			cin >> address;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		}
		cout << "�Ƿ���ʾ�绰��\n 1.��\n 2.��\n";
		int phone_choice = Utils::getChoice(2);
		if (phone_choice == 2) {
			phoneNumber = "����";
		}
		else {
			cout << "������绰��";
			phoneNumber = (Utils::onlyNumberInput());
		}
		cout << "�Ƿ���ʾQQ��\n 1.��\n 2.��\n";
		int qq_choice = Utils::getChoice(2);
		if (qq_choice == 2) {
			qq = "����";
		}
		else {
			cout << "������QQ��";
			qq = (Utils::onlyNumberInput());
		}
		cout << "�Ƿ���ʾ���䣿\n 1.��\n 2.��\n";
		int email_choice = Utils::getChoice(2);
		if (email_choice == 2) {
			email = "����";
		}
		else {
			cout << "���������䣺";
			cin >> email;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
		}
	}
	void modify_information() {
		cout << "����Ҫ�޸���Ϣǰ����ţ�";
		int choice = Utils::getChoice(11);
		int gender_choice;
		int address_choice;
		int phone_choice;
		int qq_choice;
		int email_choice;
		int continue_choice;
		string name_;
		string department_;
		string major_;
		string address_;
		string email_;
		switch (choice) {
		case 1:
			cout << "������������";
			cin >> name_;
			name = name_; // ����person���е��û���
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			cout << "����������ƴ��(ʾ�����룺guozhijin)��";
			pinyin = Utils::pinyinInput(); //��֤�Ƿ�ȫΪ��ĸ���룬ת��Ϊstring����
			break;
		case 2:
			gender_choice = Utils::getChoice(2);
			cout << "��ѡ���Ա�(�������)��\n";
			cout << "1.��" << endl
				<< "2.Ů" << endl;
			if (gender_choice == 1) {
				gender = 'M';
			}
			else if (gender_choice == 2) {
				gender = 'W';
			}
			break;
		case 3:
			cout << "���������䣺";
			age = stoi(Utils::onlyNumberInput());//��֤�Ƿ�ȫΪ�������룬ת��Ϊint����
			break;
		case 4:
			cout << "�������ҵ��ݣ�";
			year_of_graduation = stoi(Utils::onlyNumberInput());
			break;
		case 5:
			cout << "������ϵ��";
			cin >> department_;
			department = department_;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			break;
		case 6:
			cout << "������רҵ��";
			cin >> major_;
			major = major_;
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			break;
		case 7:
			cout << "������༶��";
			Class = (Utils::onlyNumberInput());
			break;
		case 8:
			cout << "�Ƿ���ʾ��ַ��\n 1.��\n 2.��\n";
			address_choice = Utils::getChoice(2);
			if (address_choice == 2) {
				address = "����";
			}
			else {
				cout << "�������ַ��";
				cin >> address_;
				address = address_; // ���µ�ַ��Ϣ
				cin.clear(); // ��������־
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			}
			break;

		case 9:
			cout << "�Ƿ���ʾ�绰��\n 1.��\n 2.��\n";
			phone_choice = Utils::getChoice(2);
			if (phone_choice == 2) {
				phoneNumber = "����";
			}
			else {
				cout << "������绰��";
				phoneNumber = (Utils::onlyNumberInput());//��֤�Ƿ�ȫΪ�������룬ת��Ϊstring����
			}
			break;
		case 10:
			cout << "�Ƿ���ʾQQ��\n 1.��\n 2.��\n";
			qq_choice = Utils::getChoice(2);
			if (qq_choice == 2) {
				qq = "����";
			}
			else {
				cout << "������QQ��";
				qq = (Utils::onlyNumberInput());//��֤�Ƿ�ȫΪ�������룬ת��Ϊstring����
			}
			break;
		case 11:
			cout << "�Ƿ���ʾ���䣿\n 1.��\n 2.��\n";
			email_choice = Utils::getChoice(2);
			if (email_choice == 2) {
				email = "����";
			}
			else {
				cout << "���������䣺";
				cin >> email_;
				email = email_; // ����������Ϣ
				cin.clear(); // ��������־
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
			}
			break;
		}
		cout << "�Ƿ�����޸ģ�\n 1.��\n 2.��\n";
		continue_choice = Utils::getChoice(2);
		if (continue_choice == 1) {
			modify_information();
		}
		else if (continue_choice == 2) {
			return;
		}
	}
	void show() {
		person::show();
		cout << "У����Ϣ��\n";
		cout << "1.������" << name << endl;
		if (gender == 'M') {
			cout << "2.�Ա���"<< endl;
		}
		else if (gender == 'W') {
			cout << "2.�Ա�Ů" << endl;
		}
		else {
			cout << "2.�Ա�δ֪" << endl;
		}
		cout<< "3.���䣺" << age << endl
			<< "4.��ҵ��ݣ�" << year_of_graduation << endl
			<< "5.ϵ��" << department << endl
			<< "6.רҵ��" << major << endl
			<< "7.�༶��" << Class << endl
			<< "8.��ַ��" << address << endl
			<< "9.�绰��" << phoneNumber << endl
			<< "10.QQ��" << qq << endl
			<< "11.���䣺" << email << endl;
		cout << endl;
	}
	static bool Compare_by_year_up(const alumni& left, const alumni& right) {
		return left.year_of_graduation > right.year_of_graduation;
	}
	static bool Compare_by_year_down(const alumni& left, const alumni& right) {
		return left.year_of_graduation < right.year_of_graduation;
	}
	static bool Compare_by_name_up(const alumni& left, const alumni& right) {
		return left.pinyin > right.pinyin;
	}
	static bool Compare_by_name_down(const alumni& left, const alumni& right) {
		return left.pinyin < right.pinyin;
	}

private:
	std::string name;
	std::string pinyin; // ����ƴ��
	char gender='\0';//��string,Ҫ���ó�ʼֵ,����������ᱨ��
	int age=0;
	int year_of_graduation=0;
	std::string department;//ϵ
	std::string major;//רҵ
	std::string Class;//�༶
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
};
