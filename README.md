# Proyecto de Análisis de Algoritmos con GTK y GTKMM

Este proyecto muestra visualizaciones de tiempos de ejecución para diferentes algoritmos de ordenación y búsqueda, utilizando `gtkmm` para la interfaz gráfica.

## Requisitos del sistema

- **Windows** (El proyecto usa MSYS2 para configurar el entorno)
- **GTK** y **gtkmm** para la interfaz gráfica.

## Instrucciones de instalación

### 1. Descargar MSYS2

MSYS2 es un entorno que proporciona las herramientas necesarias para compilar y ejecutar programas de tipo Unix en Windows. Puedes descargarlo desde el siguiente enlace:

[Descargar MSYS2](https://www.msys2.org/)

### 2. Instalar MSYS2

Una vez descargado el instalador de MSYS2, sigue las instrucciones para instalarlo. Después de la instalación, abre el terminal **MSYS2 UCRT64** para proceder con la instalación de las bibliotecas necesarias.

### 3. Actualizar MSYS2

Antes de instalar cualquier paquete, asegúrate de actualizar MSYS2. Abre la terminal **MSYS2 UCRT64** y ejecuta los siguientes comandos:

```bash
pacman -Syu
```

### 4. Instalar GTK y GTKMM
Ahora que MSYS2 está actualizado, necesitamos instalar las bibliotecas gtk y gtkmm. Ejecuta los siguientes comandos en la terminal MSYS2 UCRT64:
```bash
pacman -S mingw-w64-ucrt-x86_64-toolchain
pacman -S mingw-w64-ucrt-x86_64-gtk4
pacman -S mingw-w64-ucrt-x86_64-gtkmm4
```

### 5. Configurar el entorno en CLion
Configurar el compilador y las rutas para que CLion use el entorno de MSYS2 y GTKMM:
1. Configuración del compilador:
- Ve a `File > Settings > Build, Execution, Deployment > Toolchains.`
- En C Compiler escogerás: `C:\msys64\ucrt64\bin\gcc.exe`
- En C++ Compiler escogerás: `C:\msys64\ucrt64\bin\g++.exe`
- En Debugger escogerás: `C:\msys64\ucrt64\bin\gdb.exe`

2. Variables de Entorno:
- Asegúrate de que las variables de entorno están configuradas para incluir las rutas de MSYS2. Por ejemplo:
-- Path: Añade `C:\msys64\ucrt64\bin`

### 5. Compilar y Ejecutar el Proyecto
Ahora puedes compilar y ejecutar el proyecto desde tu IDE (como CLion) o usando el terminal MSYS2 UCRT64. Si decides hacerlo desde el terminal, navega al directorio del proyecto y usa make para compilarlo:
```bash
cd /path/to/project
mkdir build
cd build
cmake ..
make
```

Después de la compilación, puedes ejecutar el programa con:
`./your_executable_name`

O haciendo clic en el botón de Run en CLion.

