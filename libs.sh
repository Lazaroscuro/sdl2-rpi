#!/bin/bash
#cd #sh ../utilitylib.sh
#cd ..

list="SDL2_image-2.0.1 smpeg2-2.0.0 SDL2_mixer-2.0.1 SDL2_net-2.0.1 SDL2_ttf-2.0.14"

for dir in $list
do
	ls -d $dir
	pushd $dir
	sh ../utilitylib.sh
	popd
done
