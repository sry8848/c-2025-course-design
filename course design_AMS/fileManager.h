#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include "list.h"
#include "alumni_list.h"
class fileManager {
public:
	static void save_alumni_list(const std::string& fileName,const alumni_list& alumniList); // ����У���б��ļ�                                                                                             
	static alumni_list load_alumni_list(const std::string& fileName); // ��ָ���ļ�����У���б�(AlumniList ���� FileManager������������)
	template <typename T>
	static void save_T_list(const std::string& fileName, List<T>& TList); // ��ָ���ļ�����ͨ���б�
	template <typename T>
	static List<T> load_T_list(const std::string& fileName); // ����ͨ���б��ļ�
}
;