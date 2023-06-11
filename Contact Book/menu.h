#include<iostream>
class Menu
{
	const std::string enter_data = "enter 1 data of contact";
	const std::string print_total_contacts_array = "enter 2 to print the total contacts in array";
	const std::string merge = "enter 3 to merge the document in array";
	const std::string print_sorted = "enter 4 to print the sorted data";
	const std::string save_data = "enter 5 to save data in to file";
	const std::string load_data = "enter 6 to load data from file";
	const std::string print_unsoted = "enter 7 to print unsorted data / as it as data stored in array";
	const std::string sort_list = "enter 8 to sort list";
	const std::string search = "enter 9 to search :";
	const std::string save_data_list = "enter 10 to save data of list to file";
	const std::string update = "enter 11 to update";
	const std::string delete_single_contact = "enter 12 to delete the single contact";
	const std::string load_data_list = "enter 13 to load data of list from file";
	const std::string display_list_data = "enter 14 to display daya list";
	const std::string display_frequently_search = "enter 15 to display frequently searched data";
	const std::string create_group = "enter 16 to create Group";
	const std::string add_contact_group = "enter 17 to add contact to Group";
	const std::string remove_contact_group = "enter 18 to remove contact from Group";
	const std::string view_contact_group = "enter 19 to veiw a contact's Group";
	const std::string remove_group = "enter 20 to remove group";
	const std::string save_group = "enter 21 to save group to file";
	const std::string load_group = "enter 22 to load group from file";
	const std::string advance_search = "enter 23 to advance search";
public:
	Menu();
	friend std::ostream& operator << (std::ostream& outi, const  Menu& m1);
	//final code By Mustafa X Adeel
};
