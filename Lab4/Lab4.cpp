#include <iostream>

class Element {
private:
	int v;
	Element* next;
	Element* prev;

public:
	Element(int x, Element* next, Element* prev) {
		this->v = x;
		this->next = next;
		this->prev = prev;
	}

	int getValue() {
		return this->v;
	}

	void setValue(int v) {
		this->v = v;
	}

	Element* getNext() {
		return this->next;
	}

	Element* getPrev() {
		return this->prev;
	}

	void setNext(Element* p) {
		this->next = p;
	}

	void setPrev(Element* p) {
		this->prev = p;
	}
};


class LinkedList {
private:
	Element* head;
	Element* tail;
	int size;

public:
	LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	bool empty() {
		return this->size == 0;
	}

	int getSize() {
		return this->size;
	}

	Element* getFirst() {
		return this->head;
	}

	Element* getLast() {
		return this->tail;
	}

	Element* getNext(Element* p) {
		return p->getNext();
	}

	Element* getPrev(Element* p) {
		return p->getPrev();
	}

	int retrieve(Element* p) {
		return p->getValue();
	}

	void append(int x) {
		if (empty()) {
			Element* e = new Element(x, nullptr, nullptr);
			this->head = e;
			this->tail = e;
		}
		else {
			Element* e = new Element(x, nullptr, this->tail);
			this->tail->setNext(e);
			this->tail = e;
		}
		this->size++;
	}

	void prepend(int x) {
		if (empty()) {
			Element* e = new Element(x, nullptr, nullptr);
			this->head = e;
			this->tail = e;
		}
		else {
			Element* e = new Element(x, this->head, nullptr);
			this->head->setPrev(e);
			this->head = e;
		}
		this->size++;
	}

	friend std::ostream& operator<<(std::ostream& out, LinkedList* l) {
		if (l->empty()) {
			return out;
		}

		Element* tempNode = l->getFirst();
		while (tempNode != nullptr) {
			out << tempNode->getValue() << " ";
			tempNode = tempNode->getNext();
		}
		return out;
	}

	Element* locate(int x) {
		Element* tempNode = this->head;
		while (tempNode != nullptr) {
			if((tempNode->getValue() == x)) {
				return tempNode;
			}
			tempNode = tempNode->getNext();
		}
		return nullptr;
	}

	void clear() {
		Element* tempNode = this->head;
		while (tempNode != nullptr) {
			Element* nextNode = tempNode->getNext();
			delete tempNode;
			tempNode = nextNode;
		}
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	~LinkedList() {
		clear();
	}
};

int main()
{
	//Zadanie 1 - przykładowy sposób testowania
	LinkedList* a = new LinkedList();
	std::cout << std::endl << "empty(): 1 - " << a->empty();
	std::cout << std::endl << "getSize(): 0 - " << a->getSize();
	std::cout << std::endl << "append(4): 4 - "; a->append(4);
	std::cout << a << std::endl;
	a->append(5); a->append(6); a->append(7); a->append(8);
	std::cout << " " << a;
	a->clear();
	std::cout << " " << a;

	return 0;
}
