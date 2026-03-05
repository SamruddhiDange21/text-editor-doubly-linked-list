#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char ch) {
        data = ch;
        prev = nullptr;
        next = nullptr;
    }
};

// Text editor using doubly linked list
class TextEditor {
    Node* head;    
    Node* tail;    
    Node* cursor; 

public:
    TextEditor() {
        head = tail = cursor = nullptr; 
    }

    // Insert a character after cursor
    void insertChar(char ch) {
        Node* newNode = new Node(ch);

        if (!head) {  // Empty list
            head = tail = cursor = newNode;
        } else if (!cursor) { // Cursor at end
            tail->next = newNode;
            newNode->prev = tail;
            tail = cursor = newNode;
        } else {  // Insert after cursor
            newNode->next = cursor->next;
            newNode->prev = cursor;

            if (cursor->next)
                cursor->next->prev = newNode;

            cursor->next = newNode;

            if (cursor == tail)
                tail = newNode;

            cursor = newNode; // Move cursor to new node
        }
    }

    // Delete character before cursor
    void deleteChar() {
        if (!cursor) {
            cout << "Nothing to delete.\n";
            return;
        }

        Node* temp = cursor;

        // Update links
        if (cursor->prev)
            cursor->prev->next = cursor->next;
        if (cursor->next)
            cursor->next->prev = cursor->prev;

        if (cursor == head)
            head = cursor->next;
        if (cursor == tail)
            tail = cursor->prev;

        cursor = cursor->prev; // Move cursor left
        delete temp;
    }

    // Move cursor left
    void moveLeft() {
        if (cursor && cursor->prev)
            cursor = cursor->prev;
        else
            cout << "Cursor at beginning.\n";
    }

    // Move cursor right
    void moveRight() {
        if (cursor && cursor->next)
            cursor = cursor->next;
        else
            cout << "Cursor at end.\n";
    }

    // Display text with cursor
    void display() {
    Node* temp = head;
    cout << "Text: ";
    while (temp) {
        cout << temp->data; // Just print characters
        temp = temp->next;
    }
    cout << endl;
}

};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout <<"\n 1.Insert\n 2.Delete\n 3.Move Left\n 4.Move Right\n 5.Display\n 6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> ch;
                editor.insertChar(ch);
                break;
            case 2:
                editor.deleteChar();
                break;
            case 3:
                editor.moveLeft();
                break;
            case 4:
                editor.moveRight();
                break;
            case 5:
                editor.display();
                break;
            case 6:
                cout << "Exited.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    return 0;
}
