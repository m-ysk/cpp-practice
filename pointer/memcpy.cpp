#include <stdio.h>

#include <cstddef>
#include <iostream>
using namespace std;

void* memcpy(void* dest, void const* src, size_t n) {
  auto d = static_cast<byte*>(dest);
  auto s = static_cast<byte const*>(src);

  auto last = s + n;

  while (s != last) {
    *d = *s;
    ++d;
    ++s;
  }

  return dest;
}

template <typename To, typename From>
To bit_cast(From const& from) {
  To to;
  memcpy(&to, &from, sizeof(To));
  return to;
}

template <typename T>
void raw_address(T ptr) {
  cout << bit_cast<uintptr_t>(ptr) << endl;
}

struct Object {
  int x;
  int y;
  int z;
};

int main() {
  int data[4] = {0, 1, 2, 3};
  int* a0 = &data[0];
  raw_address(a0);

  int* a3 = a0 + 3;
  raw_address(a3);

  int* a1 = a3 - 2;
  raw_address(a1);

  int* a4 = a1 + 10;
  raw_address(a4);

  Object obj;
  obj.x = 123;
  obj.y = 456;
  obj.z = 789;

  byte* start = bit_cast<byte*>(&obj);
  int* y = bit_cast<int*>(start + 4);
  cout << *y << endl;
}