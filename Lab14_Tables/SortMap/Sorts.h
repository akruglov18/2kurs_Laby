#ifndef _SPORTS_H
#define _SPORTS_H
#include <vector>

template<typename T>
void QuickSort(T* mas, int size) {
  QuickSort(mas, 0, size - 1);
}

template<typename T>
void QuickSort(T* mas, int left, int right) {
  int l = left, r = right;
  T mid = mas[(l + r) / 2];
  do {
    while (mas[l] < mid)
      l++;
    while (mas[r] > mid)
      r--;
    if (l <= r) {
      std::swap(mas[l], mas[r]);
      l++;
      r--;
    }
  } while (l <= r);
  if (left < r)
    QuickSort(mas, left, r);
  if (right > l)
    QuickSort(mas, l, right);
}

template<typename T>
void BubbleSort(T* mas, int size) {
  for (int i = size - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (mas[j] > mas[j + 1])
        std::swap(mas[j], mas[j + 1]);
    }
  }
}

template<typename T>
void InsertionSort(T* mas, int size) {
  for (int i = 1; i < size; i++) {
    T add = mas[i];
    int j = i - 1;
    while (j >= 0 && mas[j] > add) {
      mas[j + 1] = mas[j];
      j--;
    }
    mas[j + 1] = add;
  }
}

template<typename TK, typename TV>
void CountingSort(TNode<TK,TV>* mas, int size) {
  if (size > 0) {
    TK mx = mas[0].GetKey(), mn = mas[0].GetKey();
    for (int i = 1; i < size; i++) {
      mx = std::max(mx, mas[i].GetKey());
      mn = std::min(mn, mas[i].GetKey());
    }
    int cnt_size = mx - mn + 1;
    std::vector<std::vector<TNode<TK, TV>>> cnt(cnt_size);
    for (int i = 0; i < size; i++) {
      cnt[mas[i].GetKey() - mn].push_back(mas[i]);
    }
    int j = 0;
    for (int i = 0; i < cnt_size; i++) {
      for (int c = 0; c < cnt[i].size(); c++, j++) {
        mas[j] = cnt[i][c];
      }
    }
  }
}

int get_radix(int n, int num, int radix) {
  while (n > 0 && num  > 1) {
    n /= radix;
    num--;
  }
  return n%10;
}

template<typename TK, typename TV>
void RadixSort(TNode<TK,TV>* mas, int size) {
  if (size > 0) {
    TK mx = mas[0].GetKey();
    for (int i = 1; i < size; i++) {
      mx = std::max(mx, mas[i].GetKey());
    }
    int max_r = 0;
    while (mx > 0) {
      mx /= 10;
      max_r++;
    }

    std::vector<std::vector<TNode<TK, TV>>> cnt(10);
    for (int k = 0; k < max_r; k++) {
      for (int i = 0; i < size; i++) {
        int r = get_radix(mas[i].GetKey(), k + 1, 10);
        cnt[r].push_back(mas[i]);
      }
      int c = 0;
      for (int i = 0; i < cnt.size(); i++) {
        for (int j = 0; j < cnt[i].size(); j++) {
          mas[c] = cnt[i][j];
          c++;
        }
      }
      for (int j = 0; j < cnt.size(); j++) {
        cnt[j].clear();
      }
    }
  }
}
#endif