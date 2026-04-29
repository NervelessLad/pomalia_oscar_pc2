#include <iostream>
#include "../include/AllOne.h"

int main() {
    std::cout << "=== Demo Visual de la Estructura AllOne ===\n\n";
    AllOne obj;

    std::cout << "[+] Incrementando 'manzana' 3 veces...\n";
    obj.inc("manzana");
    obj.inc("manzana");
    obj.inc("manzana");

    std::cout << "[+] Incrementando 'platano' 1 vez...\n";
    obj.inc("platano");

    std::cout << " -> Max Key actual: " << obj.getMaxKey() << " (deberia ser manzana)\n";
    std::cout << " -> Min Key actual: " << obj.getMinKey() << " (deberia ser platano)\n\n";

    std::cout << "[-] Decrementando 'manzana' 3 veces...\n";
    obj.dec("manzana");
    obj.dec("manzana");
    obj.dec("manzana");

    std::cout << " -> Max Key ahora: " << obj.getMaxKey() << " (deberia ser platano)\n";
    std::cout << " -> Min Key ahora: " << obj.getMinKey() << " (deberia ser platano)\n\n";

    std::cout << "=== Fin de la Demo ===\n";
    return 0;
}