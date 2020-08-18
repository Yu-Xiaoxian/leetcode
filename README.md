# LeetCoding Record 

Follow me at [LeetCode](https://leetcode.com/yu-xiaoxian)

# How to use this project

## Install Pre-requires
```shell
######## Ubuntu/Debian ############
sudo apt-get update
sudo apt-get install -y \
    g++
    ninja-build
```

## Build Project
```shell
mkdir build
cd build
cmake .. -G Ninja -DCXX11=ON
ninja
```

## Run Certain Problem
For Example
```
./347.top-k-frequent-elemnts
```

# TODO
- [ ] Use GTest for testing instead of main()
- [ ] Load test-case from txt file
- [ ] Implement common container such as TreeNode
- [ ] Add CMake-make workflow for CI/CD
