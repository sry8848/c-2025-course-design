#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include "person.h"
class manager :public person {
public:
	manager(std::string userName_="", std::string password_="123456") :person::person(userName_, password_) {}
};
