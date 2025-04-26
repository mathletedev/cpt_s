#import "@preview/problemst:0.1.2": pset
#import "@preview/syntree:0.2.1": tree

#show: pset.with(
  class: "CPT_S 223",
  student: "Neal Wang",
  title: "Homework 5",
  date: datetime(year: 2024, month: 4, day: 25),
)

=

#table(
  columns: 12,
  table.header(
    [*0*],
    [*1*],
    [*2*],
    [*3*],
    [*4*],
    [*5*],
    [*6*],
    [*7*],
    [*8*],
    [*9*],
    [*10*],
    [*11*],
  ),

  [0], [0], [1], [3], [], [6], [6], [6], [7], [7], [3], [11],
)

=

==

#table(
  columns: 3,
  table.header(
    [],
    [*Program A (w/ path compression)*],
    [*Program B (w/o path compression)*],
  ),

  [1. `find(8)`], [3], [3],
  [2. `find(7)`], [2], [2],
  [3. `find(10)`], [2], [2],
  [4. `find(7)`], [1], [2],
  [5. `find(9)`], [2], [3],
  [6. `find(2)`], [2], [2],
  [*Total Steps*], [*12*], [*14*],
)

==

=== Program A's final tree

#tree(
  "",
  tree(
    "0",
    "1",
    "2",
    "3",
    tree("6", "5"),
    "7",
    "8",
    "9",
    "10",
  ),
)

=== Program B's final tree

#tree(
  "",
  tree(
    "0",
    tree("3", "10"),
    tree("6", tree("5"), tree("7", "8", "9")),
    tree("1", "2"),
  ),
)

=

== Unions performed by size and simple finds

#grid(
  columns: 12,
  gutter: 24pt,
  tree("", "0"),
  tree("", "1"),
  tree("", "2"),
  tree("", "3"),
  tree("", "4"),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(1, 2)`

#grid(
  columns: 11,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", "3"),
  tree("", "4"),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(3, 4)`

#grid(
  columns: 10,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", "4")),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(4, 5)`

#grid(
  columns: 9,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", tree("4", "5"))),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(6, 8)`

#grid(
  columns: 8,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", tree("4", "5"))),
  tree("", tree("6", "8")),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#pagebreak()

`union(5, 8)`

#grid(
  columns: 7,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", tree("4", "5"), tree("6", "8"))),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(1, 6)`

#grid(
  columns: 6,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", tree("4", "5"), tree("6", "8"), tree("1", "2"))),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(7, 9)`

#grid(
  columns: 5,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", tree("4", "5"), tree("6", "8"), tree("1", "2"))),
  tree("", tree("7", "9")),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(10, 11)`

#grid(
  columns: 4,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", tree("4", "5"), tree("6", "8"), tree("1", "2"))),
  tree("", tree("7", "9")),
  tree("", tree("10", "11")),
)

#pagebreak()

`union(11, 9)`

#grid(
  columns: 3,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", tree("4", "5"), tree("6", "8"), tree("1", "2"))),
  tree("", tree("7", tree("9"), tree("10", "11"))),
)

#line(length: 100%)

`union(1, 11)`

#grid(
  columns: 2,
  gutter: 24pt,
  tree("", "0"),
  tree(
    "",
    tree(
      "3",
      tree("4", "5"),
      tree("6", "8"),
      tree("1", "2"),
      tree("7", tree("9"), tree("10", "11")),
    ),
  ),
)

#pagebreak()

== Unions performed by size and path compression

#grid(
  columns: 12,
  gutter: 24pt,
  tree("", "0"),
  tree("", "1"),
  tree("", "2"),
  tree("", "3"),
  tree("", "4"),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(1, 2)`

#grid(
  columns: 11,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", "3"),
  tree("", "4"),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(3, 4)`

#grid(
  columns: 10,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", "4")),
  tree("", "5"),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(4, 5)`

#grid(
  columns: 9,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", "4", "5")),
  tree("", "6"),
  tree("", "7"),
  tree("", "8"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(6, 8)`

#grid(
  columns: 8,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", "4", "5")),
  tree("", tree("6", "8")),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(5, 8)`

#grid(
  columns: 7,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("1", "2")),
  tree("", tree("3", "4", "5", "6", "8")),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#pagebreak()

`union(1, 6)`

#grid(
  columns: 6,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", "4", "5", "6", "8", tree("1", "2"))),
  tree("", "7"),
  tree("", "9"),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(7, 9)`

#grid(
  columns: 5,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", "4", "5", "6", "8", tree("1", "2"))),
  tree("", tree("7", "9")),
  tree("", "10"),
  tree("", "11"),
)

#line(length: 100%)

`union(10, 11)`

#grid(
  columns: 4,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", "4", "5", "6", "8", tree("1", "2"))),
  tree("", tree("7", "9")),
  tree("", tree("10", "11")),
)

#line(length: 100%)

`union(11, 9)`

#grid(
  columns: 3,
  gutter: 24pt,
  tree("", "0"),
  tree("", tree("3", "4", "5", "6", "8", tree("1", "2"))),
  tree("", tree("7", "9", "10", "11")),
)

#pagebreak()

`union(1, 11)`

#grid(
  columns: 2,
  gutter: 24pt,
  tree("", "0"),
  tree(
    "",
    tree("3", "4", "5", "6", "8", tree("1", "2"), tree("7", "9", "10"), "11"),
  ),
)
