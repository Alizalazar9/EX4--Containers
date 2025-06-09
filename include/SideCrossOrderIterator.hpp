//alizalazar9@gmail.com
// SideCrossOrderIterator: Iterates from smallest to largest in a crisscross pattern (min, max, next-min, next-max, ...)

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

    // Template iterator class for side-cross (zigzag) order
    template<typename T>
    class SideCrossOrderIterator {
    private:
        std::vector<T> ordered; // Stores elements in side-cross order
        size_t index;           // Current position in the ordered vector

    public:
        // Constructor receives the elements and initializes side-cross ordering
        SideCrossOrderIterator(const std::vector<T>& elements, bool is_begin) {
            std::vector<T> sorted = elements;                // Make a copy to sort
            std::sort(sorted.begin(), sorted.end());         // Sort the elements in ascending order

            // Create side-cross pattern: smallest, largest, next smallest, next largest...
            size_t left = 0;
            size_t right = sorted.size() - 1;
            while (left <= right) {
                if (left == right) {
                    ordered.push_back(sorted[left]);         // Add middle element (for odd-sized vectors)
                    break;
                }
                ordered.push_back(sorted[left++]);           // Add smallest
                ordered.push_back(sorted[right--]);          // Add largest
            }

            // Set iterator index to beginning or end
            index = is_begin ? 0 : ordered.size();
        }

        // Dereference operator returns the current element
        const T& operator*() const {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            return ordered[index];
        }

        // Prefix increment to advance to next element
        SideCrossOrderIterator& operator++() {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            ++index;
            return *this;
        }

        // Equality operator: true if both iterators point to same index
        bool operator==(const SideCrossOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality operator
        bool operator!=(const SideCrossOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
