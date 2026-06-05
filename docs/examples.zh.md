# 示例

仓库包含一组对应的 C++ 和 Python 示例。

| 示例 | C++ | Python | 说明 |
|---|---|---|---|
| 01 | `examples/01_connect.cpp` | `examples_py/01_connect.py` | 初始化、检查连接、关闭 |
| 02 | `examples/02_read_state.cpp` | `examples_py/02_read_state.py` | 读取机器人状态和电机状态 |
| 03 | `examples/03_movej.cpp` | `examples_py/03_movej.py` | 固定保守关节点的关节空间运动 |
| 04 | `examples/04_movel.cpp` | `examples_py/04_movel.py` | 从当前 TCP 位姿出发的短距离笛卡尔直线运动 |

## C++ 示例

```bash
./scripts/download.sh
./scripts/build.sh
./build/01_connect [robot_ip]
./build/02_read_state [robot_ip]
```

## Python 示例

先安装 Python wheel，然后运行：

```bash
python examples_py/01_connect.py [robot_ip]
python examples_py/02_read_state.py [robot_ip]
```

## 运动示例

运行 `03_movej` 或 `04_movel` 前，请先检查源文件中的目标点，确认其对当前
设备安全。

```bash
./build/03_movej [robot_ip]
./build/04_movel [robot_ip]

python examples_py/03_movej.py [robot_ip]
python examples_py/04_movel.py [robot_ip]
```
