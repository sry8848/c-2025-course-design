#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
class person {
public:
	person(std::string userName_, std::string password_);
	void show();
	void modify_password();//�޸�����
protected:
	std::string userName;
	std::string password;
};