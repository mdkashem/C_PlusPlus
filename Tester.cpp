//***********   CSCD 305                 ***********
//***********   Md Abul Kashem           *********** 
//***********  Linked list nested class  ***********
//***********   Puttting all togather    ***********

#include "LinkedList.h"
#include"complex.h"
using namespace std;



int main(void) {
	/* create complex number  test linked list */
	complex_class complex1 =complex_class(1.0,2.5);
	complex_class complex2 = complex_class(2.0, 1.5);
	complex_class complex3 = complex_class(3.0, 6.5);
	complex_class complex4 = complex_class(4.0, 6.5);
	LinkedList<complex_class> complexList; // create a Lnked list for complex number 

	//complexList.addFirst(complex1);
	
	complexList.add(complex1); // add the complex2 at the last of the list, but first time make it first item.
	complexList.add(complex2); // add the complex3 at the last of the list.
	complexList.add(complex3); // add the complex3 at the last of the list.
	complexList.add(2, complex4); // add the complex4 at the index 2. index start from 0.
	 /* ******** << operator overload test *****************/
	
	
	
	/**************** equality test bellow*************/
	LinkedList<complex_class> compareOne; // this compareOne for == test.
	LinkedList<complex_class> compareTwo;// another list for test

	compareOne.add(complex1);
	compareOne.add(complex2);
	compareOne.add(complex3);

	compareTwo.add(complex1);
	compareTwo.add(complex2);
	compareTwo.add(complex3);

	LinkedList<complex_class> com1;
	com1.add(complex3);
	
/**************************finish equality(==) check ************************/
	
	

	LinkedList<int> intList;  //list that holds int values
	LinkedList<int> intList2;
	intList.add(4);
	intList.add(3);
	intList.add(2);
	intList.add(1);
	intList.add(100);
	intList.add(200);
	
	//*******************************************
	// for anding item test 
	LinkedList<int> insertLast;
	LinkedList<string> insertString;
	


	//********************************************
	LinkedList<string> removeTest;
	removeTest.add("cherry");
	removeTest.add("banana");
	removeTest.add("strawberry");
	removeTest.add("apple");
	
	/****************************/

	/* + operator overload (this will concatenate two lists - the result is a new LinkedList that contains a deep copy of the two existing lists) */
	LinkedList<int> list1;
	LinkedList<int> list2;
	list1.add(2);
	list1.add(5);
	list2.add(2);
	list2.add(2);
	LinkedList<int> bigList;
	// + operator overload finish.
	//***************************


	// for copy contructor test 
	LinkedList<string> strList;
	strList.add("cherry");
	strList.add("banana");
	strList.add("strawberry");
	strList.add("apple");

	//for copy assignment test
	LinkedList<int> score;
	LinkedList<int> grade;
	score.add(90);
	score.add(95);
	score.add(98);

	// for move constructor
	LinkedList<string> fruits;
	fruits.add("cherry");
	fruits.add("banana");
	fruits.add("strawberry");
	fruits.add("apple");
	 
	// for move assignment test
	LinkedList<string> strList4;
	LinkedList<string> pLanguage;
	pLanguage.add("Cplusplus");
	pLanguage.add("Java");
	pLanguage.add("Python");
	

	
	int operation; ///user input
	while (true) {
		cout << "*******Welcome to test the Linked List ********"<<endl;
		cout << "MENU:\n\nEnter 1 for default and explicit constructors test.\n";
		cout << "Enter 2 for copy constructor (deep copy)\n";
		cout << "Enter 3 for move constructor (&&) (C++11)\n";
		cout << "Enter 4 for destructor\n";
		cout << "Enter 5 for = operator overload\n";
		cout << "Enter 6 for move = operator overload (&&) (C++11)\n";
		cout << "Enter 7 for == operator overload\n";
		cout << "Enter 8 for [ ] operator overload\n";
		cout << "Enter 9 for + operator overload\n";
		cout << "Enter 10 for << operator overload\n";
		cout << "Enter 11 for add(data): adds at end of list\n";
		cout << "Enter 12 for add(index, data): adds at index, throw an exception if index is out of range\n";
		cout << "Enter 13 to remove(data):\n";
		cout << "Enter 14 for remove(index):\n";
		cout << "Enter 15 for removeAll(data):\n";
		cout << "Enter 16 for sort\n";
		cout << "Enter 17 for nested Iterator class that can be used with a C++ 11 for loop \n";
		cout << "Enter 18 to Exit\n\n";
		cin >> operation;

		if (operation == 18) {
			break;              // exit
		}
		switch (operation) {
		case 1: { 
			LinkedList<int> intOne;
			LinkedList<complex_class> complexOne;
			LinkedList<string> stringOne;
			

		}break;

		case 2: {  //for copy constructor (deep copy)\n
			
			cout << "Before copy strList Size: " << strList.getSize() << endl << strList << endl;
			LinkedList<string> strList3 = strList; // testing copy constructor
			cout << "After copy strList to strList3 Size: " << strList3.getSize() << endl << strList3 << endl;
			
		}
				break;
		case 3: {  //for move constructor (&&) (C++11)\n
			
			LinkedList<string> moveFruits(std::move(fruits)); 
			
			/*Note: this also call destrutor when out of scope.*/
			cout << "New list :" << endl << moveFruits << endl;
			
		}

				break;
		case 4: { //for destructor\n";
			/* when out of this case 4 this program call distructors */
			LinkedList<string> temp;
			temp.add("cherry");
			temp.add("banana");
			temp.add("strawberry");
			temp.add("apple");
			
		}
				break;
		case 5: {  //for = operator overload\n";
			grade = score; //I force a copy assignment 
			cout << "After copied to new list: "<<endl << grade << endl;

		}break;

		case 6: { //for move = operator overload (&&) (C++11)\n";
			strList4 = std::move(pLanguage);
			cout << "programming Language Size: " << pLanguage.getSize() << pLanguage << endl;
			cout << "New list Size: " << strList4.getSize() << endl << strList4 << endl;
		}
				break;
		case 7: {  //for == operator overload
			cout << "**********Test == : for same value *********" << endl;// test for same value
			if (compareOne == compareTwo) {   // compareOne and compareTwo both linked list have same values
				cout << "Both are same." << endl;
			}
			else {
				cout << "Both lists are different." << endl;
			};
			// now test for diffrent value 
			cout << "**********Test == : for different value *********" << endl;
			

			if (com1 == compareTwo) {
				cout << "Both are same." << endl;
			}
			else {
				cout << "Both lists are different." << endl;
			};

		}break;

		case 8: { //for [ ] operator overload
			cout <<"complexList: " <<endl<<complexList << endl;
			cout << "[] test: return value from index 1. *****Note: index start from 0" << endl;
			cout << complexList[1] << endl;  // test for [] operator. it will return the data at the specific index
			cout << " Assign value at index 2 & print updated list" << endl;
			complexList[2] = complex1;   // assign complex1 at the position 
			cout << complexList << endl;     // print again to see the update.

		}
				break;
		case 9: {//for + operator overload
			bigList = list1 + list2;
			cout << "After concatenate two lists - the result is:" << endl << bigList << endl;

		}

				break;
		case 10: {  //for << operator overload
			cout << pLanguage << endl;
			cout << "complexList: " << endl << complexList << endl;

		}
				break;
		case 11: { //for add(data): adds at end of list

			int data;
			cout<< "Please Enter a integer:" <<endl;
			cin >> data;
			insertLast.add(data);
			cout << "Please Enter a integer:" << endl;
			cin >> data;
			insertLast.add(data);
			cout << "Please Enter a integer:" << endl;
			cin >> data;
			insertLast.add(data);
			cout<<"You entered: "<<endl <<insertLast <<endl;

			cout << "Please Enter a String:" << endl;
			string  str;
			cin >> str;
			insertString.add(str);
			cout << "Please Enter a String:" << endl;
			cin >> str;
			insertString.add(str);
			cout << "Please Enter a String:" << endl;
			cin >> str;
			insertString.add(str);
			cout << "You entered: "<<endl << insertString << endl;


		}break;

		case 12: { // for add(index, data): adds at index, throw an exception if index is out of range
			cout << "print the existing list :" <<" size : "<<intList.getSize()<<endl << intList << endl;
			
			intList.add(2, 50);   //  
			cout << "print after adding 50 at index 2 :" << " size : " << intList.getSize() << endl << intList << endl;
			intList.add(7, 50); // chacking the bounce 
			cout << "print again to see the exception call:" << " size : " << intList.getSize() << endl << intList << endl;

		}
		case 13: {  //remove(data): deletes the first instance of specified data, returns a bool
			cout << "Before remove the first node: " << endl << intList << endl;
			intList.remove(); //remove first node
			cout << "after remove the first node: " << endl << intList << endl;


		}

				break;
		case 14: {  // for remove(index)
			cout << "Before remove  data from a specific index :" << " size : " << removeTest.getSize() << endl << removeTest << endl;

			removeTest.remove(1);
			cout << "After remove data from index 1:" << " size : " << removeTest.getSize() << endl << removeTest << endl;

			

		}
				break;
		case 15: { //removeAll(data): deletes all instances of the specified data, returns a bool

			cout << "Before remove all data:" << " size : " << removeTest.getSize() << endl << removeTest << endl;

			removeTest.removeAll();
			cout << "After remove all data:" << " size : " << removeTest.getSize() << endl << removeTest << endl;
			
		}			

				break;
		case 16: { // for sort
			cout << "Before sort:" << endl << intList << endl;
			intList.sort();  // Sort the list 
			cout <<"After sort"<<endl<< intList << endl; // print list after sort.

			//cout << "Before sort:" << endl << fruits << endl;
			//fruits.sort();  // Sort the list 
			//cout << "After sort :" << endl << fruits << endl; // print list after sort.

		}
				 break;
		case 17: { //for nested Iterator class that can be used with a C++ 11 for loop
			cout << "Traversing LinkedList through Iterator" << endl;
			for (LinkedList<int>::Iterator iterator = intList.begin();
				iterator != intList.end(); iterator++)
			{
				cout << *iterator << endl;
			}


		}
				 break;
		}
		
	}

	//cin.get();
	//system("pause");

	return 0;
}