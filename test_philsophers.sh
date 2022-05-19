#!/bin/zsh

echo '\033[91m _____ _   _ _                 _                  _____        _           
|  _  | |_|_| |___ ___ ___ ___| |_ ___ ___ ___   |_   _|__ ___| |_ ___ ___ 
|   __|   | | | . |_ -| . | . |   | -_|  _|_ -|    | || -_|_ -|  _| -_|  _|
|__|  |_|_|_|_|___|___|___|  _|_|_|___|_| |___|    |_||___|___|_| |___|_|  
                          |_|                                              \033[0m\n'

if [ "$#" -ne 2 ]; then
    echo "Usage: start.sh <Project Folder> <Test Type>"
    echo "\tType 1: test philo_one only"
    echo "\tType 3: test philo_bonus only"
    exit
fi

if [ "$2" -gt 3 -o "$2" -lt 0 ]; then
    echo "[Error]: Wrong Arguments"
    exit
fi

echo "\033[92m[+] Given Folder: $1"
echo "[+] Test Type: $2\033[0m\n"

test_one ()
{
    ("$2/$1" 4 310 200 100 > "./log_$1")&
    sleep 5
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
    if [ $output = "died" ];then
        echo "\033[92m[+] Test #1 Succeeded -> Given 4 310 200 100 arguments to $1, a philosopher have die !!\033[0m"
    else
        echo "\033[91m[+] Test #1 Failed -> Given 4 310 200 100 arguments to $1, a philosopher should die !\033[0m"
    fi
    rm -rf "./log_$1"
}

test_two ()
{
    echo "\033[94m[+] Test #2: Executing your program for 180 second, please wait...\033[0m"
    ("$2/$1" 4 410 200 200 > /dev/null)&
    i=1
    error=0
    while [ $i -lt 180 ];do
        printf "\r[%d...]" $i
        pgrep $1 > /dev/null
        if [ "$?" -ne 0 ];then
            echo "\r\033[91m[+] Test #2 Failed -> Given 4 410 200 200 arguments to $1, no philosopher should die !\033[0m"
            error=1
            break
        fi
        sleep 1
        i=$(( $i + 1 ))
    done
    sleep 1
    if [ $error -eq 0 ];then
        pkill $1
        echo "\r\033[92m[+] Test #2 Succeeded -> Given 4 410 200 200 arguments to $1, no philosopher have die !\033[0m"
    fi
}

test_three ()
{
    echo "\033[94m[+] Test #3: Executing your program for 180 second, please wait...\033[0m"
    ("$2/$1" 5 800 200 200 > /dev/null)&
    i=1
    error=0
    while [ $i -lt 180 ];do
        printf "\r[%d...]" $i
        pgrep $1 > /dev/null
        if [ "$?" -ne 0 ];then
            echo "\r\033[91m[+] Test #3 Failed -> Given 4 800 200 200 arguments to $1, no philosopher should die !\033[0m"
            error=1
            break
        fi
        sleep 1
        i=$(( $i + 1 ))
    done
    sleep 1
    if [ $error -eq 0 ];then
        pkill $1
        echo "\r\033[92m[+] Test #3 Succeeded -> Given 4 800 200 200 arguments to $1, no philosopher have die !\033[0m"
    fi
}

test_four ()
{
    ("$2/$1" 4 410 200 200 $3 > "./log_$1")&
    sleep 10
    pgrep $1 > /dev/null
    if [ "$?" -eq 1 ];then
        lines=$(grep eating "./log_$1" | wc -l)
        if [ $lines -ge $4 ];then
            echo "\t\033[92m[+] Test #4-$5 Succeeded -> Given 4 410 200 200 $3 arguments to $1, every philosophers have eaten $3 times\033[0m"
        else
            echo "\t\033[91m[+] Test #4-$5 Failed -> Given 4 410 200 200 $3 arguments to $1, $1 should only be stopped if each philosopher ate at least $3 times !\033[0m"
        fi
    else
        echo "\t\033[91m[+] Test #4-$5 Failed  -> Given 4 410 200 200 $3 arguments to $1, $1 should stop ! \033[0m"
        pkill $1
    fi
    rm -rf "./log_$1"
}

test_five ()
{
    echo "\033[94m[+] Test #5 on progress, please wait...\033[0m"
    i=1
    t=0
    error=0
    while [ $i -le 10 ];do
        ("$2/$1" 2 60 60 60 > "./log_$1")&
        sleep 2
        pgrep $1 > /dev/null
        if [ "$?" -eq 1 ];then
            printf "\r[%d/10]" $i
            tmp=$(grep died -m 1 "./log_$1" | awk '{print $1}' | sed 's/[^0-9]*//g')
            if [ $i -gt 1 ];then
                x=$(expr $tmp - $t)
                x=${x#-}
                if [ $x -gt 10 ];then
                    printf "\r\033[91m[+] Test #5 Failed -> Given 2 60 60 60 arguments to $1, the time difference of each death shouldn't be bigger than 10ms ! \033[0m\n"
                    error=1
                    break
                fi
            else
                t=$tmp
            fi
        else
            printf "\r\033[91m[+] Test #5 Failed -> Given 2 60 60 60 arguments to $1, a philosopher should die ! \033[0m\n"
            pkill $1
            break
        fi
        i=$(( $i + 1 ))
    done
    
    if [ $error -eq 0 ];then
        echo "\r\033[92m[+] Test #5 Succeeded -> Given 2 60 60 60 arguments to $1 a philosopher have die !\033[0m"
    fi
}

test_six ()
{
    ("$2/$1" 10 410 200 200 > /dev/null)&
    sleep 2
    forks=$(pgrep $1 | wc -l)
    if [ "$forks" -eq 11 ];then
        printf "\r\033[92m[+] Test #6 Given 10 410 200 200- > Succeeded 10 processes have been forked\033[0m\n"
    else
        printf "\r\033[91m[+] Test #6 Failed -> Given 10 410 200 200 arguments to $1, 10 processes should be forked, each process for a philosopher !\033[0m\n"
    fi
    pkill $1
}

if [ "$2" -eq 1 -o "$2" -eq 0 ];then

    echo "[============[Testing philo_one]==============]\n"

    target="philo"
    echo "[+] MAKE, please wait..."
    make -C "$1"

    if [ "$?" -ne 0 ];then
        echo "\n[+] There's a problem while compiling $target, please recheck your inputs"
        exit
    fi

    test_one $target $1
    test_two $target $1
    test_three $target $1  
    echo "\033[94m[+] Test #4 on progress, please wait...\033[0m"
    test_four $target $1 7 28 1
    test_four $target $1 10 40 2
    test_four $target $1 12 48 3
    test_four $target $1 15 60 4
    test_five $target $1
    echo "\033[94m[+] Cleaning, please wait...\033[0m"
    make -C "$1" fclean
fi

if [ "$2" -eq 3 -o "$2" -eq 0 ];then

    echo "\n[============[Testing philo_bonus]==============]\n"

    target="philo_bonus"
    echo "[+] MAKE, please wait..."
    make -C "$1" 

    if [ "$?" -ne 0 ];then
        echo "\n[+] There's a problem while compiling, please recheck your inputs"
        exit
    fi

    test_one $target $1
    
    test_two $target $1

    test_three $target $1
    
    echo "\033[94m[+] Test #4 on progress, please wait...\033[0m"
    test_four $target $1 7 28 1
    test_four $target $1 10 40 2
    test_four $target $1 12 48 3
    test_four $target $1 15 60 4
    test_five $target $1
    test_six $target $1
    echo "\033[94m[+] Cleaning, please wait...\033[0m"
    make -C "$1" fclean
fi
