
#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE]; // array of storage for alloc
// could also be written as char *allocp = &allocbuf[0]; (point to beginning to the array):
static char *allocp = allocbuf; // next free position (start at the first position)

/**
 * @brief allocate n bytes.
 *
 * @param n number of bytes to allocate.
 * @return char* pointer to the allocated space.
 */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) { // It fits
        allocp += n;
        return allocp - n; // return pointer to allocated space (old allocp)
    } else
        // C guarantees that 0 is never a valid address for data (so use it if not enough space):
        return 0; // not enough space
}

/**
 * @brief free the allocated space.
 *
 * @param p pointer to the allocated space.
 */
void afree(char *p) {
    if (p >= allocbuf && p <= allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
