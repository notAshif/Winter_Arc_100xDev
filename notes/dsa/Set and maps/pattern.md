# Competitive Programming Patterns --- C++

A practical reference for recognizing common problem-solving patterns in
C++.

## 1. Arrays and Traversal

### Pattern 1: Basic Array Traversal

**Recognize when:** You need to inspect, count, sum, or find something
across all elements.

``` cpp
for (int i = 0; i < n; i++) {
    // process a[i]
}
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

### Pattern 2: Find Minimum / Maximum

**Recognize when:** You need the smallest or largest element.

``` cpp
int mn = a[0];
int mx = a[0];

for (int i = 1; i < n; i++) {
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
}
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

### Pattern 3: Consecutive Segment

**Recognize when:** You need the longest continuous sequence satisfying
a condition, such as a non-decreasing segment.

``` cpp
int current = 1;
int longest = 1;

for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) {
        current++;
    } else {
        current = 1;
    }

    longest = max(longest, current);
}
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

### Pattern 4: Prefix Sum

**Recognize when:** You have multiple range-sum queries or repeated
cumulative calculations.

``` cpp
vector<long long> pref(n + 1, 0);

for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
}

// Sum from index l to r, inclusive:
long long sum = pref[r + 1] - pref[l];
```

-   Preprocessing: `O(n)`
-   Each query: `O(1)`
-   Space: `O(n)`

## 2. Hashing and Frequency

### Pattern 5: Frequency Counting

**Recognize when:** You need to count how many times each value appears.

``` cpp
unordered_map<int, int> freq;

for (int x : a) {
    freq[x]++;
}
```

-   Average time: `O(n)` for all insertions
-   Space: `O(n)`

### Pattern 6: Check Element Existence / Count Distinct Values

**Recognize when:** You only need to know which unique values exist.

``` cpp
unordered_set<int> st;

for (int x : a) {
    st.insert(x);
}

cout << st.size(); // Number of distinct values
```

-   Average insertion and lookup: `O(1)`
-   Space: `O(n)`

### Pattern 7: Two Sum --- Find Whether a Pair Exists

**Recognize when:** You need to determine whether two different indices
contain values whose sum equals a target.

``` cpp
unordered_set<int> seen;

for (int x : a) {
    int need = target - x;

    if (seen.find(need) != seen.end()) {
        cout << "TRUE\n";
        break;
    }

    seen.insert(x);
}
```

Check before inserting the current value. This prevents using the same
index twice.

-   Average time: `O(n)`
-   Space: `O(n)`

### Pattern 8: Two Sum --- Return Indices

**Recognize when:** You need the indices of two elements whose sum
equals a target.

``` cpp
unordered_map<int, int> seen; // value -> index

for (int i = 0; i < n; i++) {
    int need = target - a[i];

    if (seen.find(need) != seen.end()) {
        cout << seen[need] + 1 << " " << i + 1 << '\n';
        break;
    }

    seen[a[i]] = i;
}
```

The map stores indices of previously visited elements. Add `1` when the
problem asks for 1-based indices.

-   Average time: `O(n)`
-   Space: `O(n)`

### Pattern 9: Two Sum --- Count All Valid Pairs

**Recognize when:** You need to count pairs `(i, j)` with `i < j` and
`a[i] + a[j] == target`.

``` cpp
unordered_map<int, long long> freq;
long long pairs = 0;

for (int x : a) {
    int need = target - x;

    pairs += freq[need]; // Count all matching previous elements
    freq[x]++;           // Then add the current element
}
```

-   Average time: `O(n)`
-   Space: `O(n)`

**Important:** Add the previous frequency, not just `1`. This correctly
handles duplicate values and counts each pair once.

## 3. Multisets and Distinct Counts

### Pattern 10: Insert / Remove One Occurrence with `unordered_multiset`

**Recognize when:** Duplicates are allowed and a removal query must
delete only one occurrence.

``` cpp
unordered_multiset<int> mst;

// Insert one occurrence:
mst.insert(x);

// Remove one occurrence, if present:
auto it = mst.find(x);
if (it != mst.end()) {
    mst.erase(it);
}

// Number of occurrences:
cout << mst.count(x);
```

-   Average insertion, lookup, and single-element erase: `O(1)`
-   `mst.erase(x)` removes **all** occurrences of `x`.
-   `mst.erase(it)` removes only the occurrence represented by the
    iterator.

### Pattern 11: Maintain Distinct Count with a Multiset

**Recognize when:** You need duplicate storage but also need to answer
distinct-count queries quickly.

``` cpp
unordered_multiset<int> mst;
int distinct = 0;

// Insert x:
if (mst.find(x) == mst.end()) {
    distinct++;
}
mst.insert(x);

// Remove one occurrence of x:
auto it = mst.find(x);

if (it != mst.end()) {
    mst.erase(it);

    if (mst.find(x) == mst.end()) {
        distinct--;
    }
}

// Answer distinct-count query:
cout << distinct;
```

-   Average time per query: `O(1)`
-   Space: `O(n)`

## 4. Two Pointers

### Pattern 12: Opposite-Direction Pointers

**Recognize when:** You process a sequence from both ends, such as
checking a palindrome.

``` cpp
int l = 0;
int r = n - 1;

while (l < r) {
    if (a[l] == a[r]) {
        l++;
        r--;
    } else {
        // Handle mismatch
        break;
    }
}
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

### Pattern 13: Same-Direction Pointers

**Recognize when:** You process a sorted array, compact elements, or
maintain a read/write position.

``` cpp
int j = 0;

for (int i = 0; i < n; i++) {
    if (/* keep a[i] */) {
        a[j] = a[i];
        j++;
    }
}

// The first j positions contain the kept elements.
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

## 5. Sliding Window

### Pattern 14: Fixed-Size Window

**Recognize when:** You need a sum, maximum, or minimum over every
contiguous subarray of exactly size `k`.

``` cpp
long long windowSum = 0;

for (int i = 0; i < k; i++) {
    windowSum += a[i];
}

long long best = windowSum;

for (int i = k; i < n; i++) {
    windowSum += a[i];
    windowSum -= a[i - k];

    best = max(best, windowSum);
}
```

-   Time: `O(n)`
-   Auxiliary space: `O(1)`

### Pattern 15: Variable-Size Window

**Recognize when:** You need the longest or shortest valid contiguous
subarray and the condition allows the window to expand and shrink.

``` cpp
int l = 0;
long long sum = 0;

for (int r = 0; r < n; r++) {
    sum += a[r];

    while (sum > target && l <= r) {
        sum -= a[l];
        l++;
    }

    // Update the answer using window [l, r].
}
```

This example assumes all array elements are non-negative. With negative
values, this shrinking rule is not generally valid.

-   Time: `O(n)` when each pointer only moves forward
-   Auxiliary space: `O(1)`

## 6. Binary Search

### Pattern 16: Standard Binary Search

**Recognize when:** You need to find a target in sorted data.

``` cpp
int l = 0;
int r = n - 1;

while (l <= r) {
    int mid = l + (r - l) / 2;

    if (a[mid] == target) {
        cout << mid;
        break;
    } else if (a[mid] < target) {
        l = mid + 1;
    } else {
        r = mid - 1;
    }
}
```

-   Time: `O(log n)`
-   Auxiliary space: `O(1)`

### Pattern 17: Lower Bound / First Valid Position

**Recognize when:** You need the first index where `a[i] >= target` in a
sorted array.

``` cpp
int l = 0;
int r = n; // Search range is [0, n).

while (l < r) {
    int mid = l + (r - l) / 2;

    if (a[mid] >= target) {
        r = mid;
    } else {
        l = mid + 1;
    }
}

// l is the first position with a[l] >= target,
// or n if no such position exists.
```

-   Time: `O(log n)`
-   Auxiliary space: `O(1)`

## 7. Stack and Queue

### Pattern 18: Monotonic Stack --- Next Greater Element

**Recognize when:** You need the next greater or smaller element, or the
nearest element satisfying an ordering condition.

``` cpp
stack<int> st;
vector<int> ans(n, -1);

for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= a[i]) {
        st.pop();
    }

    if (!st.empty()) {
        ans[i] = st.top();
    }

    st.push(a[i]);
}
```

This version finds the next greater value to the right.

-   Time: `O(n)` amortized
-   Space: `O(n)`

### Pattern 19: Queue / Breadth-First Search (BFS)

**Recognize when:** You need shortest distances in an unweighted graph
or level-by-level traversal.

``` cpp
queue<int> q;
vector<int> dist(n, -1);

q.push(source);
dist[source] = 0;

while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

-   Time: `O(V + E)` with an adjacency list
-   Space: `O(V)` for the queue and distance array

## 8. Sorting and Greedy

### Pattern 20: Sort Then Process

**Recognize when:** Sorting makes duplicates, ordering, nearest values,
or pair relationships easier to handle.

``` cpp
sort(a.begin(), a.end());

for (int i = 0; i < n; i++) {
    // Process sorted elements.
}
```

-   Time: `O(n log n)`
-   Extra space: implementation-dependent

### Pattern 21: Greedy Interval Selection

**Recognize when:** You need the maximum number of non-overlapping
intervals.

``` cpp
// Each interval is {start, end}.
sort(intervals.begin(), intervals.end(),
     [](const auto& a, const auto& b) {
         return a.second < b.second;
     });

int count = 0;
int lastEnd = INT_MIN;

for (auto [start, end] : intervals) {
    if (start >= lastEnd) {
        count++;
        lastEnd = end;
    }
}
```

Sort by ending time, then repeatedly choose the next compatible
interval.

-   Time: `O(n log n)`
-   Extra space: implementation-dependent

## 9. Number and Digit Techniques

### Pattern 22: Digit Extraction

**Recognize when:** You need to process individual digits of a
non-negative integer.

``` cpp
while (n > 0) {
    int digit = n % 10;

    // Process digit.

    n /= 10;
}
```

-   Time: `O(log10(n))`
-   Auxiliary space: `O(1)`

### Pattern 23: Reverse a Number

``` cpp
long long rev = 0;

while (n > 0) {
    int digit = n % 10;
    rev = rev * 10 + digit;
    n /= 10;
}
```

For negative numbers or possible overflow, handle the sign and bounds
separately.

### Pattern 24: Prime Check

**Recognize when:** You need to determine whether an integer is prime.

``` cpp
bool isPrime(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
```

-   Time: `O(sqrt(n))`
-   Auxiliary space: `O(1)`

Using `i <= n / i` avoids the potential overflow of `i * i`.

## Quick Recognition Table

  Problem clue                            Pattern to consider
  --------------------------------------- -----------------------------------
  Count occurrences                       Frequency map
  Check whether a value exists            `set` / `unordered_set`
  Count unique values                     `set` / `unordered_set`
  Find two values adding to a target      Two Sum / hashing
  Return indices for Two Sum              Hash map: value to index
  Count all Two Sum pairs                 Hash map: complement frequency
  Remove one duplicate occurrence         Multiset iterator erase
  Range-sum queries                       Prefix sum
  Longest continuous valid segment        Consecutive scan / sliding window
  Fixed-length subarray                   Fixed-size sliding window
  Sorted array search                     Binary search
  First position satisfying a condition   Lower bound
  Compare both ends                       Two pointers
  Next greater element                    Monotonic stack
  Shortest path in an unweighted graph    BFS
  Maximum non-overlapping intervals       Greedy
  Reverse digits / digit sum              Digit extraction
  Check primality                         Square-root loop

## How to Add New Patterns

For every new problem you solve, record:

1.  **Problem clue:** What wording or constraint suggests the technique?
2.  **Observation:** What key fact makes the solution work?
3.  **Pattern:** Which algorithm or data structure applies?
4.  **Template:** A reusable C++ implementation.
5.  **Complexity:** Time and auxiliary space.
6.  **Practice problems:** Problem names or links where you used it.

A pattern is a starting point, not a guarantee. Always verify that its
assumptions match the problem constraints.
