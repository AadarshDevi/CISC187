//
// Created by CryosArtic on 9/27/2026.
//

#include <iostream>
#include <string>
#include <climits>
#include <vector>


struct Record {
    int key;
    std::string value;
};

class HashTable {
private:
    const int DEFAULT_SIZE = 11;
    int table_size = DEFAULT_SIZE;
    std::vector<Record> hash_table;
    float DEFAULT_GROWING_THRESHOLD = 0.75;
    float growing_threshold = DEFAULT_GROWING_THRESHOLD;
    int element_count = 0;

public:
    HashTable(int table_size, float growing_threshold) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative
        if (growing_threshold > 0) this->growing_threshold = growing_threshold;
        // makes sure factor is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = std::vector<Record>(this->table_size);
    }

    HashTable(int table_size) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = std::vector<Record>(this->table_size);
    }

    // Deconstructor
    ~HashTable() {
        // delete the vector created
        delete &hash_table;
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
        // const int index = hashFunction(record.key); // get table_index
        // hash_table->at(index).push_back(record); // place record in the vector with the table_index
        return true;
    }

    Record *get(int key) {
        // const int index = hashFunction(key);
        // std::vector<Record> &record_vector = hash_table->at(index);
        // for (int i = 0; i < record_vector.size(); i++) {
        //     if (record_vector[i].key == key) {
        //         return &record_vector[i];
        //     }
        // }
        return nullptr;
    }

    bool remove(int key) {
        // const int index = hashFunction(key);
        // std::vector<Record> &record_vector = hash_table->at(index);
        // for (int i = 0; i < record_vector.size(); i++) {
        //     if (record_vector[i].key == key) {
        //         record_vector.erase(record_vector.begin() + i);
        //         return true;
        //     }
        // }
        return false;
    }

    bool remove(Record record) {
        // const int index = hashFunction(record.key);
        // std::vector<Record> &record_vector = hash_table->at(index);
        // for (int i = 0; i < record_vector.size(); i++) {
        //     if (record_vector[i].key == record.key) {
        //         record_vector.erase(record_vector.begin() + i);
        //         return true;
        //     }
        // }
        return false;
    }

    void printData() {
        std::cout << "\nPrinting Data:\n";
        if (hash_table.empty()) return;
        for (int i = 0; i < table_size; i++) {
            if (&hash_table.at(i) == nullptr) {
                continue;
            }
            std::cout << "i = " << i << ": ";
            std::cout << hash_table.at(i).value << "\t";
            std::cout << "\n";
        }
    }
};

int main() {
    HashTable hash_table(10);

    Record record1{.key = 555223, .value = "Student_C"};
    hash_table.add(record1);

    Record record2{.key = 555980, .value = "Student_G"};
    hash_table.add(record2);

    Record record3{.key = 555000, .value = "Student_A"};
    hash_table.add(record3);

    Record record4{.key = 555890, .value = "Student_L"};
    hash_table.add(record4);

    hash_table.printData();

    hash_table.remove(555890);

    hash_table.printData();

    hash_table.remove(record1);

    hash_table.printData();

    Record *record5 = hash_table.get(555890);
    std::cout << "\nPrinting Record: " << record5 << "\n";

    Record *record6 = hash_table.get(555980);
    std::cout << "\nPrinting Record: " << record6->value << "\n";

    std::cout << "\n";
    return 0;
}
