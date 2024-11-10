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

    void insert(const int& key, const int& value) {//���������� ��������
        unsigned int index = key;
        table[index].push_back(make_pair(key, value));//��������� � index-�� ������� ������� � ����� ������
    }

    bool find(const int& key, int& value) const {//���� �������� ���� ����� ���������� ���
        unsigned int index = key;
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }
        return false;
    }
    void print() const {//������� ��� �������
        for (unsigned int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            for (auto& entry : table[i]) {
                cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            cout << endl;
        }
    }
    unsigned int countCollisions() const {//������� ���������� ��������
        unsigned int collisions = 0;
        for (const auto& bucket : table) {
            if (bucket.size() > 1) {
                collisions++;
            }
        }
        return collisions;
    }
    vector<pair<int, int>> longestCollisionChain() const {//���� ����� ������� ��������
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
    double calculateLoadFactor() const {//������� ������� ������������� ������� (���������� �� ������ �������/�� ����� ���������� �������)
        unsigned int itemsCount = 0;
        for (const auto& bucket : table) {
            if (bucket.size() > 0) {
                itemsCount++;
            }
        }
        return static_cast<double>(itemsCount) / size * 100;
    }
};