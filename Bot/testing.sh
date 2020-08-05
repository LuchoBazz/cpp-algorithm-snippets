#!/bin/bash

for i in $(find -name '*.cpp'); do
   [ -f "$i" ] || break
   echo "$i --> ${i##*/}"
done
