#pragma once

#include <vector>
#include <list>

using namespace std;


class Hash {
private:
    vector<list<pair<int, int>>> table;
    unsigned int size;

public:
    Hash(unsigned int size) : table(size), size(size) {}

    void insert(const int& key, const int& value) {//добавление элемента
        unsigned int index = key;
        table[index].push_back(make_pair(key, value));//добавляем в index-ий элемент вектора в конец списка
    }

    bool find(const int& key, int& value) const {//ищем значение если нашли возвращаем тру
        unsigned int index = key;
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }
        return false;
    }
    void print() const {//выводим всю таблицу
        for (unsigned int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            for (auto& entry : table[i]) {
                cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            cout << endl;
        }
    }
    unsigned int countCollisions() const {//считаем количество коллизий
        unsigned int collisions = 0;
        for (const auto& bucket : table) {
            if (bucket.size() > 1) {
                collisions++;
            }
        }
        return collisions;
    }
    vector<pair<int, int>> longestCollisionChain() const {//ищем самую длинную коллизию
        unsigned int maxChainLength = 0;
        vector<pair<int, int>> longestChain;

        for (const auto& bucket : table) {
            if (bucket.size() > maxChainLength) {
                maxChainLength = bucket.size();
                longestChain = vector<pair<int, int>>(bucket.begin(), bucket.end());
            }
        }
        return longestChain;
    }
    double calculateLoadFactor() const {//считаем степень заполненности таблицы (количество не пустых классов/на общее количество классов)
        unsigned int itemsCount = 0;
        for (const auto& bucket : table) {
            if (bucket.size() > 0) {
                itemsCount++;
            }
        }
        return static_cast<double>(itemsCount) / size * 100;
    }
};
