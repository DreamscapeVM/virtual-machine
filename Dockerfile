FROM ubuntu:24.04 AS builder
WORKDIR /work
RUN apt update && \
    apt install clang-17 cmake ninja-build -y && \
    rm -rf /var/lib/apt/lists/*

    
COPY . .

ENV CXX clang++-17
ENV CC clang-17

RUN mkdir build && \ 
    cd build && \
    cmake -G Ninja .. && \
    ninja
