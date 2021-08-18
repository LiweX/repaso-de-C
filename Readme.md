## Laboratorio N2
# Repaso Lenguaje C
### SOI - FCEFyN - UNC

## Respuestas

### Strings y arreglos
Las primeras consignas practicas se resolvieron en modulos separados para practicar el linkeo de objetos y refrescar el uso de makefile.
Para ejecutar el programa se debe clonar el repositorio o descargarlo, abrir una terminal en esa carpeta y usar estos comandos:
 ```
make
./tp2
 ```
El programa primero imprime la informacion solicitada de `/proc/meminfo`, luego continua mostrando la info requerida de `/proc/cpuinfo`, y por ultimo se enlistan las palabras en mayusculas de  `/proc/version` contenidas en un arreglo dinamico.
### ¿Cómo utilizar typedef junto a struct? ¿Para qué sirve? Ejemplo.
```
typedef struct{     //asi se declara un nuevo tipo de dato desde una estructura
    int a;          //se pueden agregar todos los tipos de datos que sean necesarios
    char b;     
}Dato               //este seria el nombre del nuevo tipo de dato
```

Permite generar tipos nuevos a conveniencia, algo asi como objetos en java pero sin metodos.
Por ejemplo:
```
typedef struct{
    char nombre[30];
    int edad;
    long dni;
    float altura;
}Persona   
```
Aqui se define un tipo de dato "Persona" que almacena el nombre, edad, dni y altura de la persona en cuestion.

### ¿Qué es packing and padding?

El packing en estructuras permite que los datos se guarden de manera contigua en memoria lo que produce que se desperdicien ciclos de reloj.
Esto es asi porque, segun la arquitectura del del CPU, los datos se leen por tamaño de palabra: 4 bytes en 32bits y 8 bytes en 64bits
Entonces, partiendo de la siguiente estructura:
```
typedef struct{
    char a;
    char b;
    int c;
}dato;
```
Si mi procesador es de 32 bits, los 2 chars entran en una palabra de 4bytes, pero el int no; quedara mitad del int en 2bytes de la palabra y la otra mitad en 2 bytes de la siguente.
Esto causa que al procesador le lleve un ciclo de reloj extra para poder leer correctamente el entero.
En cambio, el padding en extructuras permite que no se desperdicien ciclos de reloj, pero a cambio se desperdicia memoria.
El padding en estructuras se da de la siguiente manera:
Volviendo al ejemplo anterior, los dos chars siguen entrando en una palabra de 32bits, pero para el entero se dejaran 2 bytes vacios de la primera palabra para colocarlo en la siguiente.
Se estan desperdiciando 2 bytes y el tamaño de la estructura es mas grande: 8 bytes contra los 6 bytes si se optara por el packing de la misma estructura.
Inlcuso esto empeora si se cambia el orden de los tipos en la estructura:
```
typedef struct{
    char a;
    int b;
    char c;
}Dato;
```
Ahora el tamaño de esta estructura es de 12 bytes ya que el entero sigue sin poder entrar en una sola palabra y ademas se ocupa una palabra extra para guardar el ultimo char.

## Preguntas del codigo
### Explique a que se debe los tamaños de cada una de las estructuras
![alt text](https://github.com/ICOMP-UNC/laboratorio-2-LiweX/blob/master/Structre%20sizes.png)

### Explique por que la expresion que calcula  limit y limit_aux generan el mismo resutado
`char *limit = ((char *) &data + sizeof(BaseData));`

Aqui se realiza un desplazamiento en una determinada cantidad de bytes. En este caso se corre tantos bytes como el tamaño de BaseData

`char *limit_aux =(char *) (&data + 1);`

Aqui usando aritmetica de punteros el desplazamiento es hacia un "BaseData" mas adelante. Dan el mismo resultado por que en ambos casos me muevo la misma cantidad de bytes

### Explique los valores que se muestran en pantalla en cada iteracion del for
![alt text](https://github.com/ICOMP-UNC/laboratorio-2-LiweX/blob/master/data%20size.png)
