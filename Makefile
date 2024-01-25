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

.PHONY: all
all: configure-build-test
