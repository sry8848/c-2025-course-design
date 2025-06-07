#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include "person.h"
class alumni :public person {
public:
	alumni(
		std::string userName_, 
		std::string password_,
		std::string name,
		std::string pinyin, // ����ƴ��
		char gender,
		int age,
		int year_of_graduation,
		std::string department,
		std::string major,
		std::string Class,
		std::string address,
		std::string phoneNumber,
		std::string qq,
		std::string email
	);
	alumni() = default; // Ĭ�Ϲ��캯��
	std::string getUserName() const { return userName; }
	std::string getPassword() const { return password; }
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
	void modify_information();
	void create_information();
	void show();
	static bool Compare_by_year_up(const alumni& left,const alumni& right);
	static bool Compare_by_year_down(const alumni& left, const alumni& right);
	static bool Compare_by_name_up(const alumni& left, const alumni& right);
	static bool Compare_by_name_down(const alumni& left, const alumni& right);
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
