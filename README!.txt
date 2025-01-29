1) LOGIN:
Para el manejo de los 100 usuarios, dentro de la carpeta "Código para generar usuarios"
se encuentra un archivo .cpp llamado “Convertir cpp a bin”.Este código lo utilizamos una vez 
ya creada nuestra lista de usuarios con sus requisitos necesarios en  “Usuarios.txt”,
para convertir el documento de texto al archivo binario “Usuarios.bin” (el cual usamos en el
código general del programa de MiProyecto para manejar el ingreso de usuarios).
Las actualizaciones de la fecha se realizan en el archivo “Usuarios.bin” que se
encuentra con todos los otros documentos del proyecto, pero en el caso de que se quiera
realizar alguna modificación a un usuario (ya sea nombre, apellido, rango o legajo) debería
dirigirse al txt “Usuarios.txt” que se encuentra en la carpeta "Código para generar usuarios",
modificar el documento de texto, luego ejecutar el código de “Convertir cpp a bin.cpp” y
finalmente copiar el nuevo “Usuarios.bin” que se generará en la misma carpeta y reemplazar
el antiguo “Usuarios.bin” que se encontraba en la carpeta principal del programa junto con el
resto de documentos.

2) ESTADÍSTICAS A NIVEL CARACTERES: 
-Frecuencia de caracteres-
Al leer el archivo, guardamos cada uno de los caracteres en un arreglo de frecuencia,
donde la posición corresponde al número del carácter en la tabla ASCII y luego lo ordenamos.
Al mostrarlo, solo lo hacemos con los caracteres que tienen frecuencia mayor a cero, es decir,
los que solo aparecen al menos una vez.

3)ESTADÍSTICAS A NIVEL PALABRAS:
La creación de la lista enlazada es realizada al inicio del programa, para evitar volver 
ejecutar este proceso cada vez que se seleccione la opción de "Estadísticas a nivel palabras".
Para este inciso utilizamos una lista enlazada ya que consideramos que, como en un principio
no contamos con la información de la cantidad de caracteres que posee la palabra más larga,
utilizar estructuras de datos dinámicos sería lo mejor para el manejo de memoria.
-¿Qué consideramos palabras?-
Tomamos inicialmente como palabras al rango de caracteres que se encuentra delimitado
entre espacios(" ").
Leemos una linea completa del libro con la función "leerPalabraLibro()" y luego en la función
"abrirEstadisticasPalabras()" separamos la línea obtenida en palabras mediante
"stringstream ss(cadena);".

En cuanto al item IV), el codigo recibe la lista enlazada generada, pidiendo al usuario que
ingrese el carácter que desea evaluar, y con ese dato realiza una búsqueda lineal nodo a nodo.
Cada vez que encuentra un nodo que contiene una palabra que comienza con el carácter brindado
por el usuario, lo escribe en el archivo, del tipo "archivoX.txt", siendo "X" el carácter
proporcionado por el usuario, en un formato de "Palabra: frecuencia", y escribiendo una
por línea.

