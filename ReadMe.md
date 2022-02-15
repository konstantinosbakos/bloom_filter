# Bloom Filter [![Project Status: Inactive – The project has reached a stable, usable state but is no longer being actively developed; support/maintenance will be provided as time allows.](https://www.repostatus.org/badges/latest/inactive.svg)](https://www.repostatus.org/#inactive) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



## Contents
### bin
- Contains a demo main function to showcase the data structure.
- Contains the Makefile used to compile the project.
### src
- Contains the source code of the project.
## Compilation
Please type `make` inside the `bloom_filter/bin` folder.\
After that, type `./bloom_filter` to run the program.\
To delete the objective files and the executable type `make clean`
## Insight
The project consists of one class, **bloom_filter**.
- A bloom filter is a probabilistic data structure that is used to test whether an element is part of a set. Although false positives are possible, false negatives are not.
- In order to lessen the probability of a false positive, the use of a set of *k* hash functions as well as a large bloom filter size is encouraged.
- The bloom_filter operates bitwise on the bytes (cells) of the bloom_filter_array.
- The functions that bloom_filter contains are:
	- `bloom_filter_search()`
	- `bloom_filter_insert()`