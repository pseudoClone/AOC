#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
        std::vector<int> List1 {};
        std::vector<int> List2 {};

        std::string number{};

        std::ifstream reader1("list1");
        while (std::getline(reader1, number)) {
                List1.push_back(std::stoi(number));
        }

        std::ifstream reader2("list2");
        while (std::getline(reader2, number)) {
                List2.push_back(std::stoi(number));
        }

        std::stable_sort(List1.begin(), List1.end());
        std::stable_sort(List2.begin(), List2.end());

        int sumOfDiff {};

        auto it1 = List1.begin();
        auto it2 = List2.begin();

        for (; it1 != List1.end() && it2 != List2.end(); it1++, it2++) {
                sumOfDiff += std::abs(*it1 - *it2);
        }
        std::cout<< sumOfDiff << std::endl;

        return 0;
}
