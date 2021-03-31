// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList() {
        head = NULL;
    }

    template<typename ElementType>
    LinkedList<ElementType>::Node::Node(ElementType setData) {
        next = NULL;
        value = setData;
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
        head = NULL;
        for (size_t i = 0; i < values.size(); i++) {
            this->push_back(values[i]);
        }
    }

// Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList <ElementType> &source) {
        head = NULL;
        // For loop based on Memory & Iterators slides
        for (auto itr = source.begin(); itr != source.end(); ++itr) {
            this->push_back(*itr);
        }
    }

// Move constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(LinkedList <ElementType> &&source) noexcept {
        head = source.head;
        source.head = NULL;
    }

// Destructor
    template<typename ElementType>
    LinkedList<ElementType>::~LinkedList() {
        this->clear();
        delete head;
        head = NULL;
    }

// Copy assignment operator
    template<typename ElementType>
    LinkedList <ElementType> &LinkedList<ElementType>::operator=(
            const LinkedList <ElementType> &source) {
        this->clear();

        for (auto itr = source.begin(); itr != source.end(); ++itr) {
            this->push_back(*itr);
        }
        return *this;
    }

// Move assignment operator
    template<typename ElementType>
    LinkedList <ElementType> &LinkedList<ElementType>::operator=(
            LinkedList <ElementType> &&source) noexcept {
        if (this != source) {
            delete head;
            head = source.head;
            source.head = NULL;
        }
        return *this;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_front(const ElementType &value) {
        Node *new_node = new Node(value);

        if (head == NULL) {
            head = new_node;

        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_back(const ElementType &value) {
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

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const {
        if (this->empty()) {
            throw std::invalid_argument("list is empty");
        }
        return head->value;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const {
        if (this->empty()) {
            throw std::invalid_argument("list is empty");
        }
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        return current->value;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_front() {
        if (!this->empty()) {
            Node *current = head;
            head = head->next;
            delete current;
            current = NULL;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_back() {
        if (!this->empty()) {
            if (this->size() == magic_one) {
                delete head;
                head = NULL;
                return;
            }

            Node *current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    template<typename ElementType>
    size_t LinkedList<ElementType>::size() const {
        size_t count = 0;

        if (this->empty()) {
            return count;

        } else {
            for (auto itr = this->begin(); itr != this->end(); ++itr) {
                count++;
            }
        }
        return count;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {
        return head == NULL;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::clear() {
        if (this->size() == magic_one) {
            delete head;
            head = NULL;
            return;
        }

        Node *current = head;
        Node *temp = NULL;

        while (current != NULL) {
            temp = current->next;
            delete current;
            current = temp;
        }
        head = NULL;
    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os,
                             const LinkedList <ElementType> &list) {
        if (list.empty()) {
            os << "null";

        } else {
            for (auto itr = list.begin(); itr != list.end(); ++itr) {
                os << *itr << ", ";
            }
        }
        return os;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveNth(size_t n) {
        Node *current = head;

        if (n >= this->size() || n < 0 || this->empty()) {
            return;

        } else if (n == 0) {
            head = current->next;
            delete current;
            current = NULL;
            return;

        } else {
            for (int i = 0; i < n - 1; i++) {
                current = current->next;
            }

            Node *current2 = current->next->next;
            delete current->next;
            current->next = current2;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {
        if (head != NULL) {

            Node *even = head;
            Node *odd = head->next;

            while (even != NULL && odd != NULL) {
                even->next = odd->next;

                delete odd;
                odd = NULL;

                even = even->next;

                if (even != NULL) {
                    odd = even->next;
                }
            }
        }
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator==(
            const LinkedList <ElementType> &rhs) const {
        if (this->size() != rhs.size()) {
            return false;
        }

        for (auto itr = this->begin(), iterator = rhs.begin(); itr != this->end(); ++itr, ++iterator) {
            if (*iterator != *itr) {
                return false;
            }
        }
        return true;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator!=(
            const LinkedList <ElementType> &rhs) const {
        if (this->size() != rhs.size()) {
            return true;
        }

        for (auto itr = this->begin(), iterator = rhs.begin(); itr != this->end(); ++itr, ++iterator) {
            if (*iterator != *itr) {
                return true;
            }
        }
        return false;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::
    operator++() {
        this->current_ = this->current_->next;
        return *this;
    }

    template<typename ElementType>
    ElementType &LinkedList<ElementType>::iterator::operator*() const {
        return this->current_->value;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator!=(
            const typename LinkedList<ElementType>::iterator &other) const {
        return this->current_ != other.current_;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
        return iterator(head);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
        return iterator(nullptr);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator &
    LinkedList<ElementType>::const_iterator::operator++() {
        this->current_ = this->current_->next;
        return *this;
    }

    template<typename ElementType>
    const ElementType &LinkedList<ElementType>::const_iterator::operator*() const {
        return this->current_->value;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::const_iterator::operator!=(
            const typename LinkedList<ElementType>::const_iterator &other) const {
        return this->current_ != other.current_;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator
    LinkedList<ElementType>::begin() const {
        return const_iterator(head);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
        return const_iterator(nullptr);
    }

}  // namespace cs126linkedlist
