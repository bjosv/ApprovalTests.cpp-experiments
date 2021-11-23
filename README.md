# ApprovalTests.cpp experiments

Simple experiments how to build https://github.com/approvals/ApprovalTests.cpp

This has been tested on Linux Ubuntu 20.04 and maOS Monterey 12.0.1 (M1).

## Build using an installed ApprovalTests.cpp library and headers

### Prepare install directory
```
mkdir /tmp/install
```

### Install googletest
```
git clone https://github.com/abseil/googletest.git
cd googletest
git checkout release-1.8.1
mkdir -p build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/tmp/install/ ..
make -j8
make install
```

### Install ApprovalTests.cpp

Note: The install target is missing today, this is wanted behavior.

The build option `APPROVAL_TESTS_ENABLE_GHC_FILESYSTEM_INTEGRATION` to disable the build and installation of ghc headers is also wanted.

[Link](https://github.com/Nordix/ApprovalTests.cpp/commit/37b5797bacfef01763e9d08a7199c6f4e2f75134) to a simplified implementation.

```
# This branch contains an example of an `install` target
git clone -b add-install-target https://github.com/Nordix/ApprovalTests.cpp.git

cd ApprovalTests.cpp
mkdir -p build2 && cd build2
cmake -DCMAKE_INSTALL_PREFIX=/tmp/install/ \
-DAPPROVAL_TESTS_BUILD_TESTING=OFF \
-DAPPROVAL_TESTS_BUILD_EXAMPLES=OFF \
-DAPPROVAL_TESTS_BUILD_DOCS=OFF \
-DAPPROVAL_TESTS_BUILD_THIRD_PARTY_CATCH2=OFF \
-DAPPROVAL_TESTS_BUILD_THIRD_PARTY_DOCTEST=OFF \
-DAPPROVAL_TESTS_BUILD_THIRD_PARTY_UT=OFF \
-DAPPROVAL_TESTS_ENABLE_BOOST_TEST_INTEGRATION=OFF \
-DAPPROVAL_TESTS_ENABLE_CATCH2_INTEGRATION=OFF \
-DAPPROVAL_TESTS_ENABLE_CPPUTEST_INTEGRATION=OFF \
-DAPPROVAL_TESTS_ENABLE_DOCTEST_INTEGRATION=OFF \
-DAPPROVAL_TESTS_ENABLE_GOOGLETEST_INTEGRATION=OFF \
-DAPPROVAL_TESTS_ENABLE_UT_INTEGRATION=OFF \
..
make -j8
make install
```

### View install directory
```
tree /tmp/install
```

### Build test
```
git clone git@github.com:bjosv/ApprovalTests.cpp-experiments.git
cd ApprovalTests.cpp-experiments
mkdir -p build && cd build
cmake ../tests
make
make test
```
