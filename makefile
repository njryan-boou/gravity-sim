BUILD_DIR ?= build
TARGET ?= gravity_sim
BUILD_TYPE ?= Debug
PYTHON ?= python3

.PHONY: all help configure build run plot full clean clean-data rebuild

all: build

help:
	@echo "Available targets:"
	@echo "  build       Configure and compile the simulator"
	@echo "  run         Generate data/field.csv"
	@echo "  plot        Display the generated field"
	@echo "  full        Run simulation and plot results"
	@echo "  clean       Remove build artifacts"
	@echo "  clean-data  Remove generated simulation data"
	@echo "  rebuild     Clean and build from scratch"

configure:
	cmake -S . -B $(BUILD_DIR) \
	    -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/$(TARGET)

plot:
	$(PYTHON) scripts/plot.py

full: run plot

clean:
	rm -rf $(BUILD_DIR)

clean-data:
	rm -f data/field.csv

rebuild: clean build