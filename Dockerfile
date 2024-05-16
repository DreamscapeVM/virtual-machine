FROM ubuntu:24.04 AS builder
WORKDIR /work
RUN apt update && \
    apt install -y clang-17 git cmake ninja-build \
    curl zip unzip tar build-essential pkg-config
    
RUN apt install -y 


RUN git clone https://github.com/microsoft/vcpkg && \
    ./vcpkg/bootstrap-vcpkg.sh && \
    ./vcpkg/vcpkg install
    
COPY . .

ENV CXX clang++-17
ENV CC clang-17

RUN mkdir build && \ 
    cd build && \
    /work/vcpkg/vcpkg install && \
    cmake -DCMAKE_TOOLCHAIN_FILE=/work/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DCMAKE_C_COMPILER=${CC} \
    -DCMAKE_CXX_COMPILER=${CXX} \
    -G Ninja .. && \
    ninja

RUN rm -rf /var/lib/apt/lists/*
