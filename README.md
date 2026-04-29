Circular Buffer Implementation (CE-ESY26 - Assignment)
Description
​This project implements a Circular Buffer (Ring Buffer) data structure using the C programming language. Unlike a linear buffer, a circular buffer connects the end back to the beginning, making it efficient for streaming data and fixed-memory management.
​Features
​Initialization: Sets up the buffer pointers and counter.
​Write Operation: Adds data to the buffer with Overflow protection.
​Read Operation: Removes and retrieves data with Underflow protection.
How it Works
​The implementation uses a structure (struct) containing:
​An array to store data.
​head: Pointer for reading.
​tail: Pointer for writing.
​count: Tracks current elements to identify Full/Empty states.
