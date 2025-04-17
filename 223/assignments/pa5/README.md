# Programming Assignment 4 & 5

> Amazon Inventory Query System

## Instructions

```bash
# download dataset
make data 

# compiles the project
make build

# runs the application
make exec
```

Note: `make data` pulls the CSV file from my personal Dropbox. Alternatively, download the dataset from [Kaggle](https://kaggle.com/datasets/promptcloud/amazon-product-dataset-2020) and move to `data/dataset.csv`.

## PA5 Notes

Initially, I implemented `msort()` (merge sort) using immutable linked lists, but copying the list was expensive, resulting in a merge sort time complexity of $O(n^2)$. This meant `msort()` performed similarly (or even worse) than `isort()` (insertion sort).

Therefore, I implemented `msort()` using a mutable linked list, and being able to directly mutate pointers allowed for $O(n \log n)$ time complexity. This became immediately apparent in the results below:
- `isort()` slightly outperforms `msort()` for small lists (e.g. `> listInventory Toys`)
    - However, the difference is on the scale of microseconds, and is thus negligible
- `msort()` drastically outperforms `isort()` for large lists (e.g. `> listInventory "Toys & Games"`)
    - `msort()` takes around 0.02s on average, whereas `isort()` takes around 1.9s on average.

This shows how much better merge sort's `O(n \log n)` time complexity is necessary for large datasets, compared to insertion sort's `O(n^2)` time complexity.

Sample REPL commands:

```
> listInventory "Arts & Crafts"
69fa660abe76a3279733a88b0279e6af | Paper House Productions STM-0013E STM-0013 Unicorn Micro Stickers, 3-pack, Multi 3 Piece | $0.51
e7ef999c9950e17a5c9356da9d314047 | Crayola Nontoxic Anti-Dust Chalk, White, 12 Sticks/Box (50-1402) | $1.28
f6c679f8efe9dd23e8c9e2d73f017e73 | Trends International Emoji - Pop Up Stickers | $1.77
1d00635a17641f25399117fe8107a0f5 | STAEDTLER EF8030-5 Fimo Kids Oven-Bake Modeling Clay, 1.5 oz, Green | $1.80
2e2d46cee23bf6e46bcfc3202be60176 | Sticko 450188 Stickers, Shimmery Stars | $1.89
d481dd3a2d7468b91000e21b53828a92 | me & my BIG ideas LABS-37 Stickers, Rose Gold | $1.99
...
> listInventory "Sports & Outdoors" merge desc
e6cbd717f1a76dd5ce59e3a966de88ed | Playcraft Woodbridge Shuffleboard Table | $895.00 - $2,497.50
ad325dc0fd9634c4e1e5aa3aa9dc134c | Barrington Collection Shuffleboard Table - Available in Multiple Styles | $895.00
4897eddb3e082640b20e190bfac73d1b | Swagtron EB-8 Outlaw Fat Tire Electric Bike – Foldable Off-Road Fat eBike 20-inch Wheels with Power Assist, Freehub and Shimano 7-Speed Gear Shifts, Black, Large | $799.99
f31d4e4716ca95e3e0bbc9ce7a326eaa | Skybound Horizon 11X18ft Rectangle Trampoline with Safety Enclosure and Ladder | $799.95
33c01408bdcc8f1b66b9d21a7da30ea2 | Challenger Shuffleboard Table w Dark Cherry Finish, Hardwood Playfield and Storage Cabinets | $748.00 - $2,024.91
cc64da6022c5e3412e5018465cdefcb2 | MightySkins Skin Compatible with Razor Hovertrax 2.0 Hover Board Self-Balancing Smart Scooter wrap Cover Sticker Skins Dolphin | $553.48
...
```

## PA4 Notes

- `LinkedList` and `AvlMap` are copied from my PA1 and PA3, respectively. Some modifications were made.
- `AvlMap` was used to map command names to functions.
- I use a hash table / hash map to store `id` and `category` relations. This allows for $O(1)$ amortised insertions and lookups.
    - My implementation uses quadratic probing and rehashing to resolve hash collisions.
    - I use `std::hash` to hash `id` and `category` strings.

Sample REPL commands (old):

```
> find 4c69b61db1fc16e7013b43fc926e502d
ID: ...
Name: ...
Brand: ...
...
> listInventory Sports & Outdoors
4c69b61db1fc16e7013b43fc926e502d | DB Longboards CoreFlex Crossbow 41" Bamboo Fiberglass Longboard Complete
5bb4a9aa52085ada20006d166b1e2f87 | Franklin Sports Eye Black Stickers for Kids - Customizable Lettering Baseball and Football Eye Black Stickers - White Pencil Included
...
```

## Citations

- Kaggle Amazon sample dataset: https://kaggle.com
