.PHONY: configure
configure:
	cmake -S . -B build

.PHONY: build
build:
	cmake --build build

.PHONY: test
test:
	ctest --test-dir build --output-on-failure

.PHONY: configure-build-test
configure-build-test: configure build test

.PHONY: clean
clean:
	rm -rf build

.PHONY: all
all: configure-build-test

.PHONY: run
run:
	@if [ ! -f ./build/Thermo ]; then \
		make configure build; \
	fi
	./build/Thermo

.PHONY: build-run
build-run: build run
