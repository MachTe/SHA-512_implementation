# Implementation of the SHA-512
This repository contains C++23 implementation of the SHA-512 cryptographic hash function as described in /src/**sha256-384-512.pdf**. The bulk of the code is in the header file /src/**SHA-512.h**, while an example of how to use it is in the /src/**SHA-512_example.cpp**.

I have attempted to make the code as versatile as possible, while still managing to keep the length of it at bay. (Most other implementations I have come across used unnecessary amount of non-standard libraries and were defined to work only on strings.)
Therefore the function SHA-512 as implemented takes argument of the type std::istream. Which allows the user to make hashes not only of strings, but also of all files, as is demonstrated on the test_file.gif.