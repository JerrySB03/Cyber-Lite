#!/bin/bash

rm -rf tmp

mkdir tmp
cd tmp

##########################################################
## install oatpp

if [ ! -d /usr/local/include/oatpp-*/oatpp ]
then
    echo "Downloading oatpp"
    git clone --depth=1 https://github.com/oatpp/oatpp

    cd oatpp
    mkdir build
    cd build

    cmake ..
    sudo make install

    cd ../../
fi

##########################################################
## install oatpp-sqlite

if [ ! -d /usr/local/include/oatpp-*/oatpp-sqlite ]
then
    echo "Downloading oatpp-sqlite"
    git clone --depth=1 https://github.com/oatpp/oatpp-sqlite

    cd oatpp-sqlite
    mkdir build
    cd build

    cmake ..
    sudo make install

    cd ../../
fi

##########################################################
## install oatpp-swagger

if [ ! -d /usr/local/include/oatpp-*/oatpp-swagger ]
then
    echo "Downloading oatpp-swagger"
    git clone --depth=1 https://github.com/oatpp/oatpp-swagger

    cd oatpp-swagger
    mkdir build
    cd build

    cmake ..
    sudo make install

    cd ../../
fi

##########################################################
## install oatpp-zlib

if [ ! -d /usr/local/include/oatpp-*/oatpp-zlib ]
then
    echo "Downloading oatpp-zlib"
    git clone --depth=1 https://github.com/oatpp/oatpp-zlib

    cd oatpp-zlib
    mkdir build
    cd build

    cmake ..
    sudo make install

    cd ../../
fi

##########################################################
cd ../

rm -rf tmp