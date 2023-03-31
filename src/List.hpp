#pragma once

#include <iostream>

template <typename T>
struct Node {
    T data;
    struct Node* next;
    struct Node* prev;

    Node() {
        next = nullptr;
        prev = nullptr;
    }

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class List {
    Node<T>* head;

    Node<T>* tail;

   public:
    List();

    List(const List& other);

    List<T>& operator=(const List<T>& other);

    List(List&& other);

    List<T>& operator=(List<T>&& other);

    ~List();

    void append(T newdata);

    void push(T newdata);

    void insertAt(int index, T newdata);

    void pop();

    void removeLast();

    void removeAt(int index);

    int getSize() const;

    Node<T>* getByIndex(int index);

    void print() const;

    void printAt(int index);

    void destroy();
};

template <typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
List<T>::List(const List<T>& other) {
    head = nullptr;
    tail = nullptr;
    Node<T>* tmp = other.head;
    while (tmp != nullptr) {
        append(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this == &other) {
        return *this;
    }
    destroy();
    head = nullptr;
    tail = nullptr;
    Node<T>* tmp = other.head;
    while (tmp != nullptr) {
        append(tmp->data);
        tmp = tmp->next;
    }

    return *this;
}

template <typename T>
List<T>::List(List&& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& other) {
    if (this == &other) {
        return *this;
    }
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    return *this;
}

template <typename T>
List<T>::~List() {
    destroy();
}

template <typename T>
void List<T>::append(T newdata) {
    Node<T>* tmp = new Node<T>(newdata);
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
}

template <typename T>
void List<T>::push(T newdata) {
    Node<T>* tmp = new Node<T>(newdata);
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
}

template <typename T>
void List<T>::insertAt(int index, T newdata) {
    if (index == 0) {
        push(newdata);
        return;
    }
    if (index == getSize()) {
        append(newdata);
        return;
    }
    Node<T>* current = getByIndex(index);
    Node<T>* tmp = new Node<T>(newdata);

    current->prev->next = tmp;
    tmp->next = current;
    tmp->prev = current->prev;
    current->prev = tmp;
}

template <typename T>
void List<T>::pop() {
    if (head == tail) {
        delete head;
        return;
    }
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

template <typename T>
void List<T>::removeLast() {
    if (head == tail) {
        delete head;
        return;
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

template <typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop();
        return;
    }
    if (index == getSize() - 1) {
        removeLast();
        return;
    }
    Node<T>* current = getByIndex(index);
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

template <typename T>
int List<T>::getSize() const {
    Node<T>* tmp = head;
    int size = 0;
    while (tmp != nullptr) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

template <typename T>
Node<T>* List<T>::getByIndex(int index) {
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

template <typename T>
void List<T>::print() const {
    Node<T>* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

template <typename T>
void List<T>::printAt(int index) {
    Node<T>* current = getByIndex(index);
    if (current != nullptr) {
        std::cout << current->data << std::endl;
    }
}

template <typename T>
void List<T>::destroy() {
    Node<T>* tmp = head;
    if (tmp == nullptr) {
        return;
    }
    while (tmp->next != nullptr) {
        tmp = tmp->next;
        delete tmp->prev;
    }

    delete tail;
    head = nullptr;
    tail = nullptr;
}