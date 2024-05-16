.PHONY: build deploy configure

configure:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake .. -DCMAKE_TOOLCHAIN_FILE=./scripts/vcpkg/scripts/buildsystems/vcpkg.cmake -G Ninja

clean: 
	rm -rf build
