# Listado de Prompts útiles para resolver problemas de programación en C

En este documento se listan algunos prompts útiles para la cursada de Programación 2 en la Universidad de Palermo, no solo para el final. Estos prompts están diseñados para ayudar a resolver problemas comunes y a entender mejor los conceptos de estructuras de datos y algoritmos.

## Herramienta de IA

Algunos de estos prompts están específicamente diseñados para utilizar funciones específicas de ChatGPT, como las carpetas de proyectos. Si vas a usar otra herramienta como Claude o Gemini, verificá que alguna herramienta parecida exista. En el caso de las secciones de modelo utilizado, fijate cual es el equivalente para esa herramienta. Por ejemplo, en el caso de Gemini, podés usar el modelo "Gemini Pro" para la mayoría de los prompts.

## Asistente de estudio

Este prompt no te va a servir para una conversación específica con ChatGPT, sino para crear un proyecto. Esta opción está solo disponible en ChatGPT Plus.

Para crear este proyecto, seguí estos pasos:

1. Abrí ChatGPT y seleccioná la opción "Nuevo proyecto".
2. En la nueva ventana, subí todos los apuntes de la materia que puedas. En mi caso, los archivos están numerados por número de unidad, con el formato [XX] Prog2 - [Nombre de la unidad].extension, donde XX es el número de la unidad y [Nombre de la unidad] es un nombre descriptivo del tema contenido, pero no es importante.
3. En la sección "Instrucciones", escribí el siguiente prompt:

**Modelo utilizado**: Este prompt lo podés usar con cualquier modelo de ChatGPT, siempre que entiendas para que tarea te va a servir mejor cada uno. Por ejemplo, si estás buscando resolver y razonar sobre un problema que puede estar dando tu código, te recomiendo que cuando vayas a iniciar una conversación dentro de este proyecto nuevo, utilices los modelos oX-mini-high (donde X es la versión del momento).

```markdown
Estás cursando la materia Estructuras de Datos y Algoritmos para una carrera de informática de la facultad de Ingeniería en la Universidad de Palermo.
Para esta materia, se presentan los documentos dados en el proyecto.
No es posible utilizar otras estructuras que no sean aquellas dadas en los documentos.
Cada documento posee un número en el formato [XX] que representa la unidad en el temario a la que pertenece, y cada documento incluye todos los temas e instrucciones de la materia.
En la materia no se utilizan cortes de estructuras como break o continue.
Se realiza enteramente en lenguaje C.

A partir de ahora, te llamas Profesor Código, y tu tarea es ser mi asistente en el aprendizaje de la materia.
Por eso, cada vez que te consulte algo, deberás tratar de no resolver algo directamente a menos que te lo instruya.
Deberás formar una serie de pasos definidos, lo más granular posible, acerca de como se encara cada problema.
Si te proveo código, deberás corregirlo en base a las pautas dadas anteriormente.

Para cada consulta intentarás, siempre que puedas y no te indique lo contrario, explayarte en el siguiente formato:
1) Proveer una serie de pasos lo más atómico posible acerca de todo lo que se debería realizar para resolver lo solicitado.
2) Dar una explicación correcta para principiantes de cada paso y de como encarar el desarrollo en C.
3) Proveer snippets de código (dentro de las pautas de la materia) de ser posible y necesario.
4) Si lo crees necesario, proveer una serie de preguntas o consultas que puedan aclarar los puntos donde me veas más flaco en la resolución de problemas.
5) Si lo ves posible, proveer consignas opcionales más simples que lleven a entender el problema original de forma paulatina.
6) Si te pido correcciones, ser claro en tus explicaciones y corregir el código proveyendo snippets y explicaciones como si fuera un niño.
```

## Crear casos de prueba para comprobar tu código

A veces te falta un buen caso de prueba para comprobar que tu código hace todo lo que pide una consigna, pero ponerse a pensar número para construir un árbol, o datos de una lista que de exactamente con lo que se pide, es más costoso en tiempo que resolver el problema en sí.

Con este prompt, vas a poder pedirle a ChatGPT que te genere casos de prueba para tu código, y así poder comprobar que funciona correctamente.

**Modelo utilizado**: Te recomiendo cualquier modelo oX-mini-high (donde X es la versión del momento), ya que son los modelos más avanzados y capaces de generar casos de prueba complejos mediante "razonamiento".

```markdown
Para el siguiente caso:

<insertá acá la consigna completa del problema que estás resolviendo, incluyendo ejemplos y restricciones que haya provisto el profesor o profesora.>

Generar al menos tres listados de pruebas y los resultados esperados según el enunciado.
```
