#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Node.h"

int main()
{
	int sel;
	LinkedList* list1 = new LinkedList();
	int entry;
	std::ifstream infile("data.txt");
	int x = 0;
	infile >> x;
	while(infile.good()){
		list1->insert(x);
		infile >> x;
	}
	infile.close();
	std::cout<<"Data.txt elements: ";
	list1->print();
	std::cout<<"\n"<<std::endl;
	do
	{
		std::cout<<"....................................."<<std::endl;
		std::cout<<"Please choose one of the following commands"<<std::endl;
		std::cout<<"1) Insert"<<std::endl;
		std::cout<<"2) Delete"<<std::endl;
		std::cout<<"3) Print"<<std::endl;
		std::cout<<"4) Exit"<<std::endl;
		std::cin>>sel;

		if(sel==1)
		{
			std::cout<<"Choose a number to be inserted to the list: "<<std::endl;
			std::cin>>entry;
			std::cout<<"\n"<<std::endl;
			list1->insert(entry);
		}

		if(sel==2)
		{
      std::cout<<"Choose a number to be  deleted from the list"<<std::endl;
      std::cin>>entry;
      list1->erase(entry);
		}

		if(sel==3)
		{
			std::cout<<"List: ";
			list1->print();
			std::cout<<"\n"<<std::endl;
		}
	}while(sel!=4);

delete list1;

return(0);
}
