#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    unsigned int current_size{0};
    Element* new_head = head;
    while(new_head != nullptr){
        ++current_size;
        new_head = new_head->next;
    }
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    Element* new_element = new Element(entry);
    if(head == nullptr){
        head = new_element;
    } else{
        new_element->next = head;
        head = new_element;
        
    }
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(head == nullptr) return 0;
    int result = head->data;
    head = head->next;
    return result;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    if(head == nullptr) return;
    Element* reversed_element = new Element(head->data);
    while(head->next != nullptr){
        Element* inesrt_element = new Element(head->next->data);
        inesrt_element->next = reversed_element;
        reversed_element = inesrt_element;
        head = head->next;
    }
    
    head = reversed_element;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    delete[] head;
}

}  // namespace simple_linked_list
