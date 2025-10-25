#include <iostream>

class ArrayList {
private:
	int* items;
	int head;
	int tail;
	int capacity;
	int size;

public:
	ArrayList(int c) {
		items = new int[c];
		head = 0;
		tail = -1;
		capacity = c;
		size = 0;
	}

	bool empty() {
		if (size == 0) return true;
		return false;
	}

	bool full() {
		if (size == capacity) return true;
		return false;
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	int getFirst() {
		if (size > 0) return head;
	}

	int getLast() {
		if (size > 0) return tail;
	}

	int getNext(int p) {
		if (size >= p + 2) return p + 1;
	}

	int getPrev(int p) {
		if (p > 0) return p - 1;
	}

	int retrieve(int p) {
		if (p < size) return items[p];
	}

	void append(int x) {
		if (size < capacity) {
			tail++;
			items[tail] = x;
			size++;
		}
	}

	void prepend(int x) {
		if (size < capacity) {
			for (int i = tail; i >= 0; i--) {
				items[i + 1] = items[i];
			}
			tail++;
			items[head] = x;
			size++;
		}
	}

	void insert(int p, int x) {
		if (size < capacity) {
			for (int i = tail; i >= p; i--) {
				items[i + 1] = items[i];
			}
			tail++;
			items[p] = x;
			size++;
		}
	}

	void del(int p) {
		if (p >= 0 && p < size) {
			for (int i = p; i < size; i++) {
				items[i] = items[i + 1];
			}
			tail--;
			size--;
		}
	}

	void clear() {
		tail = -1;
		size = 0;
	}

	int locate(int x) {
		for (int i = 0; i < size; i++) {
			if (items[i] == x) return i;
		}
		return -1;
	}

	void deleteX(int x) {
		del(locate(x));
	}

	void deleteAllX(int x) {
		for (int i = size - 1; i >= 0; i--) {
			if (items[i] == x) {
				del(i);
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& out, ArrayList& l) {
		for (int i = 0; i < l.size; i++) {
			out << l.items[i] << " ";
		}

		return out;
	};

	~ArrayList() {
		delete[] items;
	}
};

int main()
{
	ArrayList a(5);
	std::cout << std::endl << "empty(): 1 - " << a.empty();
	std::cout << std::endl << "full(): 0 - " << a.full();
	a.append(4);
	std::cout << std::endl << a;
	a.prepend(67);
	std::cout << std::endl << a;
	std::cout << std::endl << a.locate(67);
	a.insert(1, 67);
	a.insert(1, 67);
	a.insert(1, 67);
	std::cout << std::endl << a;
	a.deleteX(67);
	std::cout << std::endl << a;
	a.deleteAllX(67);
	std::cout << std::endl << a;
	a.del(1);
	std::cout << std::endl << a;
	a.clear();
	std::cout << std::endl << a;

	return 0;
}
