BUILD_DIR = build
TARGET = gravity_sim

.PHONY: all configure build run clean rebuild

all: build

configure:
	cmake -S . -B $(BUILD_DIR)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
plot:
	python scripts/plot.py

rebuild: clean build