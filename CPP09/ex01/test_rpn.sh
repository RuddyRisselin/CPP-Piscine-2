#!/bin/bash

EXEC="./RPN"

tests=(
    "3 4 + 5 *|35"
    "7 3 - 2 *|8"
    "10 5 / 2 +|4"
    "2 3 + 4 * 5 -|15"

    "3 +|Error: invalid expression."
    "3 4 5 +|Error: invalid expression."
    "3 a +|Error: invalid token."

    "4 0 /|Error: division by zero."
    "42|42"

    "5 1 2 + 4 * + 3 -|14"
    "9 5 2 - * 7 3 / +|29"

    "3 4 +    5 *|35"

    "|Error: invalid expression."
    "   |Error: invalid expression."
)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

total=${#tests[@]}
passed=0

echo "Running tests for $EXEC..."

for test in "${tests[@]}"; do
    input=$(echo "$test" | cut -d'|' -f1)
    expected=$(echo "$test" | cut -d'|' -f2)

    output=$($EXEC "$input" 2>&1)

    if [ "$output" == "$expected" ]; then
        echo -e "${GREEN}PASSED${NC}: Input='$input' Output='$output'"
        ((passed++))
    else
        echo -e "${RED}FAILED${NC}: Input='$input' Expected='$expected' Got='$output'"
    fi
done

echo
echo "Tests passed: $passed/$total"
if [ "$passed" -eq "$total" ]; then
    echo -e "${GREEN}All tests passed!${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi
