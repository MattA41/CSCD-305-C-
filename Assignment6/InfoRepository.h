#include "InfoNode.h"
#include <string>
#include <iostream>
using namespace std;

template<class T, class U, class V>
class InfoRepository {
public:
	InfoRepository(string name) :first(0), iName(name) {}
	~InfoRepository();
	void addInfo(T t, U u, V v);
	bool isEmpty();
	void printInformation();
	void retrieveInfoNode(const T& t);
private:
	InfoNode<T, U, V>* first;
	std::string iName;
};

template <class T, class U, class V>
InfoRepository<T, U, V>::~InfoRepository()
{
	first->next = NULL;
	//unlinks the nodes from the first losing the list to garbage collection
	first = NULL;

}

template <class T, class U, class V>
void InfoRepository<T, U, V>::addInfo(T t, U u, V v)
{
	//creates a new node and links it to the first node
	InfoNode<T, U, V>* newNode = new InfoNode<T, U, V>(t, u, v, first);
	first = newNode;
}

template <class T, class U, class V>
bool InfoRepository<T, U, V>::isEmpty()
{
	if (first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T, class U, class V>
void InfoRepository<T, U, V>::printInformation()
{
	cout << "printing " << iName << " info..." << "\n" << endl;

	InfoNode<T, U, V>* current = first;
	while (current != NULL)
	{
		cout << current->dataOne << " " << current->dataTwo << " " << current->dataThree << endl;
		current = current->next;
	}
	cout << "\n" << endl;
}

template <class T, class U, class V>
void InfoRepository<T, U, V>::retrieveInfoNode(const T& t)
{
	cout << "Retrieving Node with ID " << t << " from the database....." << "\n" << endl;
	InfoNode<T, U, V>* current = first;
	while (current != NULL)
	{
		if (current->dataOne == t)
		{
			cout << "Node found with ID: " << "was found in the database."<<"\n" << "Here is the information" << "\n" << endl;
			cout << current->dataOne << " " << current->dataTwo << " " << current->dataThree << endl;
			return;
		}
		current = current->next;
	}
	std::cout << "No node with id " << t << " exists in the list" << endl;
}
