FROM ubuntu:24.04 AS builder
WORKDIR /work
RUN apt update && \
    apt install clang-17 git cmake ninja-build -y
    
RUN apt install -y curl zip unzip tar

RUN git clone https://github.com/microsoft/vcpkg && \
    ./vcpkg/bootstrap-vcpkg.sh
    
COPY . .

ENV CXX clang++-17
ENV CC clang-17

RUN mkdir build && \ 
    cd build && \
    cmake -G Ninja .. && \
    ninja
    
RUN rm -rf /var/lib/apt/lists/*