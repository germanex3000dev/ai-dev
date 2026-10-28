# basic single-neuron training

Two small C++ programs that train the same single neuron (linear regression
with gradient descent) from scratch.

> These codes are **NOT** AI models. They're just training one, singular neuron.

## What it does

Both programs start with `weight = 0` and `bias = 0`, then iterate over the
training data

| input `x` | expected `y` |
|-----------|--------------|
| 1         | 3            |
| 2         | 5            |
| 3         | 7            |
| 4         | 9            |
| 5         | 11           |

i.e. the target relationship is **y = 2x + 1**. Each epoch applies gradient
descent on the squared-error loss and prints the weight, bias, and MSE until
the MSE drops below `0.001` or `10000` epochs elapse.

## Files

| File | Purpose |
|------|---------|
| `001_basicNL.cpp` | The basic program: trains the neuron and prints epoch progress. |
| `basicNL_test.cpp` | Same training loop, then prompts you for a test input and prints the neuron's prediction. |

## Build & run

No build system is required — just compile with any C++ compiler:

```bash
g++ -O2 001_basicNL.cpp -o basicNL
./basicNL
```

```bash
g++ -O2 basicNL_test.cpp -o basicNL_test
./basicNL_test
```

This repo also includes a [Nix flake](flake.nix) (`flake.nix` / `flake.lock`)
that provides a dev shell with `gcc`, `cmake`, `ninja`, `gdb`, and
`clang-tools`. Enter it with:

```bash
nix develop
```

## What you should see

The weight converges toward `2.0` and the bias toward `1.0`. In `basicNL_test.cpp`
you can then type a number (e.g. `10`) and see the predicted output (roughly `21`).
