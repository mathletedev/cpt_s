# Programming Assignment 3

> AVL Map

## Instructions

```bash
# download and extract `uszips.csv` into `data`
make data 

# compiles the project
make build

# runs the benchmarks
make exec
```

Note: `make data` requires `unzip` to be installed. Alternatively, download `uszips.csv` from [simplemaps.com](https://simplemaps.com/static/data/us-zips/1.90/basic/simplemaps_uszips_basicv1.90.zip) and extract into `data`.

## Analysis

- The `AvlMap` implementation has insertion and lookup time complexities of $O(\log n)$. This is confirmed by the `assert(std::abs(bf_(p_node)) <= 1)` @ `src/avl_map.hpp:211`, which asserts that the balance factor of any node is either -1, 0, or 1 on all height updates. Since the AVL property is satisfied, it is guaranteed that the time complexity is logarithmic (each node cuts the lookup space in half).
- AVL trees use rotations to rebalance the tree after each mutation. This ensures that the tree is always balanced, and a balanced tree has logarithmic performance.
- `AvlMap` outperformed `std::map`, requiring 10% less time (-0.0001 seconds) with `NUM_LOOKUPS = 1000`. According to cppreference, `std::map` is implemented as a red-black tree. Red-black trees tend to have faster insertions but slower lookups compared to AVL trees. This is reflected in the benchmark results, as this project did not consider insertions in the elapsed time calculation. Thus, `AvlMap`'s AVL tree naturally outperformed `std::map`'s red-black tree in lookups.

## Citations

- Zip code data: https://simplemaps.com/data/us-zips
- `std::map`: https://en.cppreference.com/w/cpp/container/map
