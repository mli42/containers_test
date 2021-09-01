# containers_test

<p align="center">
	<img src="./assets/demo.gif" >
</p>

## Warning

This tester was made with the first version of ft_containers' subject \
Thus it does not test iterator traits (yet?)

Also, passing this tester does not mean the project was done correctly, please go further

## Usage

Go in your ft_containers' directory:

```bash
git clone https://github.com/mli42/containers_test.git && cd ./containers_test/
```

Expected tree:

```
. [ft_container]
├── <container>.hpp
├── [...]
└── containers_test
    └── [...]
```

If your project does not fit the expected tree (e.g. has sub-directories and/or file names are capitalized or what) \
Please edit the first line of `./<container>/common.hpp` (for filenames) \
Or the variable `tested_path` in `fct.sh` (for special path)

Then what? \
There are a three executables! How do we use them?

```bash
./do.sh [container_to_test] [...]
./cmp_one <path/to/test_file>
./one <path/to/test_file> [namespace=ft]
```

Examples:
```bash
./do.sh # tests every containers
./do.sh vector list # tests only vector && list

./cmp_one srcs/list/size.cpp # prints the result comparison (ft/std) on this test file only

./one srcs/list/rite.cpp # prints the output of this test file using ft namespace
./one srcs/list/rite.cpp std # prints the output of this test file using the std
```

How to read the output ?
```
The [ ✅ / ❌ ] emojis shows if they behave the same, i.e if the STL and your implementation:
- compile the same way,
- return the same number,
- print the same output.

If a diff occurs, a deepthought is created and logs are kept.

The [Y/N] shows if the STL compile (Y) or not (N), there are some test where you should not compile.
(If every test gives `N`, there is probably a problem with your hpp headers. Use ./one to debug)
```

## Tested features
- [x] vector
- [x] list
- [x] map
- [x] stack
- [x] queue
- [x] deque
- [x] multimap
- [x] set
- [x] multiset

## Contributors

PRs are welcomed! \
Thank you!
