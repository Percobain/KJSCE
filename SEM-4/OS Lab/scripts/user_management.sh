#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <username>"
    exit 1
fi

username=$1

if id "$username" &>/dev/null; then
    echo "User $username already exists."
else
    sudo useradd "$username"
    echo "User $username has been added."
fi