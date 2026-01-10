#include <iostream>
#include <cassert>
#include "types.hpp"
#include "BitUtils.hpp"

using namespace Optimized;

void test_set_bit() {
    u32 val = 0;
    set_bit(val, 0);
    assert(val == 1);
    set_bit(val, 1);
    assert(val == 3);
    std::cout << "test_set_bit passed." << std::endl;
}

void test_clear_bit() {
    u32 val = 3;
    clear_bit(val, 0);
    assert(val == 2);
    clear_bit(val, 1);
    assert(val == 0);
    std::cout << "test_clear_bit passed." << std::endl;
}

void test_toggle_bit() {
    u32 val = 0;
    toggle_bit(val, 2);
    assert(val == 4);
    toggle_bit(val, 2);
    assert(val == 0);
    std::cout << "test_toggle_bit passed." << std::endl;
}

void test_popcount() {
    u32 val = 0;
    assert(popcount(val) == 0);
    val = 0xFFFFFFFF;
    assert(popcount(val) == 32);
    val = 0x00000003;
    assert(popcount(val) == 2);
    std::cout << "test_popcount passed." << std::endl;
}

void test_is_power_of_two() {
    assert(is_power_of_two(1));
    assert(is_power_of_two(2));
    assert(is_power_of_two(1024));
    assert(!is_power_of_two(0));
    assert(!is_power_of_two(3));
    std::cout << "test_is_power_of_two passed." << std::endl;
}

int main() {
    test_set_bit();
    test_clear_bit();
    test_toggle_bit();
    test_popcount();
    test_is_power_of_two();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
