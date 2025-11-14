#include <iostream>

class ArrayStack {
private:
	int* items;
	int capacity;
	int top;
public:
	ArrayStack(int c) {
		items = new int[c];
		capacity = c;
		top = -1;
	}

	bool empty() {
		return top == -1;
	}

	bool full() {
		return top + 1 == capacity;
	}

	void push(int x) {
		if (!full()) {
			top++;
			items[top] = x;
		}
	}

	int peek() {
		if (!empty()) {
			return items[top];
		}
	}

	void pop() {
		if (!empty()) {
			top--;
		}
	}

	void clear() {
		top = -1;
	}

	friend std::ostream& operator<<(std::ostream& out, ArrayStack& s) {
		if (s.empty()) {
			return out;
		}

		for (int i = 0; i <= s.top; i++) {
			out << s.items[i] << " ";
		}
		return out;
	}

	~ArrayStack() {
		clear();
	}
};

class Element {
private:
	int v;
	Element* next;
public:
	Element(int x, Element* next) {
		this->v = x;
		this->next = next;
	}

	int getValue() {
		return this->v;
	}

	Element* getNext() {
		return this->next;
	}

	void setNext(Element* p) {
		this->next = p;
	}
};

class LinkedStack {
private:
	Element* top;
public:
	LinkedStack() {
		this->top = nullptr;
	}

	bool empty() {
		return this->top == nullptr;
	}

	void push(int x) {
		Element* newElement = new Element(x, this->top);
		this->top = newElement;
	}

	int peek() {
		if (!this->empty()) {
			return this->top->getValue();
		}
	}

	void pop() {
		if (!this->empty()) {
			Element* tempElement = this->top;
			this->top = tempElement->getNext();
			tempElement->setNext(nullptr);
		}
	}

	void clear() {
		while (!this->empty()) {
			this->pop();
		}
	}

	friend std::ostream& operator<<(std::ostream& out, LinkedStack& s) {
		if (s.empty()) {
			return out;
		}

		Element* tempNode = s.top;
		while (tempNode != nullptr) {
			out << tempNode->getValue() << " ";
			tempNode = tempNode->getNext();
		}
		return out;
	}

	~LinkedStack() {
		this->clear();
	}
};

class ArrayFifo {
private:
	int* items;
	int capacity;
	int size;
	int head;
	int tail;
public:
	ArrayFifo(int c) {
		items = new int[c];
		capacity = c;
		size = 0;
		head = 0;
		tail = 0;
	}

	bool empty() {
		return this->size == 0;
	}

	bool full() {
		return this->size == capacity;
	}

	void enqueue(int x) {
		if (!this->full()) {
			if (this->tail < this->capacity) {

			}
			else {

			}
		}
	}

	int peek();
	void dequeue();
	void clear();
	friend std::ostream& operator<<(std::ostream& out, ArrayFifo& f);
	~ArrayFifo();
};

int main()
{
	ArrayStack as = ArrayStack(10);
	std::cout << std::endl << "empty(): 1 - " << as.empty();
	std::cout << std::endl << "push(4): 4 -"; as.push(4); std::cout << " " << as;

	LinkedStack ls = LinkedStack();
	std::cout << std::endl << "empty(): 1 - " << ls.empty();
	std::cout << std::endl << "push(4): 4 -"; ls.push(4); std::cout << " " << ls;

	return 0;
}
