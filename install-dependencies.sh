# Enter temporary directory
mkdir .temporary
cd .temporary

# Install make, cmake, git, python3, pip and build-essential
sudo apt -y install make
sudo apt -y install cmake
sudo apt -y install git
sudo apt -y install python3
sudo apt -y install python3-pip
sudo apt -y install build-essential

# Install termcolor library
sudo pip3 install termcolor

# Install google benchmark for benchmarking support
# Script provided by the google benchmark documentation
git clone https://github.com/google/benchmark.git
cd benchmark
cmake -E make_directory "build"
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release ../
cmake --build "build" --config Release
cmake -E chdir "build" ctest --build-config Release
sudo cmake --build "build" --config Release --target install
cd ..

# Install google test for testing support
# Script provided by the google test documentation
git clone https://github.com/google/googletest.git -b release-1.11.0
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
cd ..
cd ..

# Clean up folders
cd ..
sudo rm -rf .temporary
