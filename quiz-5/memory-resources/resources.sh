#!/bin/bash

spawner() {
    # Check the number of arguments
    if [ $# -ne 3 ]; then
        echo "Error: Incorrect number of arguments passed to spawner()"
        exit 2
    fi

    memoryInKB=$1
    timeoutInSec=$2
    binaryName=$3

    # Check if the binary exists
    if [ ! -f "$binaryName" ]; then
        echo "Error: $binaryName doesn't exist"
        exit 3
    fi

    # Check if the binary has execute permission
    if [ ! -x "$binaryName" ]; then
        echo "Error: $binaryName doesn't have +x flag"
        exit 4
    fi

    # Run the binary with the specified memory limit and timeout
    # The & at the end of the command is used to run the command in the background.
    timeout "$timeoutInSec"s ./"$binaryName" &

    # Get the process ID of the last background command
    # $! holds the PID of the most recent background command
    pid=$!

    # Monitor the memory usage of the process
    while kill -0 "$pid" 2> /dev/null; do
        # Get the current memory usage in kilobytes
        currentMemory=$(pmap -x "$pid" | grep total | awk '{print $4}')

        # Check if the current memory usage exceeds the limit
        if [ "$currentMemory" -gt "$memoryInKB" ]; then
            echo "Error: Memory limit exceeded"
            if kill -0 "$pid" 2> /dev/null; then
                kill "$pid"  # Terminate the process
            fi
            exit 1
        fi

        # Sleep for a short interval before checking again
        sleep 1
    done

    # Wait for the binary to finish running
    wait "$pid"
    exitStatus=$?

    # Check if the binary exceeded the timeout
    if [ $exitStatus -eq 124 ]; then
        echo "Error: Timeout"
        exit 5
    fi
}

# Example usage: memory limit, timeout, binary
spawner 5000 5 resources