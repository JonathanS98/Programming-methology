//Lab 3, DT079G
//Jonathan Shahi
//p_queue.h, 08/12/22
//Implementation of class Email

#ifndef P_QUEUE
#define P_QUEUE

#include <vector>
#include <algorithm>
#include <string>

template<typename T, typename Comp = std::less<>>
class p_queue {
public:
    /// <summary>
    /// Gives the uncoming value to value. then removes it from the vector.
    /// </summary>
    /// <returns>value that was given from list.front()</returns>
    T pop() {
        T value = list.front();
        list.erase(list.begin());
        return value;
    }
    /// <summary>
    /// pushes the values into the vector in priority order
    /// </summary>
    /// <param name="e">takes the push_back value</param>
    void push(const T e) {
        
        // implemtation of a lambda expression. [&] means that everything that's inside and found outside is captured by reference.
        auto in_point = std::find_if(list.begin(), list.end(), [&](const T& input) {return comp(input, e); });
        list.insert(in_point, e);
    }
    size_t size() const {
        return list.size();
    }
    bool empty() const {
        return list.empty();
    }
private:
    std::vector<T> list;
    Comp comp;
};

#endif