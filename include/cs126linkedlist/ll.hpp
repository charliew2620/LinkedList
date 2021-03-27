// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
    head = NULL;
}

    template<typename ElementType>
    LinkedList<ElementType>::Node::Node(ElementType setData) {
        next = NULL;
        data = setData;
    }


template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        this->push_back(values[i]);
    }
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
    // For loop based on Memory & Iterators slides
    for (auto i = source.begin(); i != source.end(); i++) {
        this->push_back(i);
    }
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
    // https://www.educative.io/edpresso/what-is-a-move-constructor-in-cpp
    this->head = source.head;
    source.head = NULL;
}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
    delete head;
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
    this == NULL;
    for (size_t i = 0; i < source.size(); i++) {
        this->push_back(source[i]);
    }
    return *this;
}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {
    // https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-160
    if (this != source) {
        delete head;
        head = source.head;
        source.head = NULL;
        return *this;
    }
}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
    if (head == NULL) {
        head = value;

    } else {
        value->next = head;
        head = value;
    }
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
    Node *new_node = new Node(value);

    if (head == NULL) {
        head = new_node;

    } else {
        Node *current = head;

        while (current && current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
    size_t count = 0;

    if (this->empty()) {
        return count;

    } else {
        for (auto i = this->begin(); i != this->end(); ++i) {
            count++;
        }
    }
    return count;
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
    if (head != NULL) {
        return false;

    } else {
        return true;
    }
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {
    this->current_ = this->current_->next;
    return *this;
}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
    return this->current_->data;
}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {
    return this->current_ != other.current_;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {
    const_iterator start(head);
    return start;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
    Node *current = head;

    while (current && current->next != NULL) {
        current = current->next;
    }
    const_iterator end(current);
    ++end;
    return end;
}

}  // namespace cs126linkedlist
