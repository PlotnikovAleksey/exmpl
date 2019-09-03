sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq

sudo apt-get install -qq g++-5
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 90
CMAKE_VERSION=3.3.2
CMAKE_VERSION_DIR=v3.3

CMAKE_OS=Linux-x86_64
CMAKE_TAR=cmake--.tar.gz
CMAKE_URL=http://www.cmake.org/files//
CMAKE_DIR=/home/fbdn/PlotnikovAleksey/workspace/my_example/ci/travis/cmake-

wget --quiet 
mkdir -p 
tar --strip-components=1 -xzf  -C 
export PATH=/bin:/home/fbdn/.rvm/gems/ruby-2.4.6@travis/bin:/home/fbdn/.rvm/gems/ruby-2.4.6@global/bin:/home/fbdn/.rvm/rubies/ruby-2.4.6/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/fbdn/PlotnikovAleksey/workspace/node/bin:/home/fbdn/.rvm/bin
