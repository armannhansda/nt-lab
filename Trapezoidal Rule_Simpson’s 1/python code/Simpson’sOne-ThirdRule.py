# Simpson’s One-Third Rule


import numpy as np

def f(x):
    return 1 / (1 + x**2)


def simpsons_one_third(a, b, n):
    if n % 2 != 0:
        raise ValueError("n must be even for Simpson's 1/3 rule")
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return (h / 3) * (y[0] + 4 * np.sum(y[1:-1:2]) + 2 * np.sum(y[2:-2:2]) + y[-1])


exact_value = np.pi / 4
for n in [10, 100, 200]:
    approx = simpsons_one_third(0, 1, n)
    error = abs(exact_value - approx)
    print(f"Simpson's 1/3 Rule (n={n}): Approx = {approx:.10f}, Error = {error:.10f}")
