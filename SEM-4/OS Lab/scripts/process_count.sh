#!/bin/bash

process_count=$(ps aux | wc -l)
echo "Number of processes running on the system: $process_count"