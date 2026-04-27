#include "AllOne.h"

AllOne::AllOne() {
    head = new Bucket(0);
    tail = new Bucket(0);
    head->next = tail;
    tail->prev = head;
}

AllOne::~AllOne() {
    Bucket* curr = head;
    while (curr != nullptr) {
        Bucket* nextNode = curr->next;
        delete curr;
        curr = nextNode; // liberamos memoria para evitar leaks
    }
}

void AllOne::addBucketAfter(Bucket* newBucket, Bucket* prevBucket) {
    newBucket->prev = prevBucket;
    newBucket->next = prevBucket->next;
    prevBucket->next->prev = newBucket;
    prevBucket->next = newBucket;
}

void AllOne::removeBucket(Bucket* bucket) {
    bucket->prev->next = bucket->next;
    bucket->next->prev = bucket->prev;
    delete bucket; 
}

void AllOne::inc(std::string key) {
    if (map.find(key) == map.end()) {
        // Si no existe, va al primer bucket (frecuencia 1)
        if (head->next->freq != 1) {
            addBucketAfter(new Bucket(1), head);
        }
        head->next->keys.insert(key);
        map[key] = head->next;
    } else {
        // Ya existe, hay que subirle la frecuencia y moverlo a la derecha
        Bucket* curr = map[key];
        int nFreq = curr->freq + 1;
        
        if (curr->next->freq != nFreq) {
            addBucketAfter(new Bucket(nFreq), curr);
        }
        
        curr->next->keys.insert(key);
        map[key] = curr->next;
        
        // Borramos del anterior
        curr->keys.erase(key);
        if (curr->keys.empty()) {
            removeBucket(curr); // Mantenemos la invariante (cero buckets vacíos)
        }
    }
}

void AllOne::dec(std::string key) {
    if (map.find(key) == map.end()) return; // Por si acaso mandan algo que no existe

    Bucket* curr = map[key];
    int pFreq = curr->freq - 1;

    curr->keys.erase(key);

    if (pFreq == 0) {
        map.erase(key); // Adios llave
    } else {
        // Retrocede al bucket de la izquierda
        if (curr->prev->freq != pFreq) {
            addBucketAfter(new Bucket(pFreq), curr->prev);
        }
        curr->prev->keys.insert(key);
        map[key] = curr->prev;
    }

    if (curr->keys.empty()) {
        removeBucket(curr);
    }
}

// TODO para mañana: implementar las busquedas de extremos
std::string AllOne::getMaxKey() { return ""; }
std::string AllOne::getMinKey() { return ""; }