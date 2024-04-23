# Compute grades

Add a text file like:
```txt
[SUBJECT_1] [COEFFICIENT_1] [GRADE_1]
[SUBJECT_2] [COEFFICIENT_2] [GRADE_2]
[...]
[SUBJECT_N] [COEFFICIENT_N] [GRADE_N]
```

Or just modify `example.txt`.

How to:
```bash
# compile
01_compute_grades % cmake -S . -B build
01_compute_grades % cmake --build build

# execute
01_compute_grades % cd build
build % ./compute_grades /path/to/[file or example].txt

# tests
01_compute_grades % cd build
build % ctest
```
