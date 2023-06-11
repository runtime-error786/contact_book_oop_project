#include "menu.h"
Menu::Menu()
{

}
std::ostream& operator << (std::ostream& outi, const  Menu& m1)
{
	outi << m1.enter_data << std::endl;
	outi << m1.print_total_contacts_array << std::endl;
	outi << m1.merge << std::endl;
	outi << m1.print_sorted << std::endl;
	outi << m1.save_data << std::endl;
	outi << m1.load_data << std::endl;
	outi << m1.print_unsoted << std::endl;
	outi << m1.sort_list << std::endl;
	outi << m1.search << std::endl;
	outi << m1.save_data_list << std::endl;
	outi << m1.update << std::endl;
	outi << m1.delete_single_contact << std::endl;
	outi << m1.load_data_list << std::endl;
	outi << m1.display_list_data << std::endl;
	outi << m1.display_frequently_search << std::endl;
	outi << m1.create_group << std::endl;
	outi << m1.add_contact_group << std::endl;
	outi << m1.remove_contact_group << std::endl;
	outi << m1.view_contact_group << std::endl;
	outi << m1.remove_group << std::endl;
	outi << m1.advance_search << std::endl;
	outi << m1.save_group << std::endl;
	outi << m1.load_group << std::endl;
	return outi;
}


