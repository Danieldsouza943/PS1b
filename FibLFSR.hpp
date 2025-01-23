// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <string>

namespace PhotoMagic {
class FibLFSR {
 public:
        // constructor to create LFSR with the given initial seed and taps.
        explicit FibLFSR(std::string seed);

        // simulate one step and return the new bit as 1 or 0.
        int step();

        // simulate k steps and return k-bit integer.
        int generate(int k);

        std::string get_register() const;

 private:
        std::string register_;
        // You can add any other fields you need for the taps and internal state.
};

    // Overloading the << stream insertion operator.
    std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);
}  // namespace PhotoMagic
