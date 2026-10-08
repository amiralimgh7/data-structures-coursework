# Data Structures Coursework

Two C++ course submissions by Amirali Moghadasi, with portable C++17 builds and regression tests.

## Run

```bash
make
make test
./felix < input.txt
./mafia < input.txt
```

Requires a C++17 compiler, Make and Python 3. Windows was verified with Cygwin; CI runs on Ubuntu.

### Felix the Repairman

Reads `n q`, followed by `q` commands of the form `x y U` or `x y L`. Maintains ordered sets/maps for upward and leftward repair queries on a grid. The restored implementation guards end iterators before dereferencing and validates the command stream. Regression fixtures cover boundary and repeated-ray cases; the original course algorithm is retained.

### Mafia Nights

Reads `n` followed by `n` integers. Computes the number of simultaneous elimination rounds until no element is smaller than its left neighbor, using a monotonic stack. The original variable-length arrays were replaced by standard vectors; empty input sequences return zero.

Tests compare Mafia Nights with an independent brute-force simulation for 310 seeded random sequences, including empty and repeated values. Both programs return a nonzero status on malformed input.
