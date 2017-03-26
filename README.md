# Scripts para instalar SDL2 (2.0.5) en Raspberry Pi (Raspbian Jessie)

Por conveniencia he reunido estas secuencias de órdenes
de compilación e instalación de SDL2 en un repositorio,
principalmente para uso personal.

Emplear con cuidado.

> Notas - La biblioteca es incapaz de abrir un display en una ventana XOrg
> utilizando el driver OpenGLES 2.
> Esto requiere una investigación más profunda,
> pero es suficiente para hacer que los programas funcionen
> con aceleración gráfica.
>
> Para ello cambie a un TTY (en muchos sistemas a través de Ctrl + Alt + F<N>,
> por ejemplo F1, siendo F7 donde suele desplegarse el escritorio
> si lo hubiera).
>
> Veáse para mayor información:
> http://choccyhobnob.com/tutorials/sdl2-2-0-5-on-raspberry-pi/

## Dependencias

libfontconfig-dev qt5-default automake mercurial libtool libfreeimage-dev libopenal-dev libpangol1.0-dev libsndfile-dev libudev-dev libtiff5-dev libwebp-dev libasound2-dev libaudio-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libxss-dev libesd0-dev freeglut3-dev libmodplug-dev libsmpeg-dev

## Instrucciones

Primero entre en el directorio raíz del repositorio.

Descargue SDL2 2.0.5, descomprímalo y ejecute **desde su directorio**
el script _confighw.sh_.

```bash
wget -c http://www.libsdl.org/release/SDL2-2.0.5.tar.gz
tar xvf SDL2-2.0.5.tar.gz
cd SDL2-2.0.5
sh ../confighw.sh
make
sudo make install
```

Utilice sdl2-config para verificar el resultado:

```bash
sdl2-config --version
```

Desgargue también SDL2_image, SDL2_mixer y SDL2_net en sus versiones 2.0.1,
SDL2_ttf 2.0.14 y smpeg2 2.0.0. Descompríma y ejecute _libs.sh_
**desde el directorio que las contenga**.

```bash
wget -c http://www.libsdl.org/projects/SDL2_image/release/SDL2_image-2.0.1.tar.gz
wget -c http://www.libsdl.org/projects/SDL2_mixer/release/SDL2_mixer-2.0.1.tar.gz
wget -c http://www.libsdl.org/projects/SDL2_net/release/SDL2_net-2.0.1.tar.gz
wget -c http://www.libsdl.org/projects/SDL2_ttf/release/SDL2_ttf-2.0.14.tar.gz
wget -c http://www.libsdl.org/projects/smpeg/release/smpeg2-2.0.0.tar.gz

# Este script es de bash, una shell más conservadora no servirá.
bash libs.sh
```


Si desea añadir bibliotecas o modificar sus versiones,
puede modificar la variable _list_ en este script.

> Nota - En ese caso debe revisar _utilitylib.sh_.

## Proyecto de prueba

Diríjase al directorio _test_, ejecute make y lance el programa _hw_test.elf_.
Asegúrese de lanzarlo desde un TTY.
Modifíquelo para que utilice otras opciones.

## Próxima versiones

Simplificar proceso de instalación y manejo de versiones.
Pasar el control de los flags del programa de prueba a flags de la CLI.
