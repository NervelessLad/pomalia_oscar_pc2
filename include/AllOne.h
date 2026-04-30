#ifndef ALLONE_H
#define ALLONE_H

#include <string>
#include <unordered_set>
#include <unordered_map>

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

    // Helpers para no marearnos con los punteros de la lista doble
    void addBucketAfter(Bucket* newBucket, Bucket* prevBucket);
    void removeBucket(Bucket* bucket);

public:
    AllOne();
    ~AllOne();

    void inc(std::string key);
    void dec(std::string key);
    std::string getMaxKey();
    std::string getMinKey();
    void printBuckets();
};

#endif