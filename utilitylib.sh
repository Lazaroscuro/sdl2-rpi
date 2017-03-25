#!/bin/sh
./autogen.sh \
&& ./configure \
&& make \
&& sudo make install
