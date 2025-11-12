#ifndef PROJECT_3_LIST342_H
#define PROJECT_3_LIST342_H

#include <filesystem>
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
struct Node {
    T *data_;
    Node *next_;
};

template <class T>
class List342 {
public:
    // Constructors
    List342(); // Initializes with empty head_
    List342(const List342& list); // Initializes with deep copied head_
    ~List342(); // Destroys List after code is done executing

    // Getters
    Node<T>* head() const; // Returns head_

    // Setters
    void setHead(Node<T> *node); // Sets to different head_

    // Methods
    bool BuildList(string file_name); // Reads into a given file creating objects of the chosen type
    bool Insert(T* data); // Inserts data members and makes sure duplicates aren't created
    bool Remove(T target, T& result); // Removes the data member that is targeted and returns that value to the result
    bool Peek(T target, T& result); // Runs the same as the Remove function but doesn't remove the value
    int Size() const; // Returns the size of the list
    void DeleteList(); // Deletes all values in the list
    bool Merge(List342& list); // Merges two lists while maintaining order and no duplicates
    string toString() const; // Returns a readable representation of the list

    // Operator Overloads
    List342& operator=(const List342& list); // Does a deep copy of the list to the given list
    List342 operator+(const List342& list) const; // Returns a merged copy of the two lists inputted
    List342& operator+=(const List342& list); // Merges two given lists without editing the second one
    bool operator==(const List342& list) const; // Compares two lists for equals
    bool operator!=(const List342& list) const; // Compares two lists for not equals
    template <class U>
    friend ostream& operator<<(ostream& os, const List342<U>& list); // Outputs the list to the given output stream

private:
    // Private Variables
    Node<T>* head_; // Holds the data as nodes in head_
};

// Constructors
template <class T>
List342<T>::List342() {
    head_ = nullptr;
}
template <class T>
List342<T>::List342(const List342<T> &list) {
    head_ = nullptr;
    *this = list;
}
template <class T>
List342<T>::~List342() {
    DeleteList();
}

// Getters
template <class T>
Node<T>* List342<T>::head() const {
    return head_;
}

// Setters
template <class T>
void List342<T>::setHead(Node<T> *node) {
    head_ = node;
}

// List Methods
template <class T>
bool List342<T>::BuildList(string file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        return false;
    }

    T obj;
    while (file >> obj) {
        this->Insert(new T(obj));
    }
    file.close();
    return true;
}
template <class T>
bool List342<T>::Insert(T* data) {
    Node<T> *newNode = new Node<T>;
    newNode->data_ = new T(*data);
    newNode->next_ = nullptr;
    if (head_ == nullptr) {
        head_ = newNode;
        return true;
    }
    if (*head_->data_ == *data) {
        delete newNode->data_;
        delete newNode;
        return false;
    }
    if (*head_->data_ > *data) {
        newNode->next_ = head_;
        head_ = newNode;
        return true;
    }
    Node<T> *node = head_;
    while (node->next_ != nullptr) {
        if (*node->next_->data_ == *data) {
            delete newNode->data_;
            delete newNode;
            return false;
        }
        if (*node->next_->data_ > *data) {
            newNode->next_ = node->next_;
            node->next_ = newNode;
            return true;
        }
        node = node->next_;
    }
    node->next_ = newNode;
    return true;
}
template <class T>
bool List342<T>::Remove(T target, T &result) {
    if (head_ == nullptr) {
        return false;
    }
    if (*(head_->data_) == target) {
        result = *(head_->data_);
        Node<T> *temp = head_;
        head_ = head_->next_;
        delete temp->data_;
        delete temp;
        return true;
    }
    Node<T> *node = head_;
    while (node->next_ != nullptr) {
        if (*(node->next_->data_) == target) {
            Node<T> *temp = node->next_;
            node->next_ = node->next_->next_;
            result = *(temp->data_);
            delete temp->data_;
            delete temp;
            return true;
        }
        node = node->next_;
    }
    return false;
}
template <class T>
bool List342<T>::Peek(T target, T &result) {
    if (head_ == nullptr) {
        return false;
    }
    if (*(head_->data_) == target) {
        result = *(head_->data_);
        return true;
    }
    Node<T> *node = head_;
    while (node->next_ != nullptr) {
        if (*(node->next_->data_) == target) {
            result = *(node->next_->data_);
            return true;
        }
        node = node->next_;
    }
    return false;
}
template <class T>
int List342<T>::Size() const {
    Node<T> *node = head_;
    int count = 0;
    while (node != nullptr) {
        count++;
        node = node->next_;
    }
    return count;
}
template <class T>
void List342<T>::DeleteList() {
    Node<T> *node = head_;
    head_ = nullptr;
    while (node != nullptr) {
        Node<T> *temp = node;
        node = node->next_;
        delete temp->data_;
        delete temp;
    }
}
template <class T>
bool List342<T>::Merge(List342 &list) {
    if (list.head_ == nullptr || *this == list) {
        return true;
    }
    if (this->head_ == nullptr) {
        head_ = list.head_;
        list.head_ = nullptr;
        return true;
    }

    Node<T> *listNode = list.head_;
    Node<T> *node = head_;
    if (*head_->data_ == *listNode->data_) {
        Node<T> *temp = listNode;
        listNode = listNode->next_;
        delete temp->data_;
        delete temp;
        list.head_ = listNode;
    }
    if (listNode != nullptr && *head_->data_ > *listNode->data_) {
        Node<T> *temp = listNode;
        listNode = listNode->next_;
        temp->next_ = node;
        node = temp;
        head_ = temp;
    }
    while (node->next_ != nullptr) {
        if (listNode == nullptr) {
            list.head_ = nullptr;
            return true;
        }
        if (*node->next_->data_ == *listNode->data_) {
            Node<T> *temp = listNode;
            listNode = listNode->next_;
            delete temp->data_;
            delete temp;
            list.head_ = listNode;
        }
        if (listNode != nullptr && *node->next_->data_ > *listNode->data_) {
            Node<T> *temp = listNode;
            listNode = listNode->next_;
            temp->next_ = node->next_;
            node->next_ = temp;
        }
        node = node->next_;
    }
    if (listNode != nullptr) {
        node->next_ = listNode;
    }
    list.head_ = nullptr;
    return true;
}
template <class T>
string List342<T>::toString() const {
    string toStr = "";
    Node<T> *node = head_;
    if (head_ == nullptr) {
        toStr += "Empty List\n";
    }
    if (head_ != nullptr) {
        toStr += "List Contents: \n";
        while (node != nullptr) {
            toStr += to_string(*(node->data_)) + " ";
            node = node->next_;
        }
        toStr += "\n";
    }
    toStr += "Size: " + to_string(this->Size()) + "\n";
    return toStr;
}

// Operator Overloads
template <class T>
List342<T>& List342<T>::operator=(const List342<T> &list) {
    if (*this == list) {
        return *this;
    }
    this->DeleteList();
    if (list.head_ == nullptr) {
        return *this;
    }
    head_ = new Node<T>;
    Node<T> *listNode = list.head_;
    Node<T> *node = head_;
    Node<T> *temp = head_;
    while (listNode->next_ != nullptr) {
        node->data_ = new T(*(listNode->data_));
        node->next_ = new Node<T>;
        node = node->next_;
        listNode = listNode->next_;
    }
    node->data_ = new T(*(listNode->data_));
    node->next_ = nullptr;
    this->setHead(temp);
    return *this;
}
template <class T>
List342<T> List342<T>::operator+(const List342<T>& list) const {
    List342<T> thisList = *this;
    List342<T> listList = list;
    thisList.Merge(listList);
    return thisList;
}
template <class T>
List342<T>& List342<T>::operator+=(const List342& list) {
    List342<T> listList = list;
    this->Merge(listList);
    return *this;
}
template <class T>
bool List342<T>::operator==(const List342 &list) const {
    if (this->Size() != list.Size()) {
        return false;
    }
    if (Size() == 0 && list.Size() == 0) {
        return true;
    }
    Node<T> *listNode = list.head_;
    Node<T> *node = head_;
    while (listNode != nullptr && node != nullptr) {
        if (*(listNode->data_) != *(node->data_)) {
            return false;
        }
        listNode = listNode->next_;
        node = node->next_;
    }
    if (listNode != nullptr || node != nullptr) {
        return false;
    }
    return true;
}
template <class T>
bool List342<T>::operator!=(const List342 &list) const {
    return !(*this == list);
}
template <class U>
ostream& operator<<(ostream& os, const List342<U>& list) {
    Node<U> *node = list.head_;
    while (node != nullptr) {
        os << *(node->data_);
        node = node->next_;
    }
    return os;
}

#endif //PROJECT_3_LIST342_H