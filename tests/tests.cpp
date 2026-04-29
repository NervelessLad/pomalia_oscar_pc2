#include <iostream>
#include <cassert>
#include "../include/AllOne.h"

void runTests() {
    std::cout << "--- Iniciando pruebas de AllOne ---" << std::endl;
    AllOne* obj = new AllOne();

    // Prueba 1: Insercion basica y comprobacion de extremos
    obj->inc("hello");
    obj->inc("hello");
    assert(obj->getMaxKey() == "hello");
    assert(obj->getMinKey() == "hello");
    std::cout << "[OK] Prueba 1: Insercion basica superada." << std::endl;

    // Prueba 2: Multiples llaves con diferentes frecuencias
    obj->inc("world");
    assert(obj->getMaxKey() == "hello"); // 'hello' tiene frec 2
    assert(obj->getMinKey() == "world"); // 'world' tiene frec 1
    std::cout << "[OK] Prueba 2: Maximos y minimos en O(1) correctos." << std::endl;

    // Prueba 3: Decremento y reajuste de la lista doble
    obj->dec("hello");
    obj->dec("hello"); // 'hello' debe ser eliminado por completo
    assert(obj->getMaxKey() == "world");
    assert(obj->getMinKey() == "world");
    std::cout << "[OK] Prueba 3: Decremento y eliminacion de buckets correctos." << std::endl;

    // Prueba 4: Estructura vacia
    obj->dec("world");
    assert(obj->getMaxKey() == "");
    assert(obj->getMinKey() == "");
    std::cout << "[OK] Prueba 4: Manejo seguro de lista vacia (centinelas)." << std::endl;

    delete obj;
    std::cout << "--- Todas las pruebas pasaron exitosamente ---" << std::endl;
}

int main() {
    runTests();
    return 0;
}