import numpy as np
import matplotlib.pyplot as plt

def modified_euler(f, y0, t0, t_end, h):
    t_values = np.arange(t0, t_end + h, h)
    y_values = np.zeros(len(t_values))
    y_values[0] = y0
    for i in range(1, len(t_values)):
        t = t_values[i-1]
        y = y_values[i-1]
        y_predict = y + h * f(t, y)
        y_values[i] = y + (h / 2) * (f(t, y) + f(t + h, y_predict))
    return t_values, y_values

def euler(f, y0, t0, t_end, h):
    t_values = np.arange(t0, t_end + h, h)
    y_values = np.zeros(len(t_values))
    y_values[0] = y0
    for i in range(1, len(t_values)):
        t = t_values[i-1]
        y = y_values[i-1]
        y_values[i] = y + h * f(t, y)
    return t_values, y_values

def analytical_solution(t_values):
    # Analytical solution for dy/dx = x^2 - y with y(0) = 1
    C = 4/3  # Initial condition y(0) = 1
    return (t_values**2 - 2*t_values + 2) + C * np.exp(-t_values)

# Predefined initial conditions
y0 = 1
t0 = 0
t_end = 5
h = 0.1

# Define the differential equation dy/dx = x^2 - y
f = lambda t, y: t**2 - y

# Calculate values using Euler's and Modified Euler's methods
t_values_mod_euler, y_values_mod_euler = modified_euler(f, y0, t0, t_end, h)
t_values_euler, y_values_euler = euler(f, y0, t0, t_end, h)
analytical_y_values = analytical_solution(t_values_mod_euler)

# Plotting
plt.plot(t_values_mod_euler, y_values_mod_euler, label="Modified Euler's Method")
plt.plot(t_values_euler, y_values_euler, label="Euler's Method", linestyle='dotted')
plt.plot(t_values_mod_euler, analytical_y_values, label="Analytical Solution", linestyle='dashed')
plt.xlabel('t')
plt.ylabel('y')
plt.legend()
plt.title("Euler's Method vs Modified Euler's Method vs Analytical Solution")
plt.show()
