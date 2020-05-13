#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

template <typename Array>
struct array_iterator {
  Array& a;
  size_t i;

  array_iterator(Array& a, size_t i) : a(a), i(i) {}

  array_iterator& operator++() {
    ++i;
    return *this;
  }

  array_iterator& operator++(int) {
    array_iterator copy = *this;
    ++*this;
    return copy;
  }

  array_iterator& operator--() {
    --i;
    return *this;
  }

  array_iterator& operator--(int) {
    array_iterator copy = *this;
    --*this;
    return copy;
  }

  array_iterator& operator+=(size_t n) {
    i += n;
    return *this;
  }

  array_iterator operator+(size_t n) const {
    auto copy = *this;
    copy += n;
    return copy;
  }

  array_iterator& operator-=(size_t n) {
    i -= n;
    return *this;
  }

  array_iterator operator-(size_t n) const {
    auto copy = *this;
    copy -= n;
    return copy;
  }

  bool operator==(array_iterator const& right) const { return i == right.i; }
  bool operator!=(array_iterator const& right) const { return i != right.i; }
  bool operator<(array_iterator const& right) const { return i < right.i; }
  bool operator<=(array_iterator const& right) const { return i <= right.i; }
  bool operator>(array_iterator const& right) const { return i > right.i; }
  bool operator>=(array_iterator const& right) const { return i >= right.i; }

  typename Array::reference operator*() { return a[i]; };

  typename Array::reference operator[](size_t n) const { return *(*this + n); }
};

template <typename T, size_t N>
struct array {
  using value_type = T;
  using reference = T&;
  using const_reference = T const&;
  using size_type = size_t;
  using iterator = array_iterator<array>;

  value_type storage[N];

  reference operator[](size_type i) { return storage[i]; }

  reference at(size_t n) {
    if (n >= size()) throw out_of_range("Error: Out of Range");
    return storage[n];
  }

  const_reference operator[](size_type i) const { return storage[i]; }

  size_type size() const { return N; }

  reference front() { return storage[0]; }
  const_reference front() const { return storage[0]; }

  reference back() { return storage[N - 1]; }
  const_reference back() const { return storage[N - 1]; }

  iterator begin() { return iterator(*this, 0); }

  iterator end() { return iterator(*this, N); }

  void fill(value_type const& u) {
    for (size_t i = 0; i < N; ++i) {
      storage[i] = u;
    }
  }
};

template <typename Container>
void print(Container const& c) {
  for (size_t i = 0; i != c.size(); ++i) {
    cout << c[i];
  }
}

int main() {
  array<int, 5> a = {1, 2, 3, 4, 5};

  try {
    a.at(1000);
  } catch (out_of_range& e) {
    cout << e.what() << endl;
  }
}
