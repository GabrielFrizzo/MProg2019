a, b, c = map(float, input().split(' '))
pi = 3.14159

print('TRIANGULO: {:.3f}'.format(a*c/2))
print('CIRCULO: {:.3f}'.format(c**2*pi))
print('TRAPEZIO: {:.3f}'.format((a+b)/2*c))
print('QUADRADO: {:.3f}'.format(b**2))
print('RETANGULO: {:.3f}'.format(a*b))