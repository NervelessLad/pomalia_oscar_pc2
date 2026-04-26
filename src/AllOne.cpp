#include "AllOne.h"

// Inicialización básica (la lógica compleja la haremos en el Día 2)
AllOne::AllOne() {
    head = new Bucket(0);
    tail = new Bucket(0);
    head->next = tail;
    tail->prev = head;
}

AllOne::~AllOne() {
    // Pendiente: limpiar memoria
}

void AllOne::inc(std::string key) { }
void AllOne::dec(std::string key) { }
std::string AllOne::getMaxKey() { return ""; }
std::string AllOne::getMinKey() { return ""; }