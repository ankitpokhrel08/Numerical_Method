import numpy as np
import matplotlib.pyplot as plt

def f(t, y):
    return -2 * t * y  # Example differential equation

def real_solution(t):
    return np.exp(-t**2)  # Real solution for the example differential equation

def rk1(f, t0, y0, h, n):
    t = np.linspace(t0, t0 + n*h, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        y[i+1] = y[i] + h * f(t[i], y[i])
    return t, y

def rk2(f, t0, y0, h, n):
    t = np.linspace(t0, t0 + n*h, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        k1 = h * f(t[i], y[i])
        k2 = h * f(t[i] + h/2, y[i] + k1/2)
        y[i+1] = y[i] + k2
    return t, y

def rk3(f, t0, y0, h, n):
    t = np.linspace(t0, t0 + n*h, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        k1 = h * f(t[i], y[i])
        k2 = h * f(t[i] + h/2, y[i] + k1/2)
        k3 = h * f(t[i] + h, y[i] - k1 + 2*k2)
        y[i+1] = y[i] + (k1 + 4*k2 + k3) / 6
    return t, y

def rk4(f, t0, y0, h, n):
    t = np.linspace(t0, t0 + n*h, n+1)
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        k1 = h * f(t[i], y[i])
        k2 = h * f(t[i] + h/2, y[i] + k1/2)
        k3 = h * f(t[i] + h/2, y[i] + k2/2)
        k4 = h * f(t[i] + h, y[i] + k3)
        y[i+1] = y[i] + (k1 + 2*k2 + 2*k3 + k4) / 6
    return t, y

def plot_results(t, y, real_t, real_y, title):
    plt.figure()
    plt.plot(t, y, label='Numerical Solution')
    plt.plot(real_t, real_y, label='Real Solution', linestyle='dashed')
    plt.title(title)
    plt.xlabel('t')
    plt.ylabel('y')
    plt.legend()
    plt.grid(True)
    plt.show()

def plot_all_results(t_rk1, y_rk1, t_rk2, y_rk2, t_rk3, y_rk3, t_rk4, y_rk4, real_t, real_y, t_min=0, t_max=2):
    plt.figure()
    plt.plot(t_rk1, y_rk1, label='RK1 Method')
    plt.plot(t_rk2, y_rk2, label='RK2 Method')
    plt.plot(t_rk3, y_rk3, label='RK3 Method')
    plt.plot(t_rk4, y_rk4, label='RK4 Method')
    plt.plot(real_t, real_y, label='Real Solution', linestyle='dashed')
    plt.title('Runge-Kutta Methods vs Real Solution')
    plt.xlabel('t')
    plt.ylabel('y')
    plt.legend()
    plt.grid(True)
    plt.xlim(t_min, t_max)
    plt.show()

# Parameters
t0 = 0
y0 = 1
h = 0.1
n = 100

# Real solution
real_t = np.linspace(t0, t0 + n*h, n+1)
real_y = real_solution(real_t)

# RK1
t_rk1, y_rk1 = rk1(f, t0, y0, h, n)

# RK2
t_rk2, y_rk2 = rk2(f, t0, y0, h, n)

# RK3
t_rk3, y_rk3 = rk3(f, t0, y0, h, n)

# RK4
t_rk4, y_rk4 = rk4(f, t0, y0, h, n)

# Plot all results in the same graph with zoom
plot_all_results(t_rk1, y_rk1, t_rk2, y_rk2, t_rk3, y_rk3, t_rk4, y_rk4, real_t, real_y, t_min=0, t_max=2)
