/**
 * @file array.hpp
 * @brief This file contains implementation of Array class
 * @author sysdev-club
 */

#pragma once

#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <type_traits>

namespace ds {

/**
 * @brief Custom implementation of a fixed-size array container.
 *
 * @tparam T type of the elements.
 * @tparam N number of elements in the array.
 */
template<typename T, std::size_t N>
struct Array {
    /// Alias for the type of elements stored in the array.
    using value_type = T;

    /// Alias for a pointer to an array element.
    using pointer = value_type*;

    /// Alias for a pointer to a constant array element.
    using const_pointer = const value_type*;

    /// Alias for a reference to an array element.
    using reference = value_type&;

    /// Alias for a reference to a constant array element.
    using const_reference = const value_type&;

    /// Alias for the size type.
    using size_type = std::size_t;

    /// Alias for the difference type between iterators.
    using difference_type = std::ptrdiff_t;

    /// Alias for the iterator.
    using iterator = value_type*;

    /// Alias for the constant iterator.
    using const_iterator = const value_type*;

    /// Alias for the reverse iterator.
    using reverse_iterator = std::reverse_iterator<iterator>;

    /// Alias for the constant reverse iterator.
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // no explicit construct/copy/destroy for aggregate type
    constexpr void fill(const value_type& u);
    constexpr void swap(Array&) noexcept(std::is_nothrow_swappable<T>());

    // iterators
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;

    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;

    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;

    // capacity
    constexpr bool empty() const noexcept { return N == 0; }
    constexpr size_type size() const noexcept { return N; }
    constexpr size_type max_size() const noexcept { return N; }

    // element access
    constexpr reference operator[](size_type n) {}
    constexpr const_reference operator[](size_type n) const {
        if (n >= N) {
            throw std::out_of_range("Argument \"n\" outside of \"Array\" range");
        }
        return m_data[n];
    }
    constexpr reference at(size_type n) {
        if (n >= N) {
            throw std::out_of_range("Argument \"n\" outside of \"Array\" range");
        }
        return m_data[n];
    }
    constexpr const_reference at(size_type n) const;
    constexpr reference front();
    constexpr const_reference front() const;
    constexpr reference back();
    constexpr const_reference back() const;

    constexpr value_type* data() noexcept;
    constexpr const value_type* data() const noexcept;

    /// The underlying raw array.
    value_type m_data[N == 0 ? 1 : N]{};
};
} // namespace ds
