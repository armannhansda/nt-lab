# Trapezoidal Rule

import numpy as np

def f(x):
    return 1 / (1 + x**2)

def trapezoidal_rule(a, b, n):
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return (h / 2) * (y[0] + 2 * np.sum(y[1:-1]) + y[-1])

exact_value = np.pi / 4
for n in [10, 100, 200]:
    approx = trapezoidal_rule(0, 1, n)
    error = abs(exact_value - approx)
    print(f"Trapezoidal Rule (n={n}): Approx = {approx:.10f}, Error = {error:.10f}")
