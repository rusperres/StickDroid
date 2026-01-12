#!/bin/bash

state=1

while IFS= read -r line; do
    echo "Line: $line"

    # Remove carriage returns just in case
    line="${line//$'\r'/}"

    # Launch kitty only the first time 0 appears
    if [[ "$line" == "0" && $state -eq 1 ]]; then
        state=0
        echo "Launching kitty..."
        nohup kitty &
    elif [[ "$line" != "0" ]]; then
        state=1
    fi
done

