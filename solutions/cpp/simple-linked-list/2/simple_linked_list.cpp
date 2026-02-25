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
    auto element = new Element{entry};    
    element->next = head;
    head = element;
    ++current_size;
        
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(head == nullptr){
        throw std::runtime_error("Cannot pop from empty list.");
    }
    auto element = head;
    head = head->next;
    int data = element->data;
    delete element;
    --current_size;
    return data;
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
    while(head != nullptr){
        Element* next = head->next;
        delete head;
        head = next;
    }
}

}  // namespace simple_linked_list
