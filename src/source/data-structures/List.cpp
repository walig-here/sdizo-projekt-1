#include <iostream>
#include "data-structures/List.h"

using namespace std;

List::List(){

    head = nullptr;
    tail = nullptr;
    print_backwards = false;

}

List::List(List* &source){

    // Ustalamy wartości bazowe ogona i głowy
    List();

    // Kopiujemy kolejność wyświetlania
    this->print_backwards = source->print_backwards;

    // Wykonujemy kopię wszystkich elementów
    ListElement* source_element = source->head;
    while(source_element != nullptr){
        this->push_back(source_element->value);
        source_element = source_element->next;
    }

}

List::~List(){

    // Dla pustej listy nic nie zwalniamy
    if(head == nullptr) return;

    // Zwalniamy kolejne elementy zaczynając od głowy
    ListElement* current_element;
    while(head != nullptr){
        current_element = head;
        head = current_element->next;
        delete current_element;
    }

    // Czyścimy wskaźnik ogona
    tail = nullptr;

}

ListElement* List::front(){

    return head;

}

ListElement* List::back(){

    return tail;

}

ListElement* List::find(const int value){

    // Sprawdzamy, czy nie jest to wartość zapisana w ogonie
    if(tail != nullptr && tail->value == value) return tail;

    // Przeszukujemy listę w poszukiwaniu elementu o wskazanej wartości
    // W wypadku, gdy taka w liście nie wystąpi zwórcony zostanie nullptr
    ListElement* found_element = head;
    while (found_element != nullptr && found_element->value != value)
        found_element = found_element->next;
    return found_element;

}

void List::add(const int new_element_value, const unsigned int new_element_index){

    // Jeżeli dodajemy na początek to lepiej jest użyć metody push_front
    if(new_element_index == 0) return push_front(new_element_value);


    // Szukamy elementów, które będą sąsiadami nowego elementu, aby "umieścić" między nimi nowy element
    ListElement* prev_element = nullptr;  // sąsiad "z lewej"
    ListElement* next_element = nullptr;  // sąsiad "z prawej"
    for(int i = 0; prev_element != nullptr; i++){

        prev_element = prev_element->next;
        if(i != new_element_index-1) continue;
        next_element = prev_element->next;        
        break;

    }

    // Jeżeli sąsiad z prawej jest null to de facto dodajemy na koniec kolejki
    // Tyczy się to także sytuacji gdy wprowadzono indeks większy od indeksu ogona
    if(next_element == nullptr) return push_back(new_element_value);

    // Umieszamy nowy element między znalezionymi sąsiadami
    ListElement* new_element = new ListElement(prev_element, new_element_value, next_element);
    prev_element->next = new_element;
    next_element->prev = new_element;

}

void List::push_front(const int new_element_value){

    ListElement* new_element = new ListElement(nullptr, new_element_value, head);
    if(head != nullptr) head->prev = new_element;
    head = new_element;

    // Sprawdzam, czy dodany element nie jest jednocześnie ogonem
    if(head->next == nullptr) tail = head;

}

void List::push_back(const int new_element_value){

    ListElement* new_element = new ListElement(tail, new_element_value, nullptr);
    if(tail != nullptr) tail->next = new_element;
    tail = new_element;

    // Sprawdzam, czy dodany element nie jest jednocześnie głową
    if(tail->prev == nullptr) head = tail;

}

void List::print(){

    printf("Zawartosc listy ");

    ListElement* current_element = nullptr;
    if(print_backwards) {
        current_element = tail;
        printf("(od tylu): ");
    }
    else{
        current_element = head;
        printf("(od przodu): ");
    }

    if(current_element == nullptr){
        printf("pusta\n");
        return;
    }

    while (current_element != nullptr){

        printf("%d", current_element->value);
        if(current_element != head || current_element != tail) printf(" ");   
        
        if(print_backwards) current_element = current_element->prev;
        else current_element = current_element->next;
    }
    printf("\n");

    printf("Glowa: %d\n", head->value);
    printf("Ogon: %d\n", tail->value);
}

void List::swap(){
    print_backwards = !print_backwards;
}