#ifndef ALLONE_H
#define ALLONE_H

#include <string>
#include <unordered_set>
#include <unordered_map>

// Representación de nuestro nodo para la lista doblemente enlazada
struct Bucket {
    int freq;
    std::unordered_set<std::string> keys;
    Bucket* prev;
    Bucket* next;

    Bucket(int f) : freq(f), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Bucket* head; 
    Bucket* tail; 
    std::unordered_map<std::string, Bucket*> map;

public:
    AllOne();
    ~AllOne();

    void inc(std::string key);
    void dec(std::string key);
    std::string getMaxKey();
    std::string getMinKey();
};

#endif