Project 1
=========

Custom, rudimentary library implementations of String, ArrayList, LinkedList and HashMap data structures.
All objects must be allocated by the user, but can be freed using the appropriate Free methods.
**Note:** When running tests, memory management and general code execution are optimal in Xcode, but buggy
       otherwise. Still some bugs to work out.

###String

The String library includes methods for common string manipulation: copying, character search, search by 
index, string length, substring search, trimming, splitting into tokens, etc. New string objects can be 
created by calling

```c
			String_New(str);
```

where `str` is a newly allocated String pointer.

###ArrayList

The ArrayList library is an expandable array implementation and includes basic collection methods: contains,
get item at index, set item at index, add, size, etc. It also includes more complex methods for ArrayList 
resizing and compacting. A new ArrayList object can be created by calling

```c
			ArrayList_New(list);
```

where `list` is a newly allocated ArrayList pointer.

###LinkedList

The LinkedList library is a custom, simple, doubly-linked list implementation. Memory concerns are not a 
staple here so a doubly-linked list implementation was preferred over a singly-linked list implementation as 
it makes some operations easier to implement. Basic linked list methods are included: set element at 
beginning, set element at end, get element at index, get list size, etc. A new LinkedList object can be 
created by calling
		
```c
			LinkedList_New(list);
```

where `list` is a newly allocated LinkedList pointer.

###HashMap

The HashMap library is a basic hashtable implementation that stores entries as key/value pairs, where the 
key is a String object and the value can be anything. The implementation uses the ArrayList and LinkedList 
objects mentioned above to provide a resizable hashtable that never exceeds a load factor of 1. This and 
a good hash function guarantee you will get constant time operations most of the time. HashMap includes basic
hashtable methods: set element for key, get element for key, get size, clear HashMap, remove element for key,
etc. A new HashMap object can be created by calling

```c
			HashMap_New(map):
```

where `map` is a newly allocated HashMap pointer.

###Tests

An included tester file includes all the necessary tests to ensure that all three above implementations are 
in order. Simply compile the above source files along with _tests.c_ and inspect the output.

```
			gcc --std=c99 -Wall String.h String.m ArrayList.h ArrayList.m LinkedList.h LinkedList.m HashMap.h\
				HashMap.m globalconst.h tests.c
```

###Histogram

Also included is a simple, non-graphical implementation of a histogram. Passing in any number of files, it 
will show the number of lines, words, characters, spaces and use the above HashMap implementation to print out 
how many times each word in the file occurs, as well as each character in the file. Compile the above source
files with _histogram.c_. The output is redirected to a file named File1.log in the same directory.

```
			gcc --std=c99 -Wall String.h String.m ArrayList.h ArrayList.m LinkedList.h LinkedList.m HashMap.h\
				HashMap.m globalconst.h histogram.c
m globalconst.h histogram.c
```
