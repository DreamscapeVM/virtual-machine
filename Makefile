.PHONY: build deploy configure

configure:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake -DCMAKE_TOOLCHAIN_FILE=../3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake \
				-DUSE_GTEST=ON \
				-DCMAKE_C_COMPILER=clang \
				-DCMAKE_CXX_COMPILER=clang++ \
				-DCMAKE_BUILD_TYPE=Debug \
				-GNinja .. 

clean: 
	rm -rf build

vcpkg:
	git clone https://github.com/microsoft/vcpkg ./3rdparty/vcpkg
	./3rdparty/vcpkg/bootstrap-vcpkg.sh
	./3rdparty/vcpkg/vcpkg install

test:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake -DCMAKE_TOOLCHAIN_FILE=../3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DCMAKE_BUILD_TYPE=Release \
		-DUSE_GTEST=ON \
		-GNinja .. && \
		ninja && \
		ninja test
