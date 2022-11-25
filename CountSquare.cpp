// CountSquare.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <algorithm>
#include <format>
#include <iostream>
#include <set>
#include <string>
#include <vector>

static constexpr int N = 10;
static constexpr int e[N] = {3, 3, 3, 3, 4, 4, 7, 7, 7, 7}; // 'e' means edge
static int used[N];
static int len[5] = {};
static std::set<std::string> solutions;

inline bool IsValid() {
  return len[1] == len[3] && len[2] == len[4] && len[1] && len[2] && len[3] &&
         len[4];
}

inline void Append(const std::vector<int> &a, std::vector<int> &r) {
  std::copy(a.begin(), a.end(), back_inserter(r));
}

int Compare(const std::vector<int> &a, const std::vector<int> &b) {
  if (a[0] < b[0]) {
    return -1;
  } else if (a[0] > b[0]) {
    return 1;
  } else {
    const auto t1 = a[a.size() - 1];
    const auto t2 = b[b.size() - 1];
    if (t1 < t2)
      return -1;
    else if (t1 > t2)
      return 1;
    else
      return 0;
  }
}

inline void Merge(const std::vector<int> &a, const std::vector<int> &b,
                  std::vector<int> &r) {
  const auto cmp = Compare(a, b);
  switch (cmp) {
  case -1:
  case 0:
    Append(a, r);
    Append(b, r);
    break;
  case 1:
    Append(b, r);
    Append(a, r);
    break;
  }
}

bool IsDuplicate() {
  std::vector<int> empty;
  std::vector<std::vector<int>> s;
  for (int k = 0; k <= 4; ++k)
    s.emplace_back(empty);

  for (int k = 0; k < N; ++k) {
    if (used[k] > 0) {
      s[used[k]].emplace_back(e[k]);
    }
  }

  std::vector<int> r;

  if (len[1] < len[2]) {
    Merge(s[1], s[3], r);
    Merge(s[2], s[4], r);
  } else if (len[1] > len[2]) {
    Merge(s[2], s[4], r);
    Merge(s[1], s[3], r);
  } else {
    for (int k = 1; k <= 3; ++k) {
      for (int j = k + 1; j <= 4; ++j) {
        const auto cmp = Compare(s[k], s[j]);
        switch (cmp) {
        case 1:
          s[k].swap(s[j]);
          break;
        }
      }      
    }

    for (int k = 1; k <= 4; ++k)
      Append(s[k], r);
  }

  std::string h;
  for (const auto i : r) {
    h += std::format("{}", i);
  }

  if (std::get<1>(solutions.insert(h))) {
    printf("solution %zu (sorted edge numbers: %s):\n", solutions.size(), h.c_str());
    return false;
  }

  return true;
}

void PrintEdge(int edge) {
  printf("\tedge %u: ", edge);

  for (int k = 0; k < N; ++k) {
    if (used[k] == edge) {
      printf("%u ", e[k]);
    }
  }

  printf("\n");
}

void Print() {
  for (int k = 1; k <= 4; ++k) {
    PrintEdge(k);
  }
  printf("\n");
}

void DFS(int k) {
  for (int state = 0; state <= 4; ++state) {
    used[k] = state;

    len[state] += e[k];

    if (k == (N - 1)) {
      if (IsValid() && !IsDuplicate())
        Print();
    } else {
      DFS(k + 1);
    }

    len[state] -= e[k];
  }
}

int main() {
  DFS(0);
  printf("total solutions: %zu\n", solutions.size());
  return 0;
}