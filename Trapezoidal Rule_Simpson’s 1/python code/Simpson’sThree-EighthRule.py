
import numpy as np

def f(x):
    return 1 / (1 + x**2)

def simpsons_three_eighth(a, b, n):
    if n % 3 != 0:
        raise ValueError("n must be divisible by 3 for Simpson's 3/8 rule")
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return (3 * h / 8) * (y[0] + 3 * np.sum(y[1:-1][(np.arange(1, n) % 3 != 0)]) + 2 * np.sum(y[3:-3:3]) + y[-1])

exact_value = np.pi / 4
for n in [12, 120, 240]:  # multiples of 3
    approx = simpsons_three_eighth(0, 1, n)
    error = abs(exact_value - approx)
    print(f"Simpson's 3/8 Rule (n={n}): Approx = {approx:.10f}, Error = {error:.10f}")
