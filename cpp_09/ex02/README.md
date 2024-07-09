# PMergeMe

---

## Resources

- [wiki](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [github.com/decidedlyso](https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md)
- [github.com/Mikastiv](https://github.com/Mikastiv/FordJohnsonSort/blob/main/main.cpp)
  (there seems to be a mistake in this repo);

## Understanding

1. The list of numbers will be paired up The method for pairing is arbitrary.
   (I chose: n, n + size/2). Leaving any unpaired number out
2. The pairs will do swap their values if the first number is greater than the second number.
3. This will be done recursively until the no more pairs can be made. Keep in mind swapping values will also influence the parent pairs.
4.

### Example

```plaintext
 9 2 4 7 0 8 5 1 6        | 1
 8 2 1 6   9 5 4 7        | 2
 |_|_|_|___| | | | swap
   |_|_|_____| | |
     |_|_______| | swap
       |_________| swap
 8 2 1 6  |9 5 4 7        | 3
 1 2 8 6  |4 5 9 7        | 3.3
 |_|_| |   |_|_| | swap
   |___|     |___|
 2 1 6 8   5 4|7 9        | 3.3.3
 |_| |_|   |_| |_| swap
                          | Recursion ends
 2 1 6 8   5 4 7-9        | 3.3.4
 2 1 6 8   5 4 7-9        |
 2 1 6 8   5 4-7 9        |
 2 1 6 8   4-5 7 9        |
 2 1 6 8   4 5 7 9        |
 2 1 6 8 0-4 5 7 9        |
 1 6 8 0-2 4 5 7 9        |
 1 8 0-2 4 5 6 7 9        |
 8 0-1 2 4 5 6 7 9        |
 0-1 2 4 5 6 7 8 9        |
 0 1 2 4 5 6 7 8 9        |

legend:
  |    - List for current itteration
|___|  - pair
  -    - start sorted list
```
