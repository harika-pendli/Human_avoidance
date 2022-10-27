# Human Detection and Tracking

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![C/C++ CI](https://github.com/shaileshpranav/Human_avoidance/actions/workflows/CI.yml/badge.svg)](https://github.com/shaileshpranav/Human_avoidance/actions/workflows/CI.yml)
[![Coverage Status](https://coveralls.io/repos/github/shaileshpranav/Human_avoidance/badge.svg?branch=main)](https://coveralls.io/github/shaileshpranav/Human_avoidance?branch=main)

## Overview
Human detection and tracking project for Midterm of course ENPM 808X

Acme Robotics Inc. is a private company set to launch a 4-wheeled robot used to deliver packages inside office for an undisclosed multinational company next. This robot is set to debut early next year. It moves in the corridor at a walking pace. The package is stored inside of the robot and drives itself to the customer. They have given us complete ownership of designing and developing a new feature for this robot's perceeption stack -"Human detector and tracker". 

Object detection is a very important computer vision task. Human detection is the task of locating all instances of human beings present in an image, and it has been most widely accomplished by searching all locations in the image, at all possible scales, and comparing a small area at each location with known templates or patterns of people. Human tracking is the process of temporally associating the human detections within a video sequence to generate persistent paths, or trajectories, of the people. Human detection and tracking are generally considered the first two processes in a video surveillance pipeline, and can feed into higher-level reasoning modules such as action recognition and dynamic scene analysis. Object detection and tracking is of utmost importance for different kinds of applications such as safety, surveillance, man-machine interaction, driving assistance system, traffic monitoring. Finding people in images has attracted much attention in recent years for practical applications such as visual surveillance. The detection of a human being is important for abnormal event detection, human gait characterization, people counting, person identification and tracking, pedestrian detection, gender classification. Human detection and tracking are tasks of computer vision systems for locating and following people in video imagery.

This is an example of human detection.

<img title="Detect_Ex" alt="Detect_Ex" src="docs/detect.jpeg">

And This is an example of human tracking.

<img title="Track_Ex" alt="Track_Ex" src="docs/track.jpeg">

In this module, we aim to build a module which when recieves video feed, starts detecting humans in the frame and gives ID to individual instances and tracks them over rest of the frames. These coordinates are then transformed into the robots reference frame and the final output is their (x,y,z) coordinate with respect to the robot reference frame.

## Authors
- [Shailesh Pranav Rajendran](https://github.com/shaileshpranav)
- [Harika Pendli](https://github.com/harika-pendli)

## License 
```
MIT License

Copyright (c) 2022 Shailesh Pranav Rajendran, Harika Pendli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

```

## Links
- [Phase-0 Proposal](https://github.com/shaileshpranav/Human_avoidance/blob/main/Proposal.pdf)

- [Phase-0 Proposal Video](https://drive.google.com/file/d/1JcN-jdWsAfGG5XlVniN_F_-hbOWnSuIF/view?usp=sharing)

- [Product-log](https://docs.google.com/spreadsheets/d/13NfVb0g8LwvVlH9F1EcA1EnQb8gwcYmieM8Q2csQmX0/edit#gid=0)

- [Sprint Review](https://docs.google.com/document/d/1Nb_psVTufyzcFsdD67MJTqQvALrAlez0QEYVcEus4a4/edit)

- [Phase 1 Update Video](https://drive.google.com/file/d/1zdG5oJxihnf690Nj9lmH-NxazA3RiWn2/view?usp=sharing)

## Demo
<img src="output/Result.gif">

## Standard Build via command-line
```
git clone --recursive https://github.com/shaileshpranav/Human_avoidance
cd <path to repository>
mkdir build && cd build
cmake ..
make
```
## Run Test:

    ./test/cpp-test
## Run program:
- For Image
```
./app/app --image=../input/1.png
```
- For video
``` 
./app/app --video=../input/video.mp4
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```

##  Install Dependencies
```
sh dependencies.sh
```
## Plugins
- Google C++ Sytle
```
clang-format -style=Google -i your_file.cpp
```

- Cpplint

```
# You may need to install cpplint:
sudo apt install python3-pip
pip install cpplint

# read the cpplint manual to get an idea of what it does:
~/.local/bin/cpplint -h
#to run on a file:
cpplint "FIlename.cpp"
```

- cppCheck
```
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```
## Running Doxygen
```
sudo apt-install doxywizard
run doxywizard
source it to ENPM808X_Midterm_Manipulator_IKSolver/
run the doxygen
```