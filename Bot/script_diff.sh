#!/usr/bin/env sh

# @author : Luis Miguel Baez <es.luismiguelbaez@gmail.com>

# Shell Colors

reset="\033[0m";
blue_fill="\033[7;49;34m";
blue_bold="\033[49;34m";
yellow_fill="\033[7;49;33m";
yellow_bold="\033[49;33m";

# Check if it is current directory
if [ "$1" = "--current-dir" ]; then
    path=""
else
    cd "$1"
    path="$1/"
fi

# Show title
echo "${blue_fill} -> Differences${reset}\n\n"

# Check differences of all testcases
for i in *.in; do
    [ -f "$i" ] || break
    
    # Show testcase filename
    echo "${yellow_fill}File '$i'${reset}"
    
    # Show ✔️  if the output testcase doesn't have differences and ❌ in other case.
    diff -w -B my${i%%.in}.out ${i%%.in}.out > diff.out && echo "✔️ " || echo "❌\ndiff -w -B \"${path}my${i%%.in}.out\" \"${path}${i%%.in}.out\""
done

# Remove temporal files
rm -f diff.out

