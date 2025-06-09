//alizalazar9@gmail.com
// MyContainer class: stores elements and allows iteration in multiple custom orders

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Custom iterator headers
#include "AscendingOrderIterator.hpp"
#include "DescendingOrderIterator.hpp"
#include "SideCrossOrderIterator.hpp"
#include "ReverseOrderIterator.hpp"
#include "OrderIterator.hpp"
#include "MiddleOutOrderIterator.hpp"

namespace mycontainers {

    // Template class for a container with multiple custom iterator views
    template<typename T>
    class MyContainer {
    private:
        std::vector<T> elements; // Stores the actual container data

    public:
        // Adds a new element to the container
        void add(const T& value) {
            elements.push_back(value);
        }

        // Removes all occurrences of the given value
        void remove(const T& value) {
            auto old_size = elements.size();
            // std::remove shifts matching elements to the end, then erase removes them
            elements.erase(std::remove(elements.begin(), elements.end(), value), elements.end());
            if (elements.size() == old_size) {
                throw std::runtime_error("Element not found in container.");
            }
        }

        // Returns the number of elements in the container
        size_t size() const {
            return elements.size();
        }

        // Gives access to raw vector of elements (for iterator use)
        const std::vector<T>& get_elements() const {
            return elements;
        }

        // Overload for printing the container content using std::ostream
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
            os << "[";
            for (size_t i = 0; i < container.elements.size(); ++i) {
                os << container.elements[i];
                if (i != container.elements.size() - 1) os << ", ";
            }
            os << "]";
            return os;
        }

        //Iterator Factory Methods

        // Ascending Order (sorted smallest to largest)
        AscendingOrderIterator<T> begin_ascending_order() const {
            return AscendingOrderIterator<T>(elements, true);
        }
        AscendingOrderIterator<T> end_ascending_order() const {
            return AscendingOrderIterator<T>(elements, false);
        }

        // Descending Order (sorted largest to smallest)
        DescendingOrderIterator<T> begin_descending_order() const {
            return DescendingOrderIterator<T>(elements, true);
        }
        DescendingOrderIterator<T> end_descending_order() const {
            return DescendingOrderIterator<T>(elements, false);
        }

        // Side Cross Order (small, large, next small, next large...)
        SideCrossOrderIterator<T> begin_side_cross_order() const {
            return SideCrossOrderIterator<T>(elements, true);
        }
        SideCrossOrderIterator<T> end_side_cross_order() const {
            return SideCrossOrderIterator<T>(elements, false);
        }

        // Reverse Order (last added to first added)
        ReverseOrderIterator<T> begin_reverse_order() const {
            return ReverseOrderIterator<T>(elements, true);
        }
        ReverseOrderIterator<T> end_reverse_order() const {
            return ReverseOrderIterator<T>(elements, false);
        }

        // Insertion Order (as elements were added)
        OrderIterator<T> begin_order() const {
            return OrderIterator<T>(elements, true);
        }
        OrderIterator<T> end_order() const {
            return OrderIterator<T>(elements, false);
        }

        // Middle-Out Order (middle element, then outward alternately)
        MiddleOutOrderIterator<T> begin_middle_out_order() const {
            return MiddleOutOrderIterator<T>(elements, true);
        }
        MiddleOutOrderIterator<T> end_middle_out_order() const {
            return MiddleOutOrderIterator<T>(elements, false);
        }
    };

} // namespace mycontainers
