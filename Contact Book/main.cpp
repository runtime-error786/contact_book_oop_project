#include "ContactsBook.h"
#include "menu.h"
#include "exception.h"
int main()
{
	Menu m1;
	ContactsBook contacts_book(5);
	Contact contact;
	List<Group> group_array;
	Group* group_temp_arr = NULL;
	std::string str_first, str_last, file_name, sorted_choice, * contact_id_list;
	int enter_choice;

	std::cout << m1;
	while (true)
	{

		try {
			std::cin >> enter_choice;
			if (std::cin.fail())
			{
				throw runtime_error();
			}
			if (enter_choice < 0)
			{
				throw runtime_error();
			}

			if (enter_choice == 1)
			{
				std::cin >> contact;


				contacts_book.AddContact(contact);
			}
			else if (enter_choice == 2)
			{
				std::cout << "total:" << contacts_book.TotalContacts() << std::endl;
			}
			else if (enter_choice == 3)
			{
				contacts_book.MergeDuplicates();
			}
			else if (enter_choice == 4)
			{
				std::cout << "enter the choice:" << std::endl;
				std::cin >> sorted_choice;
				contacts_book.PrintContactsSorted(sorted_choice);
			}
			else if (enter_choice == 5)
			{
				std::cin >> file_name;
				contacts_book.SaveToFile(file_name);
			}
			else if (enter_choice == 6)
			{
				std::cin >> file_name;
				contacts_book.LoadFromFile(file_name);
			}
			else if (enter_choice == 7)
			{
				contacts_book.PrintLoad();
			}
			else if (enter_choice == 8)
			{
				contacts_book.ListSort();
			}
			else if (enter_choice == 9)
			{
				std::string phone;
				std::cin >> phone;
				Contact* c2 = contacts_book.SearchContact(phone);
				if (c2 != NULL)
				{
					c2->Print();
				}
				else {
					std::cout << "empty" << std::endl;
				}
			}
			else if (enter_choice == 10)
			{
				contacts_book.SaveDataToList();
			}
			else if (enter_choice == 11)
			{
				std::cout << "enter str1:";
				std::cin >> str_first;
				std::cout << "enter str2:";
				std::cin >> str_last;
				contacts_book.UpdateContact(str_first, str_last);
			}
			else if (enter_choice == 12)
			{
				std::cout << "enter str1:";
				std::cin >> str_first;
				std::cout << "enter str2:";
				std::cin >> str_last;
				contacts_book.DeleteContact(str_first, str_last);
			}
			else if (enter_choice == 13)
			{
				contacts_book.LoadDataFromList();
			}
			else if (enter_choice == 14)
			{
				contacts_book.DisplayDataList();
			}
			else if (enter_choice == 15)
			{
				contacts_book.PrintFrequentlyTop5();
			}
			else if (enter_choice == 16)//create group
			{
				
					std::cout << "Enter Group Name" << std::endl;
					std::cin>> str_first;
					Group group(str_first, 5);
					std::cout << "Group with the name " << str_first << " created" << std::endl;
					group_array.AddToList(group);
				
			}
			else if (enter_choice == 17)//Add contact to group
			{
				std::cout << "Select one of the following,by entering Group Name" << std::endl;
				group_array.PrintList();
				std::getline(std::cin.ignore(), str_first);
				std::cout << "Select one of the following,by entering Contact Mobile number" << std::endl;
				contacts_book.DisplayPhoneName();
				std::cin>> str_last;
				group_temp_arr = group_array.Array();
				for (int i = 0; i < group_array.Count(); i++)
				{
					if (group_temp_arr[i].GroupName() == str_first)
					{
						group_temp_arr[i].AddContactId(str_last);
					}
				}
				group_temp_arr = NULL;
			}
			else if (enter_choice == 18)//remove contact from group
			{
			    group_temp_arr = group_array.Array();
				std::cout << "Enter Group Name to remove it" << std::endl;
				group_array.PrintList();
				std::cin>> str_first;
				std::cout << "Enter contact Mobile number to remove it" << std::endl;
				std::cin>> str_last;
				for (int i = 0; i < group_array.Count(); i++)
				{
					if (group_temp_arr[i].GroupName() == str_first)
					{
						group_temp_arr[i].RemoveContactId(str_last);
					}
				}
				group_temp_arr = NULL;
			}
			else if (enter_choice == 19)//Veiw a contact's group
			{
			    group_temp_arr = group_array.Array();
				std::cout << "Enter contact Number to veiw it's Groups" << std::endl;
				std::cin>> str_first;
				for (int i = 0; i < group_array.Count(); i++)
				{
					contact_id_list = group_temp_arr[i].ContactIdList();
					for (int j = 0; j < group_temp_arr[i].Count(); j++)
					{
						if (contact_id_list[j] == str_first)
						{
							std::cout << group_temp_arr[i].GroupName() << std::endl;
						}
					}
				}
				group_temp_arr = NULL;
			}
			else if (enter_choice == 20)//remove group
			{
			    group_temp_arr = group_array.Array();
				std::cout << "Enter Group name to remove it" << std::endl;
				group_array.PrintList();
				std::cin>> str_first;
				for (int i = 0; i <= group_array.Count(); i++)
				{
					if (group_temp_arr[i].GroupName() == str_first)
					{
						std::swap(group_temp_arr[i], group_temp_arr[group_array.Size()-1]);
						group_array.Count(group_array.Count() - 1);//Count Decremented

					}
				}
				group_temp_arr = NULL;
			}
			else if (enter_choice == 21)
			{
			group_array.SaveToFile();
            }
			else if (enter_choice == 22)
			{
			group_array.ReadFromFile();
			group_array.PrintList();
			}
			else if (enter_choice == 23)
			{
			std::string str1;
			std::cout << "enter string to search" << std::endl;
			std::cin >> str1;
			contacts_book.AdvanceSearch(str1);
			}
			else if (enter_choice == 0)
			{
				std::cout << "Thank You" << std::endl;
				return 0;
			}
			std::cout << "----------------------------------------" << std::endl;

			if (std::cin.fail())
			{
				throw runtime_error();
			}
			if (enter_choice < 0)
			{
				throw runtime_error();
			}

		}

		catch (runtime_error& e1)
		{
			std::cin.clear();
			std::cin.ignore();
			e1.what();
		}
		catch (...)
		{
			std::cout << "your enter wrong information" << std::endl;
		}


	}
}
