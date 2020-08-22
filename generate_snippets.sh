#!/bin/bash

file="~/.vim/UltiSnips/cpp/cpp_generate.snippets"
folder="~/.vim"

echo "" > ~/.vim/UltiSnips/cpp/cpp_generate.snippets

for i in $(find -name '*.cpp'); do
   [ -f "$i" ] || break
   echo "$i --> ${i##*/}"
   cat "$i"
   echo "" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
   echo "snippet $(basename -- "$i" .cpp) \"$(basename -- "$i" .cpp) autocomplete\"" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
   cat "$i" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
   echo "" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
   echo "endsnippet" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
   echo "" >> ~/.vim/UltiSnips/cpp/cpp_generate.snippets
done
