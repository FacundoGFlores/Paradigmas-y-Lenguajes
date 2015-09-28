#!/usr/bin/env python

"""Poligonos.py: Un ejemplo sobre clases en Python."""

__author__      = "Flores Facundo"
__email__       = "flores.facundogabriel@exa.unsa.edu.ar"
__status__      = "Prototype"

import math
from random import randint

class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distancia(self, p2):
        return math.sqrt((self.x - p2.x) ** 2 + (self.y - p2.y) ** 2)

    def __str__(self):
        return '(' + str(self.x) + ', ' +str(self.y) + ')'

class Poligono:
    def __init__(self):
        self.vertices = []

    def add_punto(self, punto):
        self.vertices.append((punto))

    def get_perimetro(self):
        perimetro = 0
        puntos = self.vertices + [self.vertices[0]]
        for i in range(len(self.vertices)):
          perimetro += puntos[i].distancia(puntos[i + 1])
        return perimetro

class Triangulo(Poligono):
    def __init__(self, p1, p2 , p3):
        Poligono.__init__(self)
        self.add_punto(p1)
        self.add_punto(p2)
        self.add_punto(p3)

    def random_triangulo(self):
        for i in range(3):
            self.add_punto(randint(0,9), randint(0,9))

    def __str__(self):
        puntos = []
        for v in self.vertices:
            puntos.append(str(v))
        return str(puntos)


def main():
    p1 = Punto(0,0)
    p2 = Punto(1,1)
    p3 = Punto(2,0)
    triangulo = Triangulo(p1, p2, p3)
    print triangulo
    print triangulo.get_perimetro()

if __name__ == '__main__':
    main()
