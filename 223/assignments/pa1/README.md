# Programming Assignment 1

> Linux commands matching game

## Questions

What is one advantage and one disadvantage of using a linked list data structure to store commands?

- **Advantage**: Allows for dynamic resizing of the list. When adding a command, a simple `commands_.push_back()` @ `src/game_manager.cpp:252` requires $O(1)$ time. If an array were to be used, a maximum size would need to be specified, or the array would need to be re-allocated for every resize, costing $O(n)$ time to copy.
- **Disadvantage**: Requires $O(n)$ time to get the $n$th command. For instance, at `commands_.nth()` @ `src/game_manager.cpp:158`, where random commands are selected, each query requires $O(n)$ time as opposed to an array, which would require $O(1)$ time.

What is one advantage and one disadvantage of using an array to store user profiles?

- **Advantage**: Allows for $O(1)$ querying for user profiles, such as at `&players_[choice - 1]` @ `src/game_manager.cpp:217`. A linked list would require $O(n)$ time for this case.
- **Disadvantage**: Uses a static size, specified in `#define MAX_PROFILES 10` @ `src/utils.hpp:3`. This means there are only 10 profile slots available, whereas a linked list could easily grow to support more players.
