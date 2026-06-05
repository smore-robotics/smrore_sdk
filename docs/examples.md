# Examples

The repository includes matching C++ and Python examples.

| Example | C++ | Python | Description |
|---|---|---|---|
| 01 | `examples/01_connect.cpp` | `examples_py/01_connect.py` | Initialize, check connection, shutdown |
| 02 | `examples/02_read_state.cpp` | `examples_py/02_read_state.py` | Read robot state and motor status |
| 03 | `examples/03_movej.cpp` | `examples_py/03_movej.py` | Fixed conservative joint-space motion |
| 04 | `examples/04_movel.cpp` | `examples_py/04_movel.py` | Short Cartesian line motion from current TCP pose |

## C++ Examples

```bash
./scripts/download.sh
./scripts/build.sh
./build/01_connect [robot_ip]
./build/02_read_state [robot_ip]
```

## Python Examples

Install the Python wheel first, then run:

```bash
python examples_py/01_connect.py [robot_ip]
python examples_py/02_read_state.py [robot_ip]
```

## Motion Examples

Before running `03_movej` or `04_movel`, review the target positions in the
source file and confirm they are safe for your setup.

```bash
./build/03_movej [robot_ip]
./build/04_movel [robot_ip]

python examples_py/03_movej.py [robot_ip]
python examples_py/04_movel.py [robot_ip]
```
