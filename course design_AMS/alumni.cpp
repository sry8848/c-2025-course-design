/*

#include <iostream>
#include <cstdlib>
#include "alumni.h"
#include "Utils.h"
using namespace std;
alumni::alumni(
	std::string userName_="",
	std::string password_="123456",
	std::string name="",
	std::string pinyin = "",
	char gender='\0',
	int age=0,
	int year_of_graduation=0,
	std::string department = "",
	std::string major = "",
	std::string Class = "",
	std::string address = "",
	std::string phoneNumber = "",
	std::string qq = "",
	std::string email = ""
):person(userName_, password_){
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
void alumni::create_information() {
		cout << "������������";
		cin >> name;
		cout << "����������ƴ��(ʾ�����룺guozhijin)��";
		cin >> pinyin;
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
		cin >> age;
		cout << "�������ҵ��ݣ�";
		cin >> year_of_graduation;
		cout << "������ϵ��";
		cin >> department;
		cout << "������רҵ��";
		cin >> major;
		cout << "������༶��";
		cin >> Class;
		cout << "�Ƿ���ʾ��ַ��\n 1.��\n 2.��\n";
		int address_choice = Utils::getChoice(2);
		if (address_choice == 2) {
			address = "����";
		}
		else {
			cout << "�������ַ��";
			cin >> address;
		}
		cout << "�Ƿ���ʾ�绰��\n 1.��\n 2.��\n";
		int phone_choice = Utils::getChoice(2);
		if (phone_choice == 2) {
			phoneNumber = "����";
		}
		else {
			cout << "������绰��";
			cin >> phoneNumber;
		}
		cout << "�Ƿ���ʾQQ��\n 1.��\n 2.��\n";
		int qq_choice = Utils::getChoice(2);
		if (qq_choice == 2) {
			qq = "����";
		}
		else {
			cout << "������QQ��";
			cin >> qq;
		}
		cout << "�Ƿ���ʾ���䣿\n 1.��\n 2.��\n";
		int email_choice = Utils::getChoice(2);
		if (email_choice == 2) {
			email = "����";
		}
		else {
			cout << "���������䣺";
			cin >> email;
		}
}
void alumni::modify_information() {
	cout << "����Ҫ�޸���Ϣǰ����ţ�";
	int choice=Utils::getChoice(11);
	int gender_choice = Utils::getChoice(2);
	int address_choice = Utils::getChoice(2);
	int phone_choice = Utils::getChoice(2);
	int qq_choice = Utils::getChoice(2);
	int email_choice = Utils::getChoice(2);
	int continue_choice = Utils::getChoice(2);
	switch (choice) {
	case 1:
		cout << "������������";
		cin >> name;
		cout << "����������ƴ��(ʾ�����룺guozhijin)��";
		cin >> pinyin;
		break;
	case 2:
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
		cin >> age;
		break;
	case 4:
		cout << "�������ҵ��ݣ�";
		cin >> year_of_graduation;
		break;
	case 5:
		cout << "������ϵ��";
		cin >> department;
		break;
	case 6:
		cout << "������רҵ��";
		cin >> major;
		break;
	case 7:
		cout << "������༶��";
		cin >> Class;
		break;
	case 8:
		cout << "�Ƿ���ʾ��ַ��\n 1.��\n 2.��\n";
		if (address_choice == 2) {
			address = "����";
		}
		else {
			cout << "�������ַ��";
			cin >> address;
		}
		break;

	case 9:
		cout << "�Ƿ���ʾ�绰��\n 1.��\n 2.��\n";
		
		if (phone_choice == 2) {
			phoneNumber = "����";
		}
		else {
			cout << "������绰��";
			cin >> phoneNumber;
		}
		break;
	case 10:
		cout << "�Ƿ���ʾQQ��\n 1.��\n 2.��\n";
		
		if (qq_choice == 2) {
			qq = "����";
		}
		else {
			cout << "������QQ��";
			cin >> qq;
		}
		break;
	case 11:
		cout << "�Ƿ���ʾ���䣿\n 1.��\n 2.��\n";
	
		if (email_choice == 2) {
			email = "����";
		}
		else {
			cout << "���������䣺";
			cin >> email;
		}
		break;
	}
	cout<<"�Ƿ�����޸ģ�\n 1.��\n 2.��\n";
	
	if (continue_choice == 1) {
		modify_information();
	}
	else if (continue_choice == 2) {
		return;
	}
}
void alumni::show() {
	person::show();
	cout << "У����Ϣ��\n";
	cout <<"1.������"<<name<<endl
		 <<"2.�Ա�"<<gender<<endl
		 <<"3.���䣺"<<age<<endl
		 <<"4.��ҵ��ݣ�"<<year_of_graduation<<endl
		 <<"5.ϵ��"<<department<<endl
		 <<"6.רҵ��"<<major<<endl
		 <<"7.�༶��"<<Class<<endl
		 <<"8.��ַ��"<<address<<endl
		 <<"9.�绰��"<<phoneNumber<<endl
		 <<"10.QQ��"<<qq<<endl
		 <<"11.���䣺"<< email<<endl;
}
bool alumni::Compare_by_year_up(const alumni& left, const alumni& right){
	return left.year_of_graduation > right.year_of_graduation;
}
bool alumni::Compare_by_year_down(const alumni& left, const alumni& right) {
	return left.year_of_graduation < right.year_of_graduation;
}
bool alumni::Compare_by_name_up(const alumni& left, const alumni& right) {
	return left.pinyin > right.pinyin;
}
bool alumni::Compare_by_name_down(const alumni& left, const alumni& right) {
	return left.pinyin < right.pinyin;
}

*/