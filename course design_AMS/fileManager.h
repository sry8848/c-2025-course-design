#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
#include "list.h"
#include "alumni_list.h"
#include "department.h"
template <typename T> class List;
class alumni_list;
class Department;//添加前向声明，避免循环依赖！！
class fileManager {
public:
	static void save_alumni_list(const std::string& fileName,const alumni_list& alumniList); // 保存校友列表到文件                                                                                             
	static alumni_list load_alumni_list(const std::string& fileName); // 从指定文件加载校友列表(AlumniList 依赖 FileManager（单向依赖）)
	template <typename T>
	static void save_T_list(const std::string& fileName, List<T>& TList); // 从指定文件加载通用列表
	template <typename T>
	static List<T> load_T_list(const std::string& fileName); // 保存通用列表到文件
	static std::vector<Department> load_department_list(const std::string& fileName); // 从指定文件加载系列表
}
;