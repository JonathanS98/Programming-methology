//Lab 3, DT079G
//Jonathan Shahi
//p_queue.h, 08/12/22
//Running some tests

#include <iostream>
#include "p_queue.h"
#include <string>
#include <ctime>
#include <utility>
#include <algorithm>
#include <vector>


struct Person {
    std::string name;
    int price;
    Person(int price, std::string name) : name(name), price(price) {}
};

struct Person_less {
    auto operator ()(const Person& lhs, const Person& rhs) {
        return lhs.price < rhs.price;
    }
};

int main() {
    srand(time(0));
    p_queue<Person, Person_less> buy;
    p_queue<Person, Person_less> sell;

    size_t lower_bound = 15;
    size_t upper_bound = 30;

    for (int i = 0; i < 3; i++) {
        std::string person_name;
        if (i % 3 == 0) {
            person_name = "Erik Pendel";
        }
        else if (i % 3 == 1) {
            person_name = "Jarl Wallenburg";
        }
        else {
            person_name = "Joakim Von Anka";
        }
        for (int j = 0; j < 7; j++) {
            sell.push(Person(rand() % (upper_bound - lower_bound) + lower_bound, person_name));
            buy.push(Person(rand() % (upper_bound - lower_bound) + lower_bound, person_name));
        }
    }

    while (!buy.empty()) {
        auto buyer = buy.pop();
        auto seller = sell.pop();
        if (buyer.name != seller.name && buyer.price >= seller.price) {
            std::cout << "Buyer: " << buyer.name << ", " << buyer.price << " bought shares from " << seller.name << ", "
                << seller.price << "\n";
        }


    }

    return 0;
}
