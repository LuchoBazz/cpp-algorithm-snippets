#!/usr/bin/env sh

# @author : Luis Miguel Baez <es.luismiguelbaez@gmail.com>

# Shell Colors

reset="\033[0m";
red_fill="\033[7;107;91m";
red_bold="\033[1;31m";
blue_fill="\033[7;49;34m";
blue_bold="\033[49;34m";
green_fill="\033[7;49;32m";
green_bold="\033[49;32m";
yellow_fill="\033[7;49;33m";
yellow_bold="\033[49;33m";
white_fill="\033[7;49;20m";
white_bold="\033[49;20m";

# check if it is current directory
if [ "$1" = "--current-dir" ]; then
    path=""
else
    cd "$1"
    path=$1
fi

# Username
echo "\n📌 ${red_bold}@SorKierkegaard${reset}\n"

# C++ Compiler
g++ -std=c++17 -o "$2.o" "$2.cpp"

# Execute all testcases
for i in *.in; do
    [ -f "$i" ] || break
    
    # Show testcase filename
    echo "🔴 ${yellow_fill}File '$i'${reset}"

    # Time Elapsed
    START_TIME=$(date +%s%N);
    echo "-$white_fill"
    # Execute Testcase
    timeout 3s ./$2.o < $i > my${i%%.in}.out
    END_TIME=$((($(date +%s%N) - $START_TIME)/1000000));
    
    # Show testcase output
    cat my${i%%.in}.out

    echo "$reset-"
    
    # Check TLE and Show execution time
    if [ "$END_TIME" -lt 2000 ]; then
        echo "🌀 ${green_fill}Finished in : ${reset}${yellow_fill}$END_TIME${reset}${green_fill} ms$reset"
    else
        echo "⛔ ${red_fill}Time Limit Exceeded : ${reset}${yellow_fill}$END_TIME${reset}${red_fill} ms$reset"
    fi
    echo ""
    echo "${green_bold}≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡${reset}"
    echo ""
done

