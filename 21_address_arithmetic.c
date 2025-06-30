/*
C is consistent and regular in its approach to address arithmetic; its integration of pointers, arrays and address
arithmetic is one of the major strengths of the language. Let us illustrate some of its properties by writing a 
rudimentary storage allocator (but useful in spite of its simplicity). There are two routines: alloc(n) returns a
pointer p to n consecutive character positions, which can be used by the caller of alloc for storing characters;
free(p) releases the storage thus acquired so it can be later re-used. The routines are "rudimentary" because the
calls to free must be made in the opposite order to the calls made on alloc. That is, the storage managed by
alloc and free is a stack, or last-in, first-out list. The standard C library provides analogous functions which
have no such restrictions, and in Chapter 8 we will show improved versions as well. In the meantime, however,
many applications really only need a trivial alloc to dispense little pieces of storage of unpredictable sizes at
unpredictable times.
The simplest implementation is to have alloc hand out pieces of a large character array which we will call
allocbuf. This array is private to alloc and free. Since they deal in pointers, not array indices, no other
routine need know the name of the array, which can be declared external static, that is, local to the source file
containing alloc and free, and invisible outside it. In practical implementations, the array may well not even
have a name; it might instead be obtained by asking the operating system for a pointer to some unnamed block of
storage.
The other information needed is how much of allocbuf has been used. We use a pointer to the next free element,
called allocp. When alloc is asked for n characters, it checks to see if there is enough room left in allocbuf.
If so, alloc returns the current value of allocp (i.e., the beginning of the free block), then increments it by n to
point to the next free area. free(p) merely sets allocp to p if p is inside allocbuf.
*/

#include<stdio.h>
#define NULL 0 /* pointer value for error report */
#define ALLOCSIZE 1000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
/* Above line could have been written as 
static char *allocp = &allocbuf[0];
since the array name is the address of the zeroth element */

char *alloc(n) /* return pointer to n characters */
int n;
{
    if(allocp + n <= allocbuf + ALLOCSIZE) { /* fits */
/*
This test checks if there's enough room to satisfy a request for n characters. If there is, the new value of allocp would be at
most one beyond the end of allocbuf. If the request can be satisfied, alloc returns a normal pointer (notice the
declaration of the function itself). If not, alloc must return some signal that no space is left. C guarantees that no
pointer that validly points at data will contain zero, so a return value of zero can be used to signal an abnormal
event, in this case, no space. We write NULL, instead of zero, however, to indicate more clearly that this is a special
value for a pointer. In general, integers cannot meaningfully be assigned to pointers; zero is a special case.
*/
    allocp += n;
    return(allocp - n); /* old p */
    } else /* not enough room */
        return(NULL);
}

free(p) /* free storage pointed to by p */
char *p;
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
#include<string.h>
int main() {
    int c;

    while((c=getchar()) != EOF) {
        putchar(c);
    }
}