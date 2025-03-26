# Implementing the shooting method to solve a boundary value problem
import numpy as np
import matplotlib.pyplot as plt

def f(x, y, dy):
    return x - y - 2 * dy

def rk4_step(x, y, dy, h):
    k1 = h * dy
    l1 = h * f(x, y, dy)
    k2 = h * (dy + 0.5 * l1)
    l2 = h * f(x + 0.5 * h, y + 0.5 * k1, dy + 0.5 * l1)
    k3 = h * (dy + 0.5 * l2)
    l3 = h * f(x + 0.5 * h, y + 0.5 * k2, dy + 0.5 * l2)
    k4 = h * (dy + l3)
    l4 = h * f(x + h, y + k3, dy + l3)
    y_next = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6
    dy_next = dy + (l1 + 2 * l2 + 2 * l3 + l4) / 6
    return y_next, dy_next

def shooting_method(h, m1):
    x = 0
    y = 1
    dy = m1
    x_values = [x]
    y_values = [y]
    
    while x < 2:
        y, dy = rk4_step(x, y, dy, h)
        x += h
        x_values.append(x)
        y_values.append(y)
    
    return x_values, y_values, y

def given_function(x):
    return (1/2) * np.exp(-x) * (6 + 2 * np.exp(x) * (-2 + x) - 3 * x + 3 * np.exp(2) * x)

def print_table(x_values, y_values):
    print("x\t\ty")
    for x, y in zip(x_values, y_values):
        print(f"{x:.4f}\t{y:.4f}")

def interpolate(m1, b1, m2, b2, b):
    return m1 + (m2 - m1) * (b - b1) / (b2 - b1)

def main():
    h = float(input("Enter step size: "))
    m1 = float(input("Enter initial slope (m1): "))
    
    x_values, y_values, y_end = shooting_method(h, m1)
    
    plt.plot(x_values, y_values, label=f'm1 = {m1}')
    print(f'For m1 = {m1}, y(2) = {y_end}')
    print_table(x_values, y_values)
    
    m_values = [m1]
    y_ends = [y_end]
    
    while abs(y_end - 3) > 1e-5:
        m2 = float(input("Enter new slope (m2): "))
        x_values, y_values, y_end = shooting_method(h, m2)
        plt.plot(x_values, y_values, label=f'm2 = {m2}')
        print(f'For m2 = {m2}, y(2) = {y_end}')
        print_table(x_values, y_values)
        
        m_values.append(m2)
        y_ends.append(y_end)
        
        if len(m_values) > 1:
            m1, m2 = m_values[-2], m_values[-1]
            b1, b2 = y_ends[-2], y_ends[-1]
            m3 = interpolate(m1, b1, m2, b2, 3)
            print(f"Interpolated slope (m3) = {m3}")
            m_values.append(m3)
            x_values, y_values, y_end = shooting_method(h, m3)
            plt.plot(x_values, y_values, label=f'm3 = {m3}')
            print(f'For m3 = {m3}, y(2) = {y_end}')
            print_table(x_values, y_values)
            y_ends.append(y_end)
    
    # Plot the given function
    x_real = np.linspace(0, 2, 100)
    y_real = given_function(x_real)
    plt.plot(x_real, y_real, 'b-', label='Given Function', linewidth=2)
    
    # Highlight the point where y = 3
    plt.plot(2, 3, 'ro', label='y=3')
    
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.title('Shooting Method for BVP')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
