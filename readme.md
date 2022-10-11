# Human Detection and Tracking
---

## Overview
Human detection and tracking project for Midterm of course ENPM 808X

## Authors
- [Shailesh Pranav Rajendran](https://github.com/shaileshpranav)
- [Harika Pendli](https://github.com/harika-pendli)

## UML
<img title="UML" alt="UML diagram" src="uml/uml_diagram.svg">

## Activity diagram
<img title="Activity" alt="UML diagram" src="uml/activity_diagram.svg">

## Standard install via command-line
```
git clone --recursive https://github.com/shaileshpranav/Human_avoidance
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
