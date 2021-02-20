# containers_test

<p align="center">
	<img src="./assets/img.png" >
</p>

## Usage

Go in your ft_containers' repository and:

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

Then what?  
There are a few executables and here is their usage:

```bash
./do.sh [container_to_test] [...]
./cmp_one <path/to/test_file>
./one <file> [namespace=ft] [path/to/includes=..]
```

Examples:
```bash
./do.sh # to test every containers
./do.sh vector list # to test only your vector && list, for instance

./cmp_one srcs/list/size.cpp # to see the result comparison (ft/std) on this test file only

./one srcs/list/rite.cpp std # to see the output of this test file with the std
```

## Tested features
- [x] vector
- [x] vector's iterators
- [ ] list
- [ ] list's iterators
- [ ] stack
- [ ] queue
- [ ] map
- [ ] map's iterators
