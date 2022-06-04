
#include <iostream>//input and outputs
#include <string>
#include<stdlib.h>
#include <cstdlib>

using namespace std;
/* linked  head->node->next->node->next-null singly linked list*/


/*
* GitHUb: akaldhafer

*/
struct Patient
{
	int ID;
	string title;
	string writer;
	string category;
	int quantity;
	float price;
	Patient* next;
};

struct Purchase {
	int ID;
	int PurchaseID;
	string bName;
	string date;
	int quantity;
	float price;
	float totalPayment;

	Purchase* next2;
};
Patient* head = NULL; //we create our head
Purchase* head2 = NULL;
string name; //name of admin for login

//For Book Linkedlist
int BookID = 1;
int position;
int linkedSize = 0;

//For Purchase Linkedlist
int Purchaseid = 1;
int position2;
int linkedSize2 = 0;

//declare the functions
int main();
void MainMenu();
void InsertArbitraryBook(int ID, string title, string writer, string category, int quantity, float price, int position);
void InsertArbitraryPurchase(int PurchaseID, int ID, string btitle, string date, int quantity, float price, float totalPayment, int position2);
void addbook();
void displaybooks(Patient* head);
void InventoryMenu();

void TransactionMenu();
void searchbooksByID();
void searchPurchaseByID();
void filterbook();
void filterPurchase();
void Updatebookdetails();
void addPurchase();
void displayPurchase(Purchase* head2);
void salesstatistics();
bool deletebook(Patient* position, Patient*& Head);
Patient* searchbookID(int id, Patient* head);

void insertionSortWaitingListByTime(struct Patient** head_ref);
void sortWitingListByTime(struct Patient** head_ref, struct Patient* new_node);

void sortedInsertTotalAmount(struct Purchase** head_ref, struct Purchase* new_node);
void insertionSortTotalAmount(struct Purchase** head_ref);


//To insert New record into the Book Linkedlist
void InsertArbitraryBook(int ID, string title, string writer, string category, int quantity, float price, int position)
{
	Patient* newNode = new Patient;
	newNode->ID = ID;
	newNode->title = title;
	newNode->writer = writer;
	newNode->category = category;
	newNode->quantity = quantity;
	newNode->price = price;
	if (linkedSize >= position)//size = 20    position = 3
	{
		if (position == 0)//insert at the beginning 
		{
			newNode->next = head;
			head = newNode;
		}
		else if (linkedSize == position) //size = 20   position 20//insert at the end
		{
			newNode->next = NULL;
			if (head == NULL) //insert at the beginning 
			{
				head = newNode;
			}
			else {
				Patient* current = head;//start from the head first node
				while (current->next != NULL)//run while the node->next is not equal to null
				{
					current = current->next;
				}
				current->next = newNode; //insert at the last node

			}
		}
		else //insert at the given position
		{ 
			Patient* prev = head;
			for (int i = 0; i < position; i++)
			{
				prev = prev->next;
			}
			newNode->next = prev->next;// we will take the address of the prev node and give it to the new node
			prev->next = newNode; //we will give the new node address to the prev-next to connect them
		}

	}
	else if (linkedSize < position) //size = 20  position= 25// insert at the end 
	{
		newNode->next = NULL;
		if (head == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			Patient* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;

		}
	}

}

//To insert New record into the Purchase Linkedlist
void InsertArbitraryPurchase(int PurchaseID, int ID, string btitle, string date, int quantity, float price, float totalPayment, int position2) {
	Purchase* newNode = new Purchase;
	newNode->PurchaseID = PurchaseID;
	newNode->ID = ID;
	newNode->bName = btitle;
	newNode->date = date;
	newNode->quantity = quantity;
	newNode->price = price;
	newNode->totalPayment = totalPayment;
	if (linkedSize2 >= position2)//size = 20    position = 3
	{
		if (position2 == 0)//insert at the beginning 
		{
			newNode->next2 = head2;
			head2 = newNode;
		}
		else if (linkedSize2 == position2) //size = 20   position 20//insert at the end
		{
			newNode->next2 = NULL;
			if (head2 == NULL) //insert at the beginning 
			{
				head2 = newNode;
			}
			else {
				Purchase* current = head2;//start from the head first node
				while (current->next2 != NULL)//run while the node->next is not equal to null
				{
					current = current->next2;
				}
				current->next2 = newNode; //insert at the last node

			}
		}
		else //insert at the given position
		{ /// node2->newNode->node3->...
			Purchase* prev = head2;
			for (int i = 0; i < position2; i++)
			{
				prev = prev->next2;
			}
			newNode->next2 = prev->next2;// we will take the address of the prev node and give it to the new node
			prev->next2 = newNode; //we will give the new node address to the prev-next to connect them
		}

	}
	else if (linkedSize2 < position2) //size = 20  position= 25// insert at the end 
	{
		newNode->next2 = NULL;
		if (head2 == NULL) {
			newNode->next2 = head2;
			head2 = newNode;
		}
		else {
			Purchase* current = head2;
			while (current->next2 != NULL)
			{
				current = current->next2;
			}
			current->next2 = newNode;

		}
	}

}

//Function to add a new book to the linkedlist
void addbook() {
	string  btitle, bwriter, bcategory;
	char conf;
	int quantity;
	float price;
	getchar();
	cout << "\nEnter Book title: "; getline(cin, btitle, '\n');
	cout << "\nEnter Book writer: "; getline(cin, bwriter, '\n');
	cout << "\nEnter Book category: "; getline(cin, bcategory, '\n');

	cout << "\nEnter Book quantity: "; cin >> quantity;
	cout << "\nEnter Book price: "; cin >> price;
	cout << "\nEnter where you want to insert the record: "; cin >> position;
	cout << "\nWould you like to confirom the details(y,n): "; cin >> conf;
	if (conf == 'Y' || conf == 'y')
	{
		InsertArbitraryBook(BookID, btitle, bwriter, bcategory, quantity, price, position);
		linkedSize++;
		BookID++;
		cout << "\nThe record has been added successfully !\n";
	}
	else {
		cout << "\nThe record cancelled !\n";
	}
}

//Function to add a new purchase record
void addPurchase() {
	Patient* current = head;
	bool flag2 = false;
	string date;
	char conf2;
	int quantity, id;
	float totalPayment, payment, remainder = 0;
	cout << "\nEnter BooK ID to Purchase: "; cin >> id;
	getchar();
	cout << "\nEnter the date of Purchase (dd/mn/yyyy): "; getline(cin, date, '\n');
	cout << "\nEnter quantity: "; cin >> quantity;
	//Confirm the purchase
	cout << "\nWould you like to confirom the Purchase (y,n): "; cin >> conf2;
	if (conf2 == 'Y' || conf2 == 'y')
	{
		while (current != NULL)
		{
			//Check if the id is available
			if (id == current->ID)
			{
				flag2 = true;
				//Check the quantity
				if (quantity <= current->quantity) {
					cout << "\nBook title       : " << current->title;
					cout << "\nBook price       : " << current->price;
					totalPayment = quantity * current->price;
					cout << "\nTotal payment    : " << totalPayment;
					cout << "\nEnter the payment:"; cin >> payment;
					remainder = payment - totalPayment;
					cout << "\n The remainder   : " << remainder;
					current->quantity -= quantity;
					InsertArbitraryPurchase(Purchaseid, id, current->title, date, quantity, current->price, totalPayment, Purchaseid);
					linkedSize2++;
					Purchaseid++;
					cout << "\nThe Purchase record has been added successfully !\n";
				}
				else {

					cout << "\nThere is no enough quantity!\n";
				}
			}
			current = current->next;
		}
		if (flag2 == false) {
			cout << "\nThe given ID is not availabe, please choose the correct one from the above list!\n";
		}

	}
	else {
		cout << "\nThe Purchase is cancelled !\n";
	}
}

void displaybooks(Patient* head) {
	Patient* current = head;
	if (current == NULL)
	{
		cout << "\nThere is no record yet, please add first !\n";
	}
	while (current != NULL)
	{
		cout << "\nBook ID         : " << current->ID;
		cout << "\nBook title      : " << current->title;
		cout << "\nBook writer     : " << current->writer;
		cout << "\nBook category   : " << current->category;
		cout << "\nBook quantity   : " << current->quantity;
		cout << "\nBook price      : " << current->price;
		cout << "\n----------------------------------------\n";
		current = current->next;
	}

}

void salesstatistics() {
	Purchase* current = head2;
	float totalsales = 0;
	if (current == NULL)
	{
		cout << "\nThere is no Purchase yet, please add first !\n";
	}
	while (current != NULL)
	{
		totalsales += current->totalPayment;
		current = current->next2;
	}
	cout << "\nTotal sales of all Purchases : " << totalsales << endl;
}

void displayPurchase(Purchase* head2) {
	Purchase* current = head2;
	if (current == NULL)
	{
		cout << "\nThere is no Purchase yet, please add first !\n";
	}
	while (current != NULL)
	{
		cout << "\nPurchase ID         : " << current->PurchaseID;
		cout << "\nBook ID             : " << current->ID;
		cout << "\nBook title          : " << current->bName;
		cout << "\nPurchase date       : " << current->date;
		cout << "\nBook quantity       : " << current->quantity;
		cout << "\nBook price          : " << current->price;
		cout << "\nThe Total Payment   : " << current->totalPayment;
		cout << "\n--------------------------------------------------\n";
		current = current->next2;
	}

}


void searchbooksByID() {
	int id;
	bool flag = false;
	Patient* current = head;
	cout << "\nEnter book ID to search: "; cin >> id;

	if (current == NULL)
	{
		cout << "\nThere is no record yet, please add first !\n";
	}
	while (current != NULL)
	{
		if (id == current->ID)
		{
			cout << "\nBook ID         : " << current->ID;
			cout << "\nBook title      : " << current->title;
			cout << "\nBook writer     : " << current->writer;
			cout << "\nBook category   : " << current->category;
			cout << "\nBook quantity   : " << current->quantity;
			cout << "\nBook price      : " << current->price;
			cout << "\n----------------------------------------\n";
			flag = true;
		}
		current = current->next;
	}
	if (flag == false)
	{
		cout << "\nThere is no match to the given ID !\n";
	}

}

void searchPurchaseByID() {
	int id;
	bool flag4 = false;
	Purchase* current = head2;
	cout << "\nEnter book ID or Purchase ID to search: "; cin >> id;

	if (current == NULL)
	{
		cout << "\nThere is no Purchase yet, please add first !\n";
	}
	while (current != NULL)
	{
		if (id == current->ID || id == current->PurchaseID)
		{
			cout << "\nPurchase ID         : " << current->PurchaseID;
			cout << "\nBook ID             : " << current->ID;
			cout << "\nBook title          : " << current->bName;
			cout << "\nPurchase date       : " << current->date;
			cout << "\nBook quantity       : " << current->quantity;
			cout << "\nBook price          : " << current->price;
			cout << "\nThe Total Payment   : " << current->totalPayment;
			cout << "\n--------------------------------------------------\n";
			flag4 = true;
		}
		current = current->next2;
	}
	if (flag4 == false)
	{
		cout << "\nThere is no match to the given ID !\n";
	}

}


void filterbook() {
	string category;
	bool flag = false;
	Patient* current = head;
	cout << "\nEnter book category to filter: "; cin >> category;

	if (current == NULL)
	{
		cout << "\nThere is no record yet, pls add first !\n";
	}
	while (current != NULL)
	{
		if (category == current->category)
		{
			cout << "\nBook ID         : " << current->ID;
			cout << "\nBook title      : " << current->title;
			cout << "\nBook writer     : " << current->writer;
			cout << "\nBook category   : " << current->category;
			cout << "\nBook quantity   : " << current->quantity;
			cout << "\nBook price      : " << current->price;
			cout << "\n----------------------------------------\n";
			flag = true;
		}
		current = current->next;
	}
	if (flag == false)
	{
		cout << "\nThere is no match to the given Category!\n";
	}

}

void filterPurchase() {
	string title;
	bool flag3 = false;
	Purchase* current = head2;
	cout << "\nEnter book title to filter: "; cin >> title;

	if (current == NULL)
	{
		cout << "\nThere is no Purchase yet, please add first !\n";
	}
	while (current != NULL)
	{
		if (title == current->bName)
		{
			cout << "\nPurchase ID         : " << current->PurchaseID;
			cout << "\nBook ID             : " << current->ID;
			cout << "\nBook title          : " << current->bName;
			cout << "\nPurchase date       : " << current->date;
			cout << "\nBook quantity       : " << current->quantity;
			cout << "\nBook price          : " << current->price;
			cout << "\nThe Total Payment   : " << current->totalPayment;
			cout << "\n--------------------------------------------------\n";
			flag3 = true;
		}
		current = current->next2;
	}
	if (flag3 == false)
	{
		cout << "\nThere is no match to the given book title!\n";
	}

}


void InventoryMenu()
{
	system("cls");
	char choice;
	int bkid;
	do
	{
		cout << "\n           Inventory Menu\n";
		cout << "\n1. Add a new book.";
		cout << "\n2. Display all books.";
		cout << "\n3. Search for a book based on ID.";
		cout << "\n4. Filter for books based on category.";
		cout << "\n5. Update book details.";
		cout << "\n6. Delete a book. ";
		cout << "\n7. Sort books based on quantity. ";
		cout << "\n8. Back";
		cout << "\nEnter your option: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			addbook();
			break;
		case '2':
			displaybooks(head);
			break;
		case '3':
			searchbooksByID();
			break;
		case '4':
			filterbook();
			break;
		case '5':
			Updatebookdetails();
			break;
		case '6':
			cout << "\nEnter the Book ID you want to delete\n";
			cin >> bkid;
			if (deletebook(searchbookID(bkid, head), head) == true) {
				cout << "\nThe book record was deleted successfully\n";
			}
			else {
				cout << "\nCould not delete the book record\n";
			}
			break;
		case '7':
			insertionSortWaitingListByTime(&head);
			displaybooks(head);
			break;
		case '8':
			MainMenu();
			break;
		default:
			cout << "\nWrong option, retry again!\n";
			break;
		}
		system("pause");
		system("cls");

	} while (choice != '8');

}

void TransactionMenu() {
	system("cls");
	char choice2;
	do
	{
		cout << "\n           Transaction Menu\n";
		cout << "\n1. Purchase a book.";
		cout << "\n2. View all Purchases.";
		cout << "\n3. Sort Purchases based on Total amount.";
		cout << "\n4. View Purchase based on book title.";
		cout << "\n5. Search Purchase based on book ID or Purchase ID.";
		cout << "\n6. Sales Statistics. ";
		cout << "\n7. Back";
		cout << "\nEnter your option: ";
		cin >> choice2;
		switch (choice2)
		{
		case '1':
			displaybooks(head);
			addPurchase();
			break;
		case '2':
			displayPurchase(head2);
			break;
		case '3':
			insertionSortTotalAmount(&head2);
			displayPurchase(head2);
			break;
		case '4':
			filterPurchase();
			break;
		case '5':
			searchPurchaseByID();
			break;
		case '6':
			salesstatistics();
			break;
		case '7':
			MainMenu();
			break;
		default:
			cout << "\nWrong option, retry again!\n";
			break;
		}
		system("pause");
		system("cls");

	} while (choice2 != '7');
}

int main() {
	system("cls");
	string password;
	int attempt = 0;
	do {
		system("color E1");
		cout << "\n           Book Store Management System\n";
		cout << "\nEnter your details to log in: \n";
		cout << "\n   Enter your name: "; cin >> name;
		cout << "\n   Enter your password (by default (1234)) : "; cin >> password;
		if (password == "1234") {
			system("color E2");
			cout << "\nYou have logged in successfully :) \n";
			system("pause");
			system("cls");
			MainMenu();
		}
		else {
			system("color E4");
			cout << "\nThe password entered is wrong!\n";
			attempt++;
		}
		system("pause");
		system("cls");
	} while (attempt < 5);
	cout << "\nYou have reached the limit of allowed attempts, the system will be terminated :( \n";
	return 0; //For termination
}

void MainMenu() {
	system("cls");
	system("color E1");
	char option;
	do
	{
		cout << "\n           Book Store\n";
		cout << "\nWelcome back, " << name;
		cout << "\n1. Inventory service";
		cout << "\n2. Transaction Service";
		cout << "\n3. Log Out";
		cout << "\nEnter your option: ";
		cin >> option;
		switch (option)
		{
		case '1':
			InventoryMenu();
			break;
		case '2':
			TransactionMenu();
			break;
		case '3':
			main();
			break;
		default:
			cout << "\nWrong option, retry again!\n";
			break;
		}
	} while (option != '3');
}

void Updatebookdetails() {
	int id, updatedquantity;
	float updatedprice;
	char updateoption;
	bool flag = false;
	Patient* current = head;
	cout << "\nEnter book ID to update: "; cin >> id;

	if (current == NULL)
	{
		cout << "\nThere is no record yet, pls add first !\n";
	}
	while (current != NULL)
	{
		if (id == current->ID)
		{
			cout << "\n The current details are:";
			cout << "\nBook ID         : " << current->ID;
			cout << "\nBook title      : " << current->title;
			cout << "\nBook quantity   : " << current->quantity;
			cout << "\nBook price      : " << current->price;
			cout << "\n----------------------------------------\n";
			flag = true;
			cout << "\nEnter 1 to update the price \n Enter 2 to update the quantity\n Enter one option:  ";
			cin >> updateoption;

			if (updateoption == '1') {
				cout << "\nEnter the new price: ";
				cin >> updatedprice;
				current->price = updatedprice;
			}
			else if (updateoption == '2') {
				cout << "\nEnter the new quantity: ";
				cin >> updatedquantity;
				current->quantity = updatedquantity;
			}
			else {
				cout << "\nYou have entered a wrong option\n";
				Updatebookdetails();
			}
		}
		current = current->next;
	}
	if (flag == false)
	{
		cout << "\nThere is no match to the given ID !\n";
	}
}


Patient* searchbookID(int id, Patient* head)
{
	Patient* current = head;
	if (head == NULL) {
		cout << "\nNo record added yet\n";
	}
	while (current != NULL) {
		if (current->ID == id) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return NULL;
}

bool deletebook(Patient* position, Patient*& Head) {
	if (position == NULL) {
		cout << "\nThe given ID is not found\n";
		return false;
	}
	else if (position == Head) {
		Head = position->next;
		delete position;
		linkedSize--;
		return true;
	}
	else {
		Patient* current = Head;
		while (current != NULL) {
			if (current->next == position) {
				current->next = position->next;
				delete position;
				linkedSize--;
				return true;
			}
			current = current->next;
		}
		return false;
	}
	

}
/*For sort the book records based on the quantity*/
/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortWitingListByTime(struct Patient** head_ref, struct Patient* new_node)
{
	struct Patient* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->quantity >= new_node->quantity)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL && current->next->quantity < new_node->quantity)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}


// function to sort a singly linked list using insertion sort
void insertionSortWaitingListByTime(struct Patient** head_ref)
{
	// Initialize sorted linked list
	struct Patient* sorted = NULL;

	// Traverse the given linked list and insert every
	// node to sorted
	struct Patient* current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration
		struct Patient* next = current->next;

		// insert current in sorted linked list
		sortWitingListByTime(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted linked list
	*head_ref = sorted;
}


/*For sort the purchases records based on the total payment*/
/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsertTotalAmount(struct Purchase** head_ref, struct Purchase* new_node)
{
	struct Purchase* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->totalPayment >= new_node->totalPayment)
	{
		new_node->next2 = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next2 != NULL && current->next2->totalPayment < new_node->totalPayment)
		{
			current = current->next2;
		}
		new_node->next2 = current->next2;
		current->next2 = new_node;
	}
}


// function to sort a singly linked list using insertion sort
void insertionSortTotalAmount(struct Purchase** head_ref)
{
	// Initialize sorted linked list
	struct Purchase* sorted = NULL;

	// Traverse the given linked list and insert every
	// node to sorted
	struct Purchase* current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration
		struct Purchase* next = current->next2;

		// insert current in sorted linked list
		sortedInsertTotalAmount(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted linked list
	*head_ref = sorted;
}
