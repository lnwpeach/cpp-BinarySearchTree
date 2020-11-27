#include "Header.h"

string line(50, '=');
int menu();
int menuPrint();
int menuFind();
int main(){
	BinarySearchTree<int> a(-999);

	int ch ,ch2 ,ch3 , element, find;
	do {
		ch = menu();
		if (ch == 1) {
			cout << "Enter Element : ";
			cin >> element;
			a.insert(element);
		}
		else if (ch == 2) {
			ch2 = menuPrint();
			cout << line << endl;
			if (ch2 == 1) {
				cout << " Binary Search Tree (Preorder) : ";
				a.printPre();
			}
			else if (ch2 == 2) {
				cout << " Binary Search Tree (Inorder) : ";
				a.printTree();
			}
			else if (ch2 == 3) {
				cout << " Binary Search Tree (Postorder) : ";
				a.printPost();
			}
			cout << endl << line << endl;
			// system("pause");
		}
		else if (ch == 3) {
			do {
				ch3 = menuFind();
				if (ch3 == 1) {
					cout << "Enter Element : ";
					cin >> element;
					find = a.find(element);
					cout << line << endl;
					if (find == -999)
						cout << "\t---- Data not found ----" << endl;
					else
						cout << "\t" << find << " is element of Binary Search Tree" << endl;
					cout << line << endl;
					// system("pause");
				}
				else if (ch3 == 2) {
					find = a.findMin();
					cout << line << endl;
					if (find == -999)
						cout << "\t---- Data not found ----" << endl;
					else
						cout << "\t" << find << " is min element of Binary Search Tree" << endl;
					cout << line << endl;
					// system("pause");
				}
				else if (ch3 == 3) {
					find = a.findMax();
					cout << line << endl;
					if (find == -999)
						cout << "\t---- Data not found ----" << endl;
					else
						cout << "\t" << find << " is max element of Binary Search Tree" << endl;
					cout << line << endl;
					// system("pause");
				}
			} while (ch3 != 4);
		}
		else if (ch == 4) {
			cout << "Enter Element : ";
			cin >> element;
			find = a.find(element);
			cout << line << endl;
			if (find == -999)
				cout << "\t---- Data not found ----" << endl;
			else {
				a.remove(element);
				cout << "\t Remove " << element << " Success" << endl;
			}
			cout << line << endl;
			// system("pause");
		}
	} while (ch != 5);

	return 0;
}

int menu() {
	int ch;
	// system("cls");
	cout << line << endl;
	cout << "\tAssignment Binary Search Tree" << endl;
	cout << line << endl;
	cout << " 1. Insert" << endl;
	cout << " 2. PrintTree" << endl;
	cout << " 3. Find" << endl;
	cout << " 4. Remove" << endl;
	cout << " 5. Quit" << endl;
	cout << line << endl;
	cout << "Enter choice : ";
	cin >> ch;
	return ch;
}

int menuPrint() {
	int ch;
	cout << line << endl;
	cout << " 1. Preorder" << endl;
	cout << " 2. Inorder" << endl;
	cout << " 3. Postorder" << endl;
	cout << line << endl;
	cout << "Enter choice : ";
	cin >> ch;
	return ch;
}

int menuFind() {
	int ch;
	// system("cls");
	cout << line << endl;
	cout << "\t\tFind Menu" << endl;
	cout << line << endl;
	cout << " 1. Find Element" << endl;
	cout << " 2. Find Min" << endl;
	cout << " 3. Find Max" << endl;
	cout << " 4. Back to Mainmenu" << endl;
	cout << line << endl;
	cout << "Enter choice : ";
	cin >> ch;
	return ch;
}