# 📊 Numerical Methods Implementation

A comprehensive collection of numerical methods implemented in C and Python for solving mathematical problems.

## 📚 Topics Covered

### 🔢 Differentiation

- **Newton's Forward Difference Method**: Approximates derivatives using forward differences
- **Newton's Backward Difference Method**: Approximates derivatives using backward differences
- **Minima-Maxima Finder**: Locates critical points using numerical differentiation

### ∫ Integration

- **Trapezoidal Rule**: Approximates definite integrals using linear interpolation
- **Simpson's 1/3 Rule**: Uses quadratic polynomials for approximation
- **Simpson's 3/8 Rule**: Higher-order approximation using cubic polynomials
- **Romberg Integration**: Accelerates convergence using Richardson extrapolation
- **Gaussian Quadrature**: Optimizes sample points for higher accuracy
  - 2-Point Formula
  - 3-Point Formula

### 📈 Non-linear Equations

- **Newton-Raphson Method**: Fast quadratic convergence using derivatives
- **Secant Method**: Similar to Newton's method but avoids derivative calculation
- **Fixed Point Iteration**: Simple iteration using function rearrangement
- **Regula Falsi (False Position)**: Combines bisection and secant methods
- **Polynomial Curve Fitting**: Fits polynomial curves to data points (Python)

### 📉 Linear Equations

- **Jacobi Method**: Iterative technique for solving linear systems
- **Gauss-Seidel Method**: Improved convergence over Jacobi method

## 🚀 Usage

### C Programs

Compile and run using:

```bash
gcc filename.c -o filename -lm
./filename
```

### Python Programs

Run using:

```bash
python filename.py
```

## 📝 Implementation Details

Each program includes:

- Detailed algorithm descriptions
- Step-by-step calculation process
- Error analysis (where applicable)
- User-friendly input interfaces

## 🔍 Key Concepts

- **Approximation Techniques**: Numerical solutions for problems lacking analytical solutions
- **Error Analysis**: Measuring the accuracy of numerical approximations
- **Convergence**: Ensuring methods approach the correct solution
- **Stability**: Preventing error amplification in iterative methods
