# smrcore_sdk

`smrcore_sdk` is the public documentation and integration repository for the
Smartmore Robot SDK. It provides release download instructions, C++ and Python
examples, compatibility notes, and generated C++ API reference.

The repository does not contain SDK source code. Users download versioned SDK
assets from GitHub Releases and build their applications against those assets.

## Start Here

- [Install](install.md)
- [Usage](usage.md)
- [Examples](examples.md)
- [Support](support.md)
- [API Reference](api/index.md)

## Quick Start

```bash
git clone https://github.com/smore-robotics/smrore_sdk.git
cd smrore_sdk

./scripts/download.sh
./scripts/build.sh

./build/01_connect [robot_ip]
./build/02_read_state [robot_ip]
```

Omit `robot_ip` for local simulation. Motion examples are also available, but
review their targets before running:

```bash
./build/03_movej [robot_ip]
./build/04_movel [robot_ip]
```

## What This Repository Provides

- C++ SDK release archives for supported platforms.
- Python wheels for supported Python and platform tags.
- C++ examples in `examples/`.
- Python examples in `examples_py/`.
- Scripts for downloading the latest C++ SDK and building examples.
- API reference generated from the C++ SDK headers.

## Safety Notice

Robots are hazardous machines. Before running any motion example or user
application, verify the target is safe for your robot, tool, payload, and
workspace. Confirm emergency stop is reachable and the workspace is clear.
