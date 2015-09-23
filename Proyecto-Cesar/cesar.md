#INTRODUCCIÓN
La encriptación es el proceso de ofuscar información para
que sin un conocimiento particular la misma se torne ilegible.
Durante siglos, la gente ha desarrollado esqumas de cifrado de
mensajes (algunos mejores que otros), pero la llegada de las computadoras
y el internet revolucionaron el campo. En estos días, es difícil
no encontrar algún tipo de cifrado, por ejemplo: si usted está comprando
algo en línea, o bien loguéandose en un sistema informático. La encriptación
le permite compartir información con otras personas de confianza sin termores.

Un "cipher" es un algoritmo para llevar a cabo el cifrado (y la inversa,
descifrado). La información original se llama "plaintext". Luego que
éste último es cifrado, se lo denomina "ciphertext". El "ciphertext" contiene
toda la información del "plaintext", pero no es un formato legible por un
humano o un ordenador sin el mecanismo adecuado para descifrarlo.

Un "cipher" por lo general depende de una pieza de información adicional llamada
clave. La clave se incorpora en el proceso de cifrado; el "plaintext" cifrado
con dos claves diferentes debería mostrar dos "ciphertext" distintos. Sin la
clave, debería ser difícil de descifrar el texto resultante.

El desarrollo del proyecto consistirá en la implementación de un conocido
(aunque no muy seguro) método de encriptación: el cifrado César. Usted deberá
ser capaz de elaborar sus propios algoritmos para llevar a cabo el cifrado
y descifrado de texto plano.

#El cifrado césar
La idea básica consite en tomar un número entero para la *clave*, y
alterar cada letra del mensaje de acuerdo a la *clave*. Por ejemplo,
si tu mensaje es "feliz" y tu *clave* es 3, la "f" se convierte en "i",
la "e" se convierte en "h", y así sucesivamente. El siguiente sería un
alfabeto alterado tres posiciones a la derecha:

```Original:  a b c d e f g h i j k l m n o p q r s t u v w x y z```

```3-shift:   d e f g h i j k l m n o p q r s t u v w x y z a b c```

Utilizando lo anterior, el mensaje "feliz" se convierte en "iholc".

Para aprender más sobre cifrado César, visite el siguiente [artículo][1].

[1]:(https://en.wikipedia.org/wiki/Caesar_cipher)


##Encriptación (HINTS)
1. Letras en mayúsculas y minúsculas: Trate de incluir ambos casos teniendo
en cuenta que el caracter alterado en minúcula sea exactamente igual al correspondiente en mayúscula. Puede utilizar lo siguiente:

```
>>> import string
>>> print string.ascii_lowercase
abcdefghijklmnopqrstuvwxyz
>>> print string.ascii_uppercase
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

2. Caracteres a ignorar: Caracteres tales como caracteres, comas, puntos,
signos de exclamación, letras acentuadas, etc no serán encriptados por el *cipher*. Un ejemplo de aquellos que no serán utilizados son:

```
string.puntuation
'  '
string.digits
```

3. Podría comenzar con la encriptación de un alfabeto completo utilizando diccionarios:

```
construirCodificador(3) #retornaria lo siguiente:
{'A': 'D', 'C': 'F', 'B': 'E', 'E': 'H', 'D': 'G', 'G': 'J', 'F': 'I', 'I': 'L', 'H': 'K', 'K': 'N', 'J': 'M', 'M': 'P', 'L': 'O', 'O': 'R', 'N': 'Q', 'Q': 'T', 'P': 'S', 'S': 'V', 'R': 'U', 'U': 'X', 'T': 'W', 'W': 'Z', 'V': 'Y', 'Y': 'B', 'X': 'A', 'Z': 'C', 'a': 'd', 'c': 'f', 'b': 'e', 'e': 'h', 'd': 'g', 'g': 'j', 'f': 'i', 'i': 'l', 'h': 'k', 'k': 'n', 'j': 'm', 'm': 'p', 'l': 'o', 'o': 'r', 'n': 'q', 'q': 't', 'p': 's', 's': 'v', 'r': 'u', 'u': 'x', 't': 'w', 'w': 'z', 'v': 'y', 'y': 'b', 'x': 'a', 'z': 'c'}
```

4. Desarrolle un módulo para aplicar el método anterior. Ejemplo:

```
aplicarCodificador("Hola Mundo!", construircodificador(3))
'Krod Pxqgr!'

aplicarcodificador("Krod Pxqgr!", construircodificador(23))
'Hola Mundo!'
```

##DESENCRIPTADO (HINTS)
Suponga que un amigo le envía un correo con el texto cifrado. Si usted conoce cual es la `key`, desencriptar el mensaje es una tarea sencilla. Si el mensaje está encriptado con `k` entonces bastará `aplicarCodificador(mensaje, 26 - k)` y obtendrá el mensaje.
El problema es que usted no conoce la `key`. Pero la buena noticia es que su compañero habla español. Entonces si es capaz de escribir un programa para encontrar la decodificación que produce el máximo número de palabras en español reales, probablemente encontrará la decodificación correcta (hay una posibilidad de que la clave no sea única).

1) Trate de implementar el siguiente pseudocódigo:

```
1- Setear el número máximo de palabras reales encontradas en 0
2- Setear el mejor_corrimiento en 0
3- Para cada corrimiento posible entre 0 y 26:
    4- Correr el texto entero por el corrimiento
    5- Dividir el texto en una lista de palabras
    6- Contar el número de palaras válidas en la lista
    7- Si el número de palabras en más grande que el número de palabras
reales encontradas entonces:
        8- Guardar el número de palabras válidas
        9- Setear el mejor_corrimiento al corrimiento actual
    10- Incrementar el corrimiento posible en 1. Volver al paso 3
11- Retornar el mejor_corrimiento
```

El algoritmo anterior encuentra la mejor *clave* de corrimiento que puede desencriptar el texto.

2) Puede utilizar lo siguiente para saber si la palabra es válida:

```python
def esPalabra(lista_palabras, palabra):
    """
    Determina si una palabra es valida

    lista_palabras: lista de las palabras en el diccionario.
    palabras: una posible palabra.
    retorna Verdadero si la palabra está en la lista.

    Ejemplo:
    >>> esPalabra(lista_palabras, 'hola') retorna
    True
    >>> esPalabra(lista_palabras, 'asdf') retorna
    False
    """
    palabra = palabra.lower()
    palabra = palabra.strip(" !@#$%^&*()-_+={}[]|\\:;'<>?,./\"")
    return palabra in lista_palabras
```
