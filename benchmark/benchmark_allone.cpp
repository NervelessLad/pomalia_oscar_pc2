#include <iostream>
#include <chrono>
#include <string>
#include "../include/AllOne.h"

int main() {
    std::cout << "=== Benchmark de AllOne O(1) ===\n";
    AllOne obj;
    const int N = 1000000; // 1 millon de operaciones

    std::cout << "[*] Ejecutando " << N << " incrementos...\n";
    
    // Medir tiempo de inserciones
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        // Insertamos 1000 llaves distintas repetidas muchas veces
        obj.inc("llave_" + std::to_string(i % 1000)); 
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_inc = end - start;
    
    std::cout << " -> Tiempo de insercion (" << N << " ops): " << diff_inc.count() << " segundos.\n\n";
    
    std::cout << "[*] Consultando Max y Min en O(1)...\n";
    // Medir tiempo de consultas extremas
    start = std::chrono::high_resolution_clock::now();
    std::string max_k = obj.getMaxKey();
    std::string min_k = obj.getMinKey();
    end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff_queries = end - start;
    
    std::cout << " -> Max Key: " << max_k << "\n";
    std::cout << " -> Min Key: " << min_k << "\n";
    std::cout << " -> Tiempo de consultas: " << std::fixed << diff_queries.count() << " segundos.\n";
    std::cout << "    (Deberia ser practicamente 0.000000 por el acceso directo a los centinelas)\n";

    return 0;
}