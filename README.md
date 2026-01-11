So this is a combination of random programs I'm writing while learning. Currently working on backtracing algorithm for a sudoku solver. I'm feeling confident in my skills of reading others code. e.g. minishell is a french program off of github. I'll add a source later and properly fork it. Also feel pretty good about my program designs and APIs as well as some beginner algorithms. Need to work on network programming and signals as well as forking and multithreading. Possibly work on memory and dynamic allocation as well 

Another thing I want to get back to is the K&R book then Berj and TCP/IP Illustrated &c.

# Modular C Practice Tasks

---
- Build some kind of file parser for configs
- Build an input parser

## File & Data Handling

1. **Struct to Binary** – Write a `Person` struct (name, age) to a binary file.
2. **Binary to Struct** – Read the binary file and print each person.
3. **Append Log Line** – Append a line with a timestamp to a `.txt` log.
4. **Line Counter** – Count how many lines exist in a given text file.
5. **Array to File** – Serialize an array of structs to disk.
6. **Read Column** – Read a CSV file and print only the second column.
7. **Log Levels** – Write logs with "INFO", "WARN", or "ERROR" prefixes.
8. **Word Counter** – Count how many times a word appears in a file.

---

##  Networking (Mockups or Real)

9. **TCP Echo Server** – Accept a client and echo back all input.
10. **TCP Client** – Connect to a server and send `"Hello"` string.
11. **Input Validation** – Validate string before sending (e.g., alphanumeric only).
12. **Fake Packet Loss** – Use `rand()` to simulate dropped packets.
13. **Simple Protocol** – Send a 4-byte length before the message body.

---

##  Memory and Structs

14. **Dynamic Int Array** – Create resizable array with `malloc` + `realloc`.
15. **Nested Free** – Free a struct with internal heap pointers.
16. **Intentional Leak** – Leak memory on purpose, then fix it.
17. **Fixed-Size Cache** – Evict oldest item when cache array is full.
18. **Singly Linked List** – Add, delete, and print operations.

---

##  Logic and Behavior

19. **Find Duplicates** – From a list of `int`, print duplicates.
20. **Hash Function** – Implement a basic hash function for strings.
21. **Key=Value Parser** – Split `key=value` into separate variables.
22. **Struct Sorter** – Sort an array of structs by field (like `age`).
23. **Lookup Table** – Searchable array of key/value pairs via struct.

---

##  Algorithms and Parsing

24. **Reverse String** – In-place string reversal.
25. **Longest Word** – Return longest word in a sentence.
26. **Hex to Int** – Convert `"1F"` string to integer.
27. **Command Parser** – Parse `"add 2 3"` into a function call.
28. **Simple Calculator** – CLI calculator supporting `+ - * /`.

---

##  Validation and Testing

29. **Is Integer?** – Check if string is a valid base-10 integer. This is almost done. Just modify one of the stoi functions
30. **Login Mock** – Hardcoded username/password login system.
31. **Email Validator** – Check for presence of `@` and `.` after.
32. **Test Helper** – Implement `assert_equal()` for simple unit tests.

---

##  System Utilities

33. **Time Function** – Measure time a function takes with `gettimeofday()`.
34. **Print Env Vars** – List all environment variables.
35. **Get CWD** – Print current working directory.
36. **Config Reader** – Load key/value settings from a config file.

---

##  Misc & Utility

37. **PRNG w/ Seed** – Custom pseudo-random generator with user seed.
38. **CLI Menu** – Menu system using `switch` and `scanf`.
39. **Tokenizer** – Split a string on spaces or commas.
40. **Run Tracker** – Save how many times program has been run (file counter).

