#!/bin/bash

logged_in_users=$(who) count=$(echo "$logged_in_users" | wc -l | xargs) 	
echo "Number of logged-in users: $count" 