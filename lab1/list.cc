#include <iostream>
#include "list.h"



List::List() {
first=nullptr;
}

List::~List() {
    Node* temp;
    while(first!=nullptr) {
        temp = first;
        first=first->next;
        temp->next=nullptr;
        delete temp;
    }
    first=nullptr;
//delete first;
}
bool List::exists(int d) const {
    if(first==nullptr){
        return false;
    }

    Node* temp=first;
    do{
        if(temp->value==d){
            temp=nullptr;
            return true;
        }
        temp=temp->next;
    }while(temp!=nullptr);
    temp=nullptr;
	return false;
}
int List::size() const {
    int sizeNbr=0;
    Node* temp=first;
    while(temp!=nullptr){
        ++sizeNbr;
        temp=temp->next;
    }
    temp=nullptr;
	return sizeNbr;
}

bool List::empty() const {

    if(first==nullptr){
	    return true;
    }
    return false;
}

void List::insertFirst(int d) {
    Node* temp = new Node(d,first);
    first = temp;
    temp=nullptr;
}

void List::remove(int d, DeleteFlag df) {
     if(first==nullptr){
        return;
    }


    Node* temp=first->next;
    Node* prev=first;

    if(List::DeleteFlag::LESS==df){
        if(first->value<d){
            first=first->next;
            delete prev;
            temp=nullptr;
            return;           
        }
        do{
            if(temp->value<d){
                prev->next=temp->next;
                delete temp;
                prev=nullptr;
                return;
            }
            prev= temp;
            temp= temp->next; 
       
        }while(temp!=nullptr);    
    } else if(List::DeleteFlag::EQUAL==df){
         if(first->value==d){
            first=first->next;
            delete prev;
            temp=nullptr;
            return;           
        }
        do{
            if(temp->value==d){
                prev->next=temp->next;              
                delete temp;
                prev=nullptr;
                return;
            }
            prev= temp;
            temp= temp->next; 
       
        }while(temp!=nullptr);    

    } else if(List::DeleteFlag::GREATER==df){
         if(first->value>d){
            first=first->next;
            delete prev;
            temp=nullptr;
            return;           
        }
        do{
            if(temp->value>d){
                prev->next=temp->next;
                delete temp;
                prev=nullptr;
                return;
            }
            prev= temp;
            temp= temp->next;      
        }while(temp!=nullptr);    
    }
    prev=nullptr;
    temp=nullptr;
    return;
}

void List::print() const {
    Node* temp=first;
    std::cout<<std::endl;
    while(temp!=nullptr){
        std::cout<<temp->value<<std::endl;
        temp=temp->next;
    }
    temp=nullptr;
    return;
}

