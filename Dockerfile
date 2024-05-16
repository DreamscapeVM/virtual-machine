FROM ubuntu:24.04 AS builder
WORKDIR /work
RUN apt update && \
    apt install -y clang-17 git cmake ninja-build \
    curl zip unzip tar build-essential pkg-config
    
COPY vcpkg.json vcpkg.json
RUN make vcpkg
COPY . .

ENV CXX clang++-17
ENV CC clang-17

RUN mkdir build && \ 
    cd build && \
    cmake -DCMAKE_TOOLCHAIN_FILE=/work/vcpkg/scripts/buildsystems/vcpkg.cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DSTATIC=ON \
    -DCMAKE_C_COMPILER=${CC} \
    -DCMAKE_CXX_COMPILER=${CXX} \
    -G Ninja .. && \
    ninja

RUN rm -rf /var/lib/apt/lists/*


# For deployment., so To be determine.
# FROM scratch
# LABEL org.opencontainers.image.source=https://github.com/orgs/virtual-machine-created-by-myself
# LABEL org.opencontainers.image.licenses=MIT
# LABEL org.opencontainers.image.authors="JooHyoung Cha"
# # LABEL org.opencontainers.image.description="reproducibility test about p2809r3, by docker and llvm17"

# COPY --from=builder /work/build/virtual-machine /virtual-machine
# CMD [ "/virtual-machine" ]
