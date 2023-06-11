#include<iostream>
#include<string>
#include<fstream>
class Group
{
private:
	std::string* contact_id_list;
	int size, count;
	std::string group_name;

public:
	Group() {
		contact_id_list = NULL;
		size = count = 0;
		group_name = "";
	}
	Group(std::string, int);
	Group(const Group&);
	~Group();

	void AddContactId(std::string);
	void RemoveContactId(std::string);
	void ResizeList();

	std::string* ContactIdList();//Getters
	std::string GroupName();
	int Count();

	void operator = (const Group&);

	friend std::ostream& operator << (std::ostream& , const Group&);

	void SaveData(std::ofstream&);//Write
	void InputData(std::ifstream&);//read
};