#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
class person {
public:
	std::string getUserName() const { return userName; }
	std::string getPassword() const { return password; }
	person(std::string userName_=0, std::string password_="123456");//Ĭ������
	void show();
	void modify_password();//�޸�����
	bool operator==(const person& other) const;
protected:
	std::string userName;
	std::string password;
};