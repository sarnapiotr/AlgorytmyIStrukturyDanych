#include <iostream>

class Element {
private:
    char v;
    Element* next;

public:
    Element(char v, Element* next) {
        this->v = v;
        this->next = next;
    }

    char getValue() {
        return v;
    }

    Element* getNext() {
        return next;
    }

    void setValue(char v) {
        this->v = v;
    }

    void setNext(Element* next) {
        this->next = next;
	}
};

class LinkedFifo {
private: 
    Element* head;
    Element* tail;
public:
    LinkedFifo() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool empty() {
        return head == nullptr;
	}

    void enqueue(char x) {
        Element* element = new Element(x, nullptr);
        if (this->empty()) {
            this->head = element;
            this->tail = element;
        }
        else {
            Element* tempElement = this->tail;
            tempElement->setNext(element);
            this->tail = element;
        }
    }

    char peek() {
        if (!this->empty()) {
            return this->head->getValue();
        }
    }

    void dequeue() {
        if (!this->empty()) {
			Element* tempelement = this->head;
			this->head = tempelement->getNext();
			delete tempelement;
        }
    }

    void clear() {
        while (!this->empty()) {
            this->dequeue();
        }
	}

    ~LinkedFifo() {
        this->clear();
	}
};

int binarySearch(char* S, int n, char x) {
	int left = 0;
	int right = n - 1;

    while (left <= right) {
		int mid = (left + right) / 2;
        if (S[mid] == x) {
            return mid;
        }
        else {
            if (S[mid] < x) {
				left = mid + 1;
            }
            else {
				right = mid - 1;
            }
        }
    }

    return -1;
}

class SingleLinkedList {
private:
	Element* head;
public:
    SingleLinkedList() {
		this->head = nullptr;
    }

    void prepend(char x) {
        Element* element = new Element(x, this->head);
		this->head = element;
    }

    void deleteByValue(char x) {
		Element* tempElement = this->head;
		Element* prevElement = nullptr;

        while (tempElement != nullptr) {
            if (tempElement->getValue() == x) {
				prevElement->setNext(tempElement->getNext());
				tempElement = nullptr;
            }
            else {
				tempElement = tempElement->getNext();
				prevElement = tempElement;
            }
        }
    }

    void deleteLast() {
		Element* tempElement = this->head;
		Element* prevElement = nullptr;

        while (tempElement->getNext() != nullptr) {
			prevElement = tempElement;
			tempElement = tempElement->getNext();
		}

		prevElement->setNext(nullptr);
		tempElement = nullptr;
    }

    void insertSorted(char x) {
		Element* newElement = new Element(x, nullptr);

        if(this->head == nullptr) {
            this->head = newElement;
            return;
		}

		Element* tempElement = this->head;
		Element* prevElement = nullptr;

        while (tempElement != nullptr && tempElement->getValue() < x) {
            prevElement = tempElement;
			tempElement = tempElement->getNext();
        }

        if (prevElement == nullptr) {
            newElement->setNext(this->head);
            this->head = newElement;
        }
        else {
            prevElement->setNext(newElement);
            newElement->setNext(tempElement);
		}
    }
};

class Stos {
private:
    char* items;
    int top;
    int capacity;
public:
    Stos(int c) {
        this->items = new char[c];
		this->top = -1;
		this->capacity = c;
    }

    void push(char s) {
        if(this->top < this->capacity - 1) {
            this->top++;
            this->items[this->top] = s;
		}
    }

    void pop() {
        if (this->top != -1) {
			this->top--;
        }
    }
};

class Node {
private:
    int value;
    Node* left;
    Node* right;

public:
    Node(int v, Node* l, Node* r){
        this->value = v;
        this->left = l;
        this->right = r;
    }

    int getValue() { return this->value; };
    Node* getLeft() { return this->left; };
    Node* getRight() { return this->right; };
    void setValue(int v) { this->value = v; };
    void setLeft(Node* l) { this->left = l; };
    void setRight(Node* r) { this->right = r; };
};

class BST {
private:
    Node* root;
public:
    BST() {
		this->root = nullptr;
    }

    void insert(int x) {
		Node* newNode = new Node(x, nullptr, nullptr);

        if (this->root == nullptr) {
            this->root = newNode;
        }
        else {
            Node* tempNode = this->root;
            while (tempNode != nullptr) {
                if (tempNode->getValue() < x) {
                    if (tempNode->getLeft() == nullptr) {
                        tempNode->setLeft(newNode);
                        break;
                    }
                    else {
						tempNode = tempNode->getLeft();
                    }
                }
                else {
                    if(tempNode->getRight() == nullptr) {
                        tempNode->setRight(newNode);
                        break;
                    }
                    else {
                        tempNode = tempNode->getRight();
                    }
                }
            }
        }
    }

    void inorder(Node* n) {
		inorder(n->getLeft());
		std::cout << n->getValue() << " ";
		inorder(n->getRight());
    }

    Node* getRoot() {
		return this->root;
    }
};

int main()
{
    

    return 0;
}
