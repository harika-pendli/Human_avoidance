# Coverage
sudo apt-get install -y -qq lcov

# OpenCV install
sudo apt-get install -y build-essential
sudo apt-get install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install -y python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

# # Download v4.4
sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config
git clone https://github.com/opencv/opencv.git
mkdir -p build && cd build
cmake ../opencv
make -j4
sudo make install

sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
cd ../../