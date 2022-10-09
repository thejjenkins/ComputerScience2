 #include <iostream>
using namespace std;

class LinkedListNode {
    public:
    LinkedListNode(int dataValue) {
        cout << "In LinkedListNode constructor (" << dataValue << ")\n";
        data = dataValue;
    }

    ~LinkedListNode() {
        cout << "In LinkedListNode destructor (" << data << ")\n";
    }

    int data;
    LinkedListNode* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void Prepend(int dataValue);

    LinkedListNode* head;
};

LinkedList::LinkedList() {
    cout << "In LinkedList constructor\n";
    head = nullptr;
}

LinkedList::~LinkedList() {
    cout << "In LinkedList destructor\n";

    // The destructor deletes each node in the Linked list
    while (head) {
        LinkedListNode* next = head->next;
        delete head;
        head = next;
    }
}

void LinkedList::Prepend(int dataValue) {
    LinkedListNode* newNode = new LinkedListNode(dataValue);
    newNode->next = head;
    head = newNode;
}

int main() {
    // Create a linked list
    LinkedList* list = new LinkedList;
    for (int i=1; i<=5; ++i) {
        list->Prepend(i*10);
    }
    
    // Free the linked list.
    // The LinkedList class destructor frees each node.
    delete list;

    return 0;
}

/*
1. A linked list is created and 5 dynamically allocated nodes are prepended.
2. Deleting the list calls the LinkedList class destructor.
3. The destructor deletes each node in the list.
4. After calling ~LinkedList(), the delete operator frees memory for the linked list's head pointer. All memory for the linked list has been freed.
*/
