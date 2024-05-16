.PHONY: build deploy configure

configure:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake .. -DCMAKE_TOOLCHAIN_FILE=./scripts/vcpkg/scripts/buildsystems/vcpkg.cmake -G Ninja

clean: 
	rm -rf build

vcpkg:
	git clone https://github.com/microsoft/vcpkg ./3rdparty/vcpkg
	./3rdparty/vcpkg/bootstrap-vcpkg.sh
	./3rdparty/vcpkg/vcpkg install
