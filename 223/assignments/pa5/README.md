# Programming Assignment 4

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
> listInventory Sports & Outdoors
4c69b61db1fc16e7013b43fc926e502d | DB Longboards CoreFlex Crossbow 41" Bamboo Fiberglass Longboard Complete
5bb4a9aa52085ada20006d166b1e2f87 | Franklin Sports Eye Black Stickers for Kids - Customizable Lettering Baseball and Football Eye Black Stickers - White Pencil Included
...
```

## Citations

- Kaggle Amazon sample dataset: https://kaggle.com
