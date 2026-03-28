## Python + C++ = bff?

Building the extension:
```shell
uv run cmake -S . -B build
cmake --build build
```

Importing the extension:
```shell
cd build
uv run python -c 'import my_ext; my_ext.add(3, 6)'
```
