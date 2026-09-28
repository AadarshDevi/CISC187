//
// Created by CryosArtic on 9/27/2026.
//

#include <iostream>
#include <vector>


struct Record {
    int key;
    std::string value;
};

class HashTable {
private:
    const int DEFAULT_SIZE = 11;
    int table_size = DEFAULT_SIZE;
    std::vector<std::vector<Record> > *hash_table;

public:
    HashTable(int table_size) : table_size(table_size) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = new std::vector<std::vector<Record> >(this->table_size);

        for (int i = 0; i < table_size; i++) {
            hash_table[i].resize(DEFAULT_SIZE);
        }
    }

    // Deconstructor
    ~HashTable() {
        // delete the vector created
        delete hash_table;
    }

    int hashFunction(int key) {
        int digit_sum = 0;
        for (int i = 0; i < INT_MAX; i++) {
            int digit = key % 10; // get last digit
            digit_sum += digit; // add to sum
            key = key / 10; // remove the last digit which is now 0
            if (key == 0) break; // escapes if key = 0
        }
        return digit_sum % table_size; // index = digital_sum % table_size
    }

    bool add(Record record) {
        // if object doesn't exist
        if (&record == nullptr) return false;

        const int index = hashFunction(record.key); // get table_index
        hash_table->at(index).push_back(record); // place record in the vector with the table_index
        return true;
    }

    Record *get(int key) {
        const int index = hashFunction(key);
        std::vector<Record> record_vector = hash_table->at(index);
        for (Record record: record_vector) {
            if (key == record.key) {
                return &record;
            }
        }
        return nullptr;
    }

    bool remove(int key) {
        const int index = hashFunction(key);
        std::vector<Record> record_vector = hash_table->at(index);
        for (int i = 0; i < record_vector.size(); i++) {
            if (record_vector[i].key == key) {
                record_vector.erase(record_vector.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool remove(Record record) {
        const int index = hashFunction(record.key);
        std::vector<Record> record_vector = hash_table->at(index);
        for (int i = 0; i < record_vector.size(); i++) {
            if (record_vector[i].key == record.key) {
                record_vector.erase(record_vector.begin() + i);
                return true;
            }
        }
        return false;
    }

    int getSize() {
        return table_size;
    }
};

int main() {
    HashTable hash_table(10);

    std::cout << "Hash: " << hash_table.hashFunction(555223) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555980) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555000) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555890) << "\n";

    std::cout << "\n";
    return 0;
}
