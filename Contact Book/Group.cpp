#include"Group.h"

Group::Group(std::string group_name, int size) {
	/*
	*Intializes Group name and the size of contact id list.
	*Intializes count of contact ids from (0)
	*/
	this->group_name = group_name;
	this->size = size;
	count = 0;
	contact_id_list = new std::string[size];
}

void Group::AddContactId(std::string mobile_number) {
	/*
	*Adds Contact to list,
	*resizes list if contact ids exceed intialized count
	*/
	if (size == count)
	{
		ResizeList();
	}
	contact_id_list[count] = mobile_number;
	count++;
}

void Group::RemoveContactId(std::string mobile_number)
{
	/*
	* Removes Contact id by swap it with the element at the last Index.
	*/
	for (int i = 0; i < count; i++)
	{
		if (contact_id_list[i] == mobile_number)
		{
			contact_id_list[i] = "";
		}
		count--;
	}
}

void Group::ResizeList()
{
	/*Resizes list by doubling its size*/
	std::string* new_id_list = new std::string[size * 2];
	for (int i = 0; i < count; i++)
	{
		new_id_list[i] = contact_id_list[i];
	}
	size *= 2;
	delete[]contact_id_list;
	contact_id_list = new_id_list;
}

Group::~Group()
{
	/*Deletes list of contact ids*/
	delete[]contact_id_list;
}

Group::Group(const Group& group)
{
	group_name = group.group_name;
	count = group.count;
	size = group.size;
	contact_id_list = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		contact_id_list[i] = group.contact_id_list[i];
	}
}

void Group::operator = (const Group& group)
{
	group_name = group.group_name;
	count = group.count;
	size = group.size;
	contact_id_list = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		contact_id_list[i] = group.contact_id_list[i];
	}
}

std::string* Group::ContactIdList()
{
	return contact_id_list;
}

std::string Group::GroupName()
{
	return group_name;
}

int Group::Count()
{
	return count;
}

std::ostream& operator << (std::ostream& out, const Group& group)
{
	out <<"Group name "<< group.group_name << std::endl;
	for (int i = 0; i < group.size; i++)
	{
		out <<"Contact Id ["<<i+1<<"]" << group.contact_id_list[i] << std::endl;
	}
	return out;
}

void Group::SaveData(std::ofstream& write)
{
	write << size << std::endl;
	write << count << std::endl;
	write << group_name << std::endl;
	for (int i = 0; i < count; i++)
	{
		write << contact_id_list[i] << std::endl;
	}
}

void Group::InputData(std::ifstream& read)
{
	read >> size;
	read >> count;
	delete[]contact_id_list;
	contact_id_list = new std::string[size];
	std::getline(read.ignore(), group_name);
	for (int i = 0; i < count; i++)
	{
		std::getline(read, contact_id_list[i]);
	}
}
