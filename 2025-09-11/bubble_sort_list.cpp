#include <iostream>
#include <list>
#include <vector>

void bubbleSortList(std::list<int>& lst) {
    if (lst.size() <= 1) return;
    
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        
        auto current = lst.begin();
        auto next = std::next(current);
        
        while (next != lst.end()) {
            if (*current > *next) {
                std::swap(*current, *next);
                swapped = true;
            }
            current = next;
            ++next;
        }
    }
}

void printList(const std::list<int>& lst) {
    bool first = true;
    for (const auto& val : lst) {
        if (!first) std::cout << " ";
        std::cout << val;
        first = false;
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> myList = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "정렬 전 (list): ";
    printList(myList);
    
    bubbleSortList(myList);
    
    std::cout << "정렬 후 (list): ";
    printList(myList);
    
    std::list<int> sortedList = {1, 2, 3, 4, 5};
    std::cout << "\n이미 정렬된 리스트 테스트:" << std::endl;
    std::cout << "정렬 전: ";
    printList(sortedList);
    
    bubbleSortList(sortedList);
    
    std::cout << "정렬 후: ";
    printList(sortedList);
    
    return 0;
}