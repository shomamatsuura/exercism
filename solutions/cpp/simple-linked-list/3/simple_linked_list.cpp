#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    auto new_el = new Element(entry);
    new_el->next = head;
    head = new_el;
    ++current_size;
    
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(head == nullptr){
        throw std::runtime_error("Cannot pop from empty list.");
    }
    auto temp = head;
    int popped_data = temp->data;

    head = head->next;
    delete temp;
    --current_size;
    return popped_data;
    
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    Element* new_head{nullptr};
    while(head != nullptr){
        auto temp = new_head;
        new_head = head;
        head = head->next;
        new_head->next = temp;
    }
    head = new_head;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    Element* current = head;
    while(current != nullptr){
        Element* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr; // Leave the pointer clean
    
}

}  // namespace simple_linked_list
