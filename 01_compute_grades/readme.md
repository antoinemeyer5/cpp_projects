# Compute grades

Add a text file like:
```txt
[SUBJECT_1] [COEFFICIENT_1] [GRADE_1]
[SUBJECT_2] [COEFFICIENT_2] [GRADE_2]
[...]
[SUBJECT_N] [COEFFICIENT_N] [GRADE_N]
```

Or just modify `example.txt`.

How to compile:
```bash
01_compute_grades % mkdir build && cd build
build % cmake ..
build % make
build % ./compute_grades /path/to/[file or example].txt
```
