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

## Notes

- `LinkedList` and `AvlMap` are copied from my PA1 and PA3, respectively. Some modifications were made.
- `AvlMap` was used to map command names to functions.
- I use a hash table / hash map to store `id` and `category` relations. This allows for $O(1)$ amortised insertions and lookups.
    - My implementation uses quadratic probing and rehashing to resolve hash collisions.
    - I use `std::hash` to hash `id` and `category` strings.

Sample REPL commands:

```
> find 4c69b61db1fc16e7013b43fc926e502d
ID: ...
Name: ...
Brand: ...
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

## Citations

- Kaggle Amazon sample dataset: https://kaggle.com
