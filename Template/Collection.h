#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Collection {
private:
    std::vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    bool removeAt(size_t index) {
        if (index >= items.size()) return false;
        items.erase(items.begin() + index);
        return true;
    }

    T& get(size_t index) {
        return items[index];
    }

    const T& get(size_t index) const {
        return items[index];
    }

    int find(const T& item) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i] == item) return static_cast<int>(i);
        }
        return -1;
    }

    template <typename Predicate>
    int findIf(Predicate pred) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (pred(items[i])) return static_cast<int>(i);
        }
        return -1;
    }

    size_t size() const {
        return items.size();
    }

    void clear() {
        items.clear();
    }

    template <typename PrintFunc>
    void print(std::ostream& os, PrintFunc printer) const {
        os << "Collection [" << items.size() << " items]:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            os << "[" << i << "] ";
            printer(items[i], os);
        }
    }
};

template <typename T, typename Comparator>
T findBest(const Collection<T>& coll, Comparator comp) {
    T best = coll.get(0); 
    for (size_t i = 1; i < coll.size(); ++i) {
        if (comp(coll.get(i), best)) {
            best = coll.get(i);
        }
    }
    return best;
}

// 9. Шаблонная функция: Подсчет элементов по критерию
template <typename T, typename Predicate>
int countIf(const Collection<T>& coll, Predicate pred) {
    int count = 0;
    for (size_t i = 0; i < coll.size(); ++i) {
        if (pred(coll.get(i))) {
            ++count;
        }
    }
    return count;
}

// 10. Шаблонная функция: Фильтрация (создает новую коллекцию)
template <typename T, typename Predicate>
Collection<T> filter(const Collection<T>& coll, Predicate pred) {
    Collection<T> result;
    for (size_t i = 0; i < coll.size(); ++i) {
        if (pred(coll.get(i))) {
            result.add(coll.get(i));
        }
    }
    return result;
}