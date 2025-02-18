# Programming Assignment 2

> Josephus Problem

## Running

```sh
make build # compiles the project; copies over data files
make exec # runs the simulation; enter `list` or `vector` to select variant

cat results.log # displays benchmark results
```

Screenshot of results @ `demo.png`

## Questions

> Does machine processing power affect execution time?

Yes. For instance, if a CPU has a higher clock speed, it will simply execute more operations per second, outperforming a lower clock speed CPU (the higher clock speed CPU will be faster).

> Which performs better: `std::list` or `std::vector?` Under what conditions?

`std::list` performed better, executing around *26.7%* faster (on average) than `std::vector`. \
This is because the Josephus Problem requires many mid-container deletions, which `std::list` is more efficient at. \
However, with very small values of `N`, `std::vector` may outperform `std::list` due to its more efficient memory layout. \
It is also important to note that IO is expensive, which may skew the results. To account for this, I performed the same number of IO operations between the two variants.

> How does `N` impact runtime compared to `M`?

Time complexities:
- `ListMyJosephus`: $O(N \times M)$
- `VectorMyJosephus`: $O(N \times (N + M))$ or $O(N^2 + N \times M)$

A breakdown of the time complexities:
- $O(N)$ for the outer `while (current_size() > 1)` loop (`current_size()` shrinks by 1 each iteration)
- $O(M)$ for the inner `std::next()` advancement of the iterator
- $O(1)$ for `std::list.erase()`
- $O(N)$ for `std::vector.erase()`

Thus, both `N` and `M` are equally impactful for `ListMyJosephus`, but `N` is more impactful (makes runtime slower) than `M` for `VectorMyJosephus`. \
We can also see that `ListMyJosephus` is more efficient for large values of `N` and `M`. \
However, in practice, since `M % N` is being used for `std::next()`, `M` will tend to be less significant compared to `N`.
