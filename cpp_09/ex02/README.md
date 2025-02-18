# PMergeMe

---

## Resources

- [wiki](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [github.com/decidedlyso](https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md)
- [github.com/Mikastiv](https://github.com/Mikastiv/FordJohnsonSort/blob/main/main.cpp)
  (there seems to be a mistake in this repo);

## Understanding

1. The list of numbers will be paired up The method for pairing is arbitrary.
   (I chose: n, n + size/2). Leaving any unpaired number out.
2. The pairs swap their values if the first number is greater than the second number.
3. This will be done recursively until the no more pairs can be made.
   Keep in mind swapping values will also influence the parent pairs.
4. Now the biggest number will be at the end of the list and we can start the
   binary-insertion sort. The order of which number is inserted are determined by

### Example

```plaintext
9 2 4 7 10 8 5 1 6        | 1
8 2 1 6    9 5 4 7        | 2
|_|_|_|____| | | | swap
  |_|_|______| | |
    |_|________| | swap
      |__________| swap
8 2 1 6   |9 5 4 7        | 3
1 2 8 6   |4 5 9 7        | 3.3
|_|_| |    |_|_| | swap
  |___|      |___|
2 1 6 8    5 4|7 9        | 3.3.3
|_| |_|    |_| |_| swap
                          | Recursion ends
2 1 6 8    5 4| 7-9        |
2 1 6 8    5 4|-7 9        | 3.3.4
2 1 6 8   |5 4 -7 9        |
1 2 6 8   |4-5  7 9        | 3.4
1 2 6 8  |-4 5  7 9        | 3.5
 |2 6 8   -1 4 5  7 9      | 4

We split up the number sequence from the slice using Jacobsthalnumbers as buckets for insertion
    2 6 8   - 1 4 5 7 9        |

    2 6 8   -[1 4 5]7 9        |
    2 8   -[1 4 x]5 7 9        |
    2 8   -[1 4]5 x 7 9        |

    2 6 8   -[1 4]5 7 9        |
    6 8   -[1 x 4 5]7 9        |

2 8   -1 4 5 6 7 9        | 5
8   -1 2 4 5 6 7 9        |
10-1 2 4 5 6 7 8 9        |
 1 2 4 5 6 7 8 9 10       |

legend:
  |    - List for current itteration
|___|  - pair
  -    - start sorted list (S)
 [ ]   - numbers to compare to
```
