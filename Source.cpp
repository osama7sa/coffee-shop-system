#include<iostream>
#include <string>
int const tabels_capacity{ 11 };

void new_order(int& recipt_number, int numbers[], int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet, int& tabel_counter);
void show_order(int recipt_number, int numbers[]);
void menu_item();
void show_menu(int& recipt_number, int numbers[], int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet, int& tabel_counter);
void add_recipt(int recipts[], int front, int rear, int max, int recipt_number);
void total_sales(int recipt_number, int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet);
void add_prudct(int& item_number_drinks, int& item_number_sweet);
void add_tabel(int item);
void delete_tabel();
void show_tabels();

struct tabel {//strcutrue using linked list hold tabel number and point next tabel
	int tabel_number;
	struct tabel* next;
};

struct tabel* Head = nullptr;
struct tabel* Prev, * Curr;



struct product {//structure hold product name and price

	std::string name;
	double price{ 0 };

};
product drinks_menu[100];
product sweet_menu[100];

struct receipts_struct {//structure hold receipts information

	std::string name[20];
	int quantities[20]{ 0 };
	double price[20]{ 0 };
	double total_price{ 0 };


};
receipts_struct recipt[200];

int main() {
	int  item_number_drinks{ 4 };
	int  item_number_sweet{ 3 };
	int recipts[200];
	int max{ 200 };
	int front{ -1 };
	int rear{ -1 };
	int recipt_number{ 0 };
	int choice;
	int numbers[200]{ -1 };
	int all_quantities[100]{ 0 };
	int drinks_quantities[100]{ 0 };
	int sweet_quantities[100]{ 0 };
	int tabel_counter{ 1 };
	int make_available;


	while (true) {
		//User interface 
		std::cout << "\n\n\t\t~~Coffee Shop System~~\n\n";
		std::cout << "\n\t1-New order\n\t2-Show order \n\t3-Add product   \n\t4-Show some statsitcal Data";
		std::cout << "\t\n\t5-tables mangment\n\t6-exit\n\n";
		std::cout << "\t your choice: ";
		std::cin >> choice;

		switch (choice) {

		case 1:
			show_menu(recipt_number, numbers, drinks_quantities, sweet_quantities, item_number_drinks, item_number_sweet, tabel_counter);
			add_recipt(recipts, front, rear, max, recipt_number);

			break;

		case 2:
			show_order(recipt_number, numbers);
			break;

		case 3:
			add_prudct(item_number_drinks, item_number_sweet);
			break;

		case 4:
			total_sales(recipt_number, drinks_quantities, sweet_quantities, item_number_drinks, item_number_sweet);
			break;
		case 5:
			std::cout << "\ntotal tabeles available: " << tabels_capacity - tabel_counter;
			std::cout << "\n tables reserved number:  "; show_tabels();
			std::cout << "\n\nif you want to make table available press 1 , to return enter -1:  ";
			std::cin >> make_available;
			if (make_available == 1) {
				delete_tabel();
			}

			break;
		case 6:

			exit(false);
			break;

		default:
			std::cout << "\n\t invalid choice!\n";
			break;
		}
	}

}


void menu_item() {//function to hold menu items

	drinks_menu[0].name = "Black coffee";
	drinks_menu[0].price = 9.00;
	drinks_menu[1].name = "latte";
	drinks_menu[1].price = 14.00;
	drinks_menu[2].name = "ice latte";
	drinks_menu[2].price = 16.00;
	drinks_menu[3].name = "cappuccino";
	drinks_menu[3].price = 12.00;
	sweet_menu[0].name = "choclate cake";
	sweet_menu[0].price = 15.00;
	sweet_menu[1].name = "blueberry cake";
	sweet_menu[1].price = 15.00;
	sweet_menu[2].name = "caramel  cake";
	sweet_menu[2].price = 15.00;

}

//function to display menu
void show_menu(int& recipt_number, int numbers[], int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet, int& tabel_counter) {
	int choice;
	menu_item();
	std::cout << " \n  1- Drinks.\t\t2- Sweet.\t\t3-To Place order.\t  4-Return. " << std::endl;
	std::cin >> choice;

	if (choice != 3 && choice != 4) {
		std::cout << "\n \t---menu---\n\n";
		std::cout << "\tITEM \t\t\tPRICE \n";
	}
	if (choice == 1) {
		for (int i{ 1 }; i <= item_number_drinks; i++) {
			std::cout << i << "- " << drinks_menu[i - 1].name << "\t\t\t" << drinks_menu[i - 1].price << " SR" << std::endl;
		}
	}
	else if (choice == 2) {
		for (int i{ 1 }; i <= item_number_sweet; i++) {
			std::cout << (i + item_number_drinks) << "- " << sweet_menu[i - 1].name << "\t\t" << sweet_menu[i - 1].price << " SR" << std::endl;
		}
	}
	else if (choice == 3) {
		new_order(recipt_number, numbers, drinks_quantities, sweet_quantities, item_number_drinks, item_number_sweet, tabel_counter);
		return;
	}
	else if (choice == 4) {
		return;
	}
	else {
		std::cout << "  * INVALID INPUT * " << std::endl;

	}
	show_menu(recipt_number, numbers, drinks_quantities, sweet_quantities, item_number_drinks, item_number_sweet, tabel_counter);

}

//function to add new order
void new_order(int& recipt_number, int numbers[], int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet, int& tabel_counter) {
	recipt_number++;
	int select{ 0 };
	int quantity{ 0 };
	bool finish = true;
	int number = { -1 };
	int take_away;




	std::cout << " You can choose your order , press (-1) if you finsih ";
	do {
		numbers[recipt_number] = ++number;


		std::cout << "\nEnter your choice :";
		std::cin >> select;


		if (select != -1) {

			std::cout << "Enter the quantity :";
			std::cin >> quantity;
		}

		if (select - 1 < item_number_drinks && select != -1) {




			std::cout << "Selected :" << drinks_menu[select - 1].name << std::endl;
			recipt[recipt_number].name[number] = drinks_menu[select - 1].name;
			recipt[recipt_number].quantities[number] = quantity;
			drinks_quantities[select - 1] += quantity;
			recipt[recipt_number].price[number] = (drinks_menu[select - 1].price * quantity);

		}

		else  if (select < (item_number_drinks + item_number_sweet + 1) && select != -1) {
			std::cout << "Selected :" << sweet_menu[select - item_number_drinks - 1].name << std::endl;
			recipt[recipt_number].name[number] = sweet_menu[select - item_number_drinks - 1].name;
			recipt[recipt_number].quantities[number] = quantity;
			sweet_quantities[select - 1] += quantity;
			recipt[recipt_number].price[number] = (sweet_menu[select - item_number_drinks - 1].price * quantity);

		}


		else if (select == -1) {
			finish = false;
			std::cout << " \t\n you have finsish ordering .";
			std::cout << "\nif you want the order take away enter -1 , dine in enter 1:\n";
			std::cin >> take_away;
			if (take_away == 1) {
				add_tabel(tabel_counter);
			}
			std::cout << "	\nYour order is : \n ";
			std::cout << "---------------\n";
			std::cout << " ITEM \t\t\tQuantity\t PRICE \n";
			for (int i = 0; i < numbers[recipt_number]; i++) {
				std::cout << i + 1 << " " << recipt[recipt_number].name[i] << " \t \t " << recipt[recipt_number].quantities[i] << "\t \t " << recipt[recipt_number].price[i] << std::endl;
			}

			for (int i = 0; i < numbers[recipt_number]; i++) {
				recipt[recipt_number].total_price += recipt[recipt_number].price[i];
			}

			std::cout << " \nTHE TOTAL PRICE :" << recipt[recipt_number].total_price << " \n \n ";
			if (take_away == 1) {
				std::cout << "\nTable number: " << tabel_counter;
				tabel_counter++;
			}
			std::cout << "\n---------------";


		}

		else {
			std::cout << "\n\t invalid choice!\n";


		}




	} while (finish);



}

void show_order(int recipt_number, int numbers[]) {//fuctio to display orders
	bool finish = true;
	int choice;
	while (finish)
	{
		std::cout << " 1- Show Last order . \t 2- Show specifc order . \t 3- SHOW ALL ORDER ! \t 4 - Return . \n\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << " ITEM \t\t\tQUANTITY \t\t\t TOTAL PRICE \n";
			for (int i = 0; i < numbers[recipt_number]; i++) {
				std::cout << i + 1 << " " << recipt[recipt_number].name[i] << " \t \t " << recipt[recipt_number].quantities[i] << " \t PRICE =" << recipt[recipt_number].price[i] << std::endl;
			}
			std::cout << " THE TOTAL PRICE :" << recipt[recipt_number].total_price << " \n \n ";
			break;

		case 2:
			std::cout << " \n ENTER THE NUMBER OF THE RECIPT : \n ";
			std::cin >> choice;
			for (int i = 0; i < numbers[choice]; i++) {
				std::cout << i + 1 << " " << recipt[choice].name[i] << " \t \t " << recipt[choice].quantities[i] << " \t PRICE =" << recipt[choice].price[i] << std::endl;
			}
			std::cout << " THE TOTAL PRICE :" << recipt[choice].total_price << " \n \n ";
			break;

		case 3:

			for (int c = 1; c <= recipt_number; c++) {
				std::cout << " \n ITEM \t\t\t PRICE \n";
				for (int i = 0; i < numbers[c]; i++) {
					std::cout << i + 1 << " " << recipt[c].name[i] << " \t \t " << recipt[c].quantities[i] << " \t PRICE =" << recipt[c].price[i] << std::endl;
				}
				std::cout << " THE TOTAL PRICE :" << recipt[c].total_price << " \n \n ";
			}
			break;

		case 4:
			finish = false;
			break;
		}

	}
}

//function to Print summaries
void total_sales(int recipt_number, int drinks_quantities[], int sweet_quantities[], int  item_number_drinks, int  item_number_sweet) {
	menu_item();
	int choice;
	bool finish = true;
	double total = { 0 };
	int count = item_number_drinks + item_number_sweet;
	while (finish) {
		std::cout << " \n 1- NUMBER OF ALL ITEM SELLINGS . \t2- TOTAL PRICE FOR ALL RECIPTS . \t 3- return .\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "\n\t ITEM  \t NUMBER OF PIECE \n ";
			for (int i = 0; i < count; i++) {
				if (i < item_number_drinks) {
					std::cout << drinks_menu[i].name << " \t\t" << drinks_quantities[i] << std::endl;
				}
				else {

					std::cout << sweet_menu[i - item_number_drinks].name << " \t\t" << sweet_quantities[i] << std::endl;
				}
			}
			break;
		case 2:
			for (int c = 1; c <= recipt_number; c++) {
				total += recipt[c].total_price;

			}
			std::cout << " ##THE TOTAL PRICE FOR ALL RECIPTS IS  = " << total << " \n \n ";
			break;
		case 3:
			finish = false;
			break;
		}
	}

}

void add_prudct(int& item_number_drinks, int& item_number_sweet) {//function to add new product
	menu_item();
	int choice;
	std::cout << "1- Drink .  2-Sweet.  3- return .\n ";
	std::cin >> choice;
	std::string name;
	double price;
	switch (choice) {

	case 1:
		std::cout << "Enter the name of the product : \n";
		std::cin >> name;
		std::cout << " Enter the price of the product : \n ";
		std::cin >> price;
		drinks_menu[item_number_drinks].name = name;
		drinks_menu[item_number_drinks].price = price;
		item_number_drinks++;

		break;

	case 2:
		std::cout << "Enter the name of the product : \n";
		std::cin >> name;
		std::cout << " Enter the price of the product : \n ";
		std::cin >> price;
		sweet_menu[item_number_sweet].name = name;
		sweet_menu[item_number_sweet].price = price;
		item_number_sweet++;
		break;
	case 3:
		return;


	}


}

void add_recipt(int recipts[], int front, int rear, int max, int recipt_number) {//function to add new recipts to queue

	if (rear == max - 1)
		std::cout << " MAXIMUM RECIPT PER DAY !!! " << std::endl;
	else {
		if (front == -1)
			front = { 0 };

		rear++;
		recipts[rear] = recipt_number;

	}
}

void add_tabel(int item) {//function to add reserved tabel matched with recipt
	struct tabel* Newtabel = new tabel;
	Newtabel->tabel_number = item;
	Newtabel->next = nullptr;

	if (Head == nullptr)
	{
		Head = Newtabel; return;
	}
	if (Newtabel->tabel_number < Head->tabel_number)
	{
		Newtabel->next = Head; Head = Newtabel; return;
	}

	for (Curr = Head; Curr != nullptr; Curr = Curr->next) {
		if (Newtabel->tabel_number < Curr->tabel_number) break;
		Prev = Curr;
	}

	Newtabel->next = Prev->next;
	Prev->next = Newtabel;
}

void delete_tabel() {//function to make tabel available
	int tabel_number;
	if (Head == nullptr)
	{
		std::cout << "\n\n empty tabel list\n"; return;
	}

	std::cout << "\n enter tabel number ";
	std::cin >> tabel_number;

	if (tabel_number == Head->tabel_number)
	{
		Head = Head->next;  return;
	}

	Prev = Curr = nullptr;
	for (Curr = Head; Curr != nullptr; Curr = Curr->next)
	{
		if (Curr->tabel_number == tabel_number)  break;
		Prev = Curr;
	}

	if (Curr->tabel_number != tabel_number)
		std::cout << "\n " << tabel_number << "  not found in list\n";
	else { Prev->next = Curr->next; }

}




void show_tabels() {//function will show reserved tabels
	for (Curr = Head; Curr != nullptr; Curr = Curr->next)

		std::cout << Curr->tabel_number << "  ";
}