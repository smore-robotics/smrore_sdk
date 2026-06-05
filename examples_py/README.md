# Python Examples

Python examples will be added later and will mirror the C++ examples:

| Example | C++ counterpart |
|---------|-----------------|
| `01_connect.py` | `01_connect.cpp` |
| `02_read_state.py` | `02_read_state.cpp` |
| `03_movej.py` | `03_movej.cpp` |
| `04_movel.py` | `04_movel.cpp` |

For now, download the Python wheel from the GitHub Release and verify the
runtime SDK version:

```bash
VERSION=0.0.1
gh release download v${VERSION} \
  --repo smore-robotics/smrore_sdk \
  --pattern "rcore_sdk_py-${VERSION}-*.whl" \
  --dir .
pip install rcore_sdk_py-${VERSION}-*.whl
python -c "import rcore_sdk; from rcore_sdk import _native; print(_native.linked_sdk())"
```
