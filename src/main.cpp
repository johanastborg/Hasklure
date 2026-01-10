#include <iostream>
#include "types.hpp"
#include "BitUtils.hpp"

using namespace Optimized;

int main() {
    std::cout << "Optimized C++98 Project Structure" << std::endl;

    u32 data = 0;

    std::cout << "Initial data: " << data << std::endl;

    set_bit(data, 0);
    set_bit(data, 5);
    set_bit(data, 10);

    std::cout << "After setting bits 0, 5, 10: " << data << std::endl;
    std::cout << "Bit 5 is set: " << (check_bit(data, 5) ? "Yes" : "No") << std::endl;
    std::cout << "Bit 6 is set: " << (check_bit(data, 6) ? "Yes" : "No") << std::endl;

    std::cout << "Population count: " << popcount(data) << std::endl;

    u32 swapped = bswap(data);
    std::cout << "Byte swapped: " << swapped << std::endl;

    return 0;
}
