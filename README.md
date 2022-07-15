# Storage Managment
Rudimentary storage allocator using the Stack data structure. Section 5.4 of The C Programming Language.

## About the project:
- `alloc(n)` returns a pointer p to n consecutive character positions which can be used by the caller of `alloc` for storing characters.
- `afree(p)` releases the storage thus acquired so it can be reused later.
- The routines are "redimentary" because the calls to `afree` must be made in the opposite order to the calls made on `alloc`.
- The storage managed by `alloc` and `afree` is a Stack.

## How `allocbuf` is used:
- We use a pointer called `allocp` that points to the next free element.
- When `alloc` is asked for n characters, it checks to see if there is enough room left in `allocbuf`. If so, `alloc` returns the currect value of `allocp` (the beginning of the free block), then increments it by n to point to the next free area.
- If there is no room, `alloc` returns zero.
- `afree(p)` merely sets `allocp` to `p` if `p` if inside `allocbuf`.

![image](https://user-images.githubusercontent.com/92950538/179277669-ea4fcdb3-1839-465b-856b-14b39fe7f992.png)


## What did I learn from this:

