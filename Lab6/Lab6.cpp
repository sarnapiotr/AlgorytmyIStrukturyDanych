#include <iostream>

class Node {
private:
	int value;
	Node* left;
	Node* right;
	Node* parent;

public:
	Node(int v, Node* l, Node* r, Node* p) {
		this->value = v;
		this->left = l;
		this->right = r;
		this->parent = p;
	}

	int getValue() {
		return this->value;
	}

	Node* getLeft() {
		return this->left;
	}

	Node* getRight() {
		return this->right;
	}

	Node* getParent() {
		return this->parent;
	}

	void setValue(int v) {
		this->value = v;
	}

	void setLeft(Node* l) {
		this->left = l;
	}

	void setRight(Node* r) {
		this->right = r;
	}
	void setParent(Node* p) {
		this->parent = p;
	}
};

class BSTree {
private:
	Node* root;

public:
	BSTree() {
		this->root = nullptr;
	}

	Node* getRoot() {
		return this->root;
	}

	bool empty(Node* p) {
		if (p == nullptr) return true;
		return false;
	}

	void inorder(Node* p) {
		if(!empty(p)) {
			inorder(p->getLeft());
			std::cout << p->getValue() << " ";
			inorder(p->getRight());
		}
	}

	void insert(int x) {
		Node* n = new Node(x, nullptr, nullptr, nullptr);
		Node* tempNode = this->root;


		if (empty(this->root)) {
			this->root = n;
		}
		else {
			while (true) {
				if (tempNode->getValue() > x) {
					if (tempNode->getLeft() == nullptr) {
						tempNode->setLeft(n);
					}
					else {
						tempNode = tempNode->getLeft();
					}
				}
				else {
					if(tempNode->getRight() == nullptr) {
						tempNode->setRight(n);
					}
					else {
						tempNode = tempNode->getRight();
					}
				}
			}
		}
	}

	Node* search(int x) {
		if (empty(this->root)) return nullptr;
		else {
			Node* tempNode = this->root;
			while (tempNode != nullptr) {
				if (tempNode->getValue() == x) {
					return tempNode;
				}
				else if (tempNode->getValue() > x) {
					tempNode = tempNode->getLeft();
				}
				else {
					tempNode = tempNode->getRight();
				}
			}
			return nullptr;
		}
	}

	Node* minimum(Node* p) {
		if(empty(p)) return nullptr;
		else {
			Node* tempNode = p;
			while (tempNode->getLeft() != nullptr) {
				tempNode = tempNode->getLeft();
			}
			return tempNode;
		}
	}

	Node* maximum(Node* p) {
		if(empty(p)) return nullptr;
		else {
			Node* tempNode = p;
			while (tempNode->getRight() != nullptr) {
				tempNode = tempNode->getRight();
			}
			return tempNode;
		}
	}

	Node* successor(Node* p) {
		if (empty(p)) return nullptr;
		if (p->getRight() != nullptr) {
			return minimum(p->getRight());
		}
		else {
			Node* tempNode = p->getParent();
			while (tempNode != nullptr && p == tempNode->getRight()) {
				p = tempNode;
				tempNode = tempNode->getParent();
			}
			return tempNode;
		}
	}
	Node* predecessor(Node* p) {
		if (empty(p)) return nullptr;
		else {
			if (p->getLeft() != nullptr) {
				return maximum(p->getLeft());
			}
			else {
				Node* tempNode = p->getParent();
				while (tempNode != nullptr && p == tempNode->getLeft()) {
					p = tempNode;
					tempNode = tempNode->getParent();
				}
				return tempNode;
			}
		}
	}

	void del(Node* p) {
		p->setParent(nullptr);
		p->setLeft(nullptr);
		p->setRight(nullptr);
	}
};

int main()
{


	return 0;
}
