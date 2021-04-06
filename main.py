import os
from sympy import plot_implicit, symbols, Eq
# Instead 'Stars' write your path to exe. file
os.system("C:/Users/Lydsyf/PycharmProjects/Mini-Project/bin/Debug/Stars.exe")
with open("data.txt", 'r') as f:
    data = f.readlines()
    a = [float(i) for i in data[0].split()]
x, y = symbols('x y')
p = plot_implicit(Eq(a[0] * x**2 + a[1]*x*y + a[2] * y**2 + a[3] * x + a[4] * y + a[5], 0),
              x_var=(x, -100, 100), y_var=(y, -100, 100), show=False, title='Minimum area ellipse')
for i in range(len(data)-1):
    a = [float(i) for i in data[i+1].split()]
    p1 = plot_implicit((x - a[0])**2 + (y - a[1])**2 <= 1,
                       x_var=(x, -100, 100), y_var=(y, -100, 100), show=False, line_color='red')
    p.append(p1[0])
p.show()