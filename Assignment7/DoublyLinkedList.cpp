#include "Node.h"
#include "Node.cpp"
using namespace std;
void createDoublyLinkedListDouble();
void createDoublyLinkedListString();
void createDoublyLinkedListInt();
int main() {
	cout << "Doubly Linked List with strings \n" << endl;
	createDoublyLinkedListString();
	cout << "\nDoubly Linked List with doubles \n" << endl;
	createDoublyLinkedListDouble();
		cout << "\nDoubly Linked List with integers \n" << endl;
		createDoublyLinkedListInt();

	return 0;
}

void createDoublyLinkedListString() {
	shared_ptr<Node<string>> start;
	weak_ptr<Node<string>> end;
	shared_ptr<Node<string>> nd = make_shared<Node<string>>("Tom");

	start = nd;
	end = start;

	auto nd1 = make_shared<Node<string>>("Dick");

	nd1->setPrevious(end);
	end.lock()->setNext(nd1);
	end = nd1;

	auto nd2 = make_shared<Node<string>>("Harry");

	nd2->setPrevious(end);
	end.lock()->setNext(nd2);
	end = nd2;

	PrintForward(start);
	PrintReverse(end);

}

void createDoublyLinkedListDouble() {
	shared_ptr<Node<double>> start;
	weak_ptr<Node<double>> end;
	shared_ptr<Node<double>> nd = make_shared<Node<double>>(47.5);

	start = nd;
	end = start;

	auto nd1 = make_shared<Node<double>>(55.6);

	nd1->setPrevious(end);
	end.lock()->setNext(nd1);
	end = nd1;

	auto nd2 = make_shared<Node<double>>(77.69);

	nd2->setPrevious(end);
	end.lock()->setNext(nd2);
	end = nd2;

	PrintForward(start);
	PrintReverse(end);

}

void createDoublyLinkedListInt() {
	shared_ptr<Node<int>> start;
	weak_ptr<Node<int>> end;
	shared_ptr<Node<int>> nd = make_shared<Node<int>>(52);

	start = nd;
	end = start;

	auto nd1 = make_shared<Node<int>>(17);

	nd1->setPrevious(end);
	end.lock()->setNext(nd1);
	end = nd1;

	auto nd2 = make_shared<Node<int>>(73);

	nd2->setPrevious(end);
	end.lock()->setNext(nd2);
	end = nd2;

	PrintForward(start);
	PrintReverse(end);

}