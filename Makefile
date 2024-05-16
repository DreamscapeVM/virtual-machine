.PHONY: build deploy configure

build:
	if ! [ -d "build" ]; then \
		mkdir build; \
	fi

	cd build && \
		cmake .. && \
		ninja -j$(shell sysctl -n hw.physicalcpu)

clean: 
	rm -rf build
