#include <iostream>
#include <vector>
#include <cassert>
#include <iterator>
#include <string>
#include <numeric>
#include <fstream>


using element_t = std::vector<uint8_t>;
using element_t_it = element_t::const_iterator;

struct group {
    uint8_t size;
    uint8_t value;
};

// lifetime of return value is the same as the lifetime of the input collection
template<typename Iter>
auto split_groups(const Iter begin, const Iter end) -> std::vector<group> {
    assert(begin != end);
    std::vector<group> out;
    Iter first = begin;
    Iter second = first;
    do {
        while (*second == *first) {
            second++;
            if (second == end) { // break after increment so second can become end
                break;
            }
        }
        //out.emplace_back(static_cast<uint8_t>(second - first), *first);
        out.push_back({static_cast<uint8_t>(second - first), *first});
        first = second;
    } while (second != end);

    return out;
}


element_t next(element_t &current) {
    const auto groups = split_groups(current.begin(), current.end());
    element_t next(groups.size() * 2);


    auto iter = next.begin();
    for (const auto group : groups) {
        *iter = group.size;
        iter++;
        *iter = group.value;
        iter++;
    }

    return next;
}

int count(element_t& element, const int num) {
    int count = 0;
    for (auto i : element) {
        if (i == num) {
            count++;
        }
    }
    return count;
}

std::ostream& operator<<(std::ostream& out, const element_t& element) {
    for (auto i : element) {
        out << unsigned(i);
    }
    return out;
}

int main() {
    const element_t start = {1};
    element_t iter = start;

    std::ofstream fout;
    fout.open("out.txt");
    for (uint64_t i = 0; i < 30 - 1; i++) {
        fout << iter << '\n';
        iter = next(iter);
    }
    fout << std::flush;
    std::cout << count(iter, 1) << ',' << count(iter, 2) << ',' << count(iter, 3) << '\n';
    return 0;
}