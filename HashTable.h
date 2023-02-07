#pragma once
// This is the header file HashTable.h.  This is the interface
// for the class HashTable, which is a class for a hash table
// of strings.
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "LinkedList.cpp"
#include <string>
using LinkedListNS::Node;
using std::string;
namespace HashTableNS
{
    const int SIZE = 10;
    class HashTable
    {
    public:
        HashTable(); // Initialize empty hash table
        virtual ~HashTable();  // Destructor destroys hash table
        // Returns true if target is in the hash table,
        // false otherwise
        bool containsString(string target) const;
        // Adds a new string to the hash table
        void put(string s);
    private:
        Node<string>* hashArray[SIZE];
        static int computeHash(string s);   // Compute hash value for string
    }; // HashTable
} // HashTableNS
#endif // HASHTABLE_H