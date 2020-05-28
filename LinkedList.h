//***********   CSCD 305                 ***********
//***********   Md Abul Kashem           *********** 
//***********  Linked list nested class  ***********
//***********   Puttting all togather    ***********

#pragma once

#include<iostream>
#include<cstdlib>
#include<memory>
#include<string>
#include <iterator>

using namespace std;

//singly linked with no dummy/buffer node
template <class T>
class LinkedList {

	class Node {
	public:
		T data;
		Node *next;
		Node(T data = NULL, Node *next = NULL) { this->data = data; this->next = next; }

		bool operator == (const Node& rhs)const {
			if (this->data != rhs.data) {
				return false;
			}
			else
				return true;
		
		};

		bool operator < (const Node& rhs)const {
			if (this->data > rhs.data) {
				return false;
			}
			else
				return true;
		
		};
		bool operator > (const Node& rhs)const {
			if (this->data < rhs.data) {
				return false;
			}
			else
				return true;

		};

		~Node();
	};

	Node *head;
	//Node *tail;
	int size;
	

public:
	LinkedList() { this->head = NULL; this->size = 0; }
	////copy constructor 
	LinkedList(LinkedList& source) {
		this->head = NULL;
		this->size = 0;
		Node * cur =source.head;
		for (int i = 0; i < source.size; i++ ) {
			add(cur->data);
			cur = cur->next;
			//this->head = new Node(tem->data, tem->next);
		}	
		this->size = source.size;
		cout << "Copy contrustor called ........"<<endl;
	};

	////copy assignment operator overload
	const LinkedList& operator=(const LinkedList& original) {
		
		this->head = NULL;
		this->size = 0;
		Node * cur = original.head;
		for (int i = 0; i < original.size; i++) {
			add(cur->data);
			cur = cur->next;
			//this->head = new Node(tem->data, tem->next);
		}
		this->size = original.size;
			cout << "Copy assignment operator called ........"<<endl;
		
		return *this;
	};

	//move costructor
	LinkedList(LinkedList && move);
	
	//move assignment 
	LinkedList& operator=(LinkedList&& rhs) {
		if (this != &rhs) {
			//delete this->head;
			if (this->head != NULL) {
				Node * cur = this->head;
				for (int i = 0; i < this->size; i++) {
					head = cur->next;
					delete cur;
					cur = this->head;

				}
			}
			this->head = rhs.head;
			this->size = rhs.size;
			cout << "Move assignment operator called ........" << endl;

			rhs.head = nullptr;
			rhs.size = 0.0;
		}
		return *this;
	};

	// Overloading [] operator 
	
	T& operator[] (const unsigned index)
	{
		Node * cur = this->head;
		int i = 0;
		while (cur->next && i < index) {
			cur = cur->next;
			i++;
		}
		//cout << cur->data<<endl;
			return cur->data;
	} 
	
	// == operator overload 
	bool operator == (const LinkedList& rhs)const;

	void checkRange(int index) {
		if (index >= this->size) {
			throw "Out of range !!!!";
		}
	}
	void badRange(int index) {
		if (index > (this->size-1)||index <0) {
			throw "Bad index  !!!!";
		}
	}
	//***********************************************
	//**************** << operator overload ***********
	friend ostream &operator<<(ostream& output, const LinkedList &c) {
		for (Node *cur = c.head; cur != NULL; cur = cur->next) {
			output << cur->data << endl;
		}
		return output;
	};
	// + operator verload 
	LinkedList operator+(const LinkedList &rhs){
		//Node * cur = this->head;
		
		// add lhs and rhs node then create a new node.
		Node * nPtr1 = this->head;
		Node * nPtr2 = rhs.head;
		LinkedList<T> newList;
		/*if (this->size == rhs.size) {
			while (nPtr1 != NULL && nPtr2 != NULL) {
				T nData = nPtr1->data + nPtr2->data;
				newList.head = new Node(nData, newList.head);
				nPtr1 = nPtr1->next;
				nPtr2 = nPtr2->next;
				newList.size++;
				

			}
		} */

		while (nPtr1!=NULL) {
			newList.add(nPtr1->data);
			nPtr1 = nPtr1->next;
		}
		while (nPtr2 != NULL) {
			newList.add(nPtr2->data);
			nPtr2 = nPtr2->next;
		}

		return newList;
	};
	void addFirst(T data);

	// add element at last
	void add(T data);
	//add element at a position
	void add(int index, T data); \
   // sort function
   void sort();

	int getSize() {
		return this->size;
	}

	//**************************************
	//****************remove data***********

	bool remove();
	T remove(int index);
	bool removeAll();
	void print(ostream& out = cout) const;
	/*****************************************for iterator class start *********************/
	
	class Iterator;

	Iterator begin()
	{
		return Iterator(head);
	}

	// End of LInkedList wrapped in Iterator type
	Iterator end()
	{
		return Iterator(nullptr);
	}

	class Iterator {

		friend class LinkedList;
	public:
		Iterator() noexcept :
			m_pCurrentNode(head) { }

		Iterator(const Node* pNode) noexcept :
			m_pCurrentNode(pNode) { }

		Iterator& operator=(Node* pNode)
		{
			this->m_pCurrentNode = pNode;
			return *this;
		}
		// Prefix ++ overload
		Iterator& operator++()
		{
			if (m_pCurrentNode)
				m_pCurrentNode = m_pCurrentNode->next;
			return *this;
		}

		// Postfix ++ overload
		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++*this;
			return iterator;
		}

		bool operator!=(const Iterator& iterator)
		{
			return m_pCurrentNode != iterator.m_pCurrentNode;
		}

		int operator*()
		{
			return m_pCurrentNode->data;
		}
	private:
		const Node* m_pCurrentNode;
	};

	/*****************************************for iterator class end *********************/


	~LinkedList();
};




template <class T>
void LinkedList<T>::print(ostream& out) const {
	out << "List size is: " << this->size << endl;
	for (Node *cur = this->head; cur != NULL; cur = cur->next) {
		out << cur->data << endl;
	}
}

template<class T>
bool LinkedList<T>::operator==(const LinkedList & rhs) const
{
	if (this->size != rhs.size ) {
		return false;
	}

	Node * nPtr1=this->head;
	Node * nPtr2 = rhs.head;
	while (nPtr1 != NULL && nPtr2!=NULL) {
		if (nPtr1->data != nPtr2->data) {
			
			return false;
		}
		nPtr1 = nPtr1->next;
		nPtr2 = nPtr2->next;
		
	}
	
	
	
	return true;

}



// add element at first
template <class T>
void LinkedList<T>::addFirst(T data) {
	this->head = new Node(data, this->head);
	this->size++;
}

// add element at last
template<class T>
void LinkedList<T>::add(T data) {
	Node * cur;
	if (this->head == NULL) {
		this->head = new Node(data, NULL);
		this->size++;
	}
	else {
		for (cur = this->head; cur->next !=NULL; cur=cur->next) {

		}
		cur->next = new Node(data, NULL);
		this->size++;
	}
}
// add element at a position
template<class T>
void LinkedList<T>::add(int index, T data)
{
	
	
	Node * cur=this->head;
	Node * temp=new Node(data, NULL);
	Node * temp2;
	if (index ==0) {
		addFirst(data);
	}
	try
	{
		checkRange(index);
		if (index != 0) {
			int i = 0;
			while (cur->next && i < index) {
				cur = cur->next;
				temp->data = cur->data;
				i++;
			}
			temp2 = cur;

			cur->data = data;
			cur->next = new Node(temp->data, temp2->next);
			this->size++;
		}

	}
	catch (const char * msg)
	{
		cout << msg << endl;

	}
	
}
/********************************************************/
//********************* sort linkedlist *****************
template<class T>
void LinkedList<T>::sort()
{
	Node * cur ;
	Node * temp ;
		for (cur = this->head; cur->next != NULL; cur = cur->next) {

		for (temp = cur->next; temp!=NULL; temp = temp->next) {
			if (cur->data > temp->data) {
				//cout << "firt:" << temp->data << "second : " << cur->data << endl;
				//temp2->data = cur->data;
				T data = cur->data;
				cur->data = temp->data;
				temp->data = data;
				//temp->data = temp2->data;
			}
			

		}
		
	}
	
	
}
// **********remode data ****************
//***************************************


template<class T>
bool LinkedList<T>::remove() {
	Node * cur = this->head;
	if (this->head==NULL) {
		cout << "The list is empty." << endl;
	}
	else {
		head = cur->next;
		delete(cur);
		this->size--;
	}
	
	return true;

}

template<class T>
T LinkedList<T>::remove(int index)
{
	Node * cur = this->head;
	
	Node * preNode;
	Node * nextNode;
	
	try
	{
		badRange(index);
		if (index != 0) {
			int i = 0;
			while (cur->next && i < index-1) {
				cur = cur->next;
				i++;
			}
			preNode = cur;
			cur = cur->next;
		     nextNode = cur->next;
			 preNode->next = nextNode;
			 delete(cur);
			this->size--;
		}

	}
	catch (const char * msg)
	{
		cout << msg << endl;

	}

	return T();
}

template<class T>
bool LinkedList<T>::removeAll()    // this function delete all
{
	Node * cur = this->head;
	if (this->head == NULL) {
		cout << "The list is empty." << endl;
	}
	else {
		for (int i = 0; i < this->size;i++) {
			head = cur->next;
			delete cur;
			cur = this->head;
			
		}
		this->size=0;
		
	}
	return false;
}


//***********************************************
//**************************************************
//move constructor implimentation 
template<class T>
LinkedList<T>::LinkedList(LinkedList&& move) {
	
		Node * tem = move.head;
		for (int i = 0; i < move.size; i++) {

			this->head = new Node(tem->data, tem->next);
		}
		this->size = move.size;

		for (int j = 0; j < move.size; j++) {

			move.head = nullptr;
		}

		move.size = 0.0;
		cout << "move constructor called......" << endl;

	
}


template<class T>
LinkedList<T>::~LinkedList()
{
	cout << "Firing destructor..........."<<endl;
	
	Node * cur = this->head;
	if (this->head == NULL) {
		cout << "The list is empty." << endl;
	}
	else {
		for (int i = 0; i < this->size; i++) {
			head = cur->next;
			delete cur;
			cur = this->head;

		}
		this->size = 0;

	}
	
}

template<class T>
LinkedList<T>::Node::~Node()
{
	cout << "Firing Node destructor..........." << endl;
	
}
