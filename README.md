# Gravity Simulator

A C++20 simulator that calculates the gravitational field and potential of several point masses on a 2D grid, then plots the results.

## Requirements

- CMake and a C++20 compiler
- Make
- Python 3 with pandas, NumPy, and Matplotlib

Install the Python packages with:

```sh
python3 -m pip install pandas numpy matplotlib
```

## Run

From the project directory:

```sh
make full
```

This builds and runs the simulator, writes the grid to `data/field.csv`, and saves the plot to `data/gravity_field.png`.

Use `make build` to build only, `make run` to generate the CSV, or `make plot` to regenerate the plot from the existing CSV.
