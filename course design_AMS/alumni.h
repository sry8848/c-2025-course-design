#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include "person.h"
class alumni :public person {
public:
	alumni(std::string userName_, std::string password_);
	void modify_information();
	void create_information();
	void show();
	static bool Compare_by_year_up(const alumni& left,const alumni& right);
	static bool Compare_by_year_down(const alumni& left, const alumni& right);
	static bool Compare_by_name_up(const alumni& left, const alumni& right);
	static bool Compare_by_name_down(const alumni& left, const alumni& right);
private:
	std::string name;
	std::string pinyin;//ƴ��
	char gender;
	int age;
	int year_of_graduation;
	std::string department;//ϵ
	std::string major;//רҵ
	int Class;//�༶
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
};
