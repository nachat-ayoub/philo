#!/bin/bash

# Path to your program
PHILO="./philo"

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
NC="\033[0m" # No Color

# Array of tests where one philosopher should die (word 'died' must appear)
die_tests=(
  "4 310 200 100 2"
  "2 180 91 60 2"
  "6 180 181 60 2"
  "8 180 60 121 2"
  "20 180 60 181 2"
  "3 180 89 89 2"
  "5 180 180 60 2"
  "7 120 60 60 2"
  "3 800 300 60 2"
  "19 210 71 60 2"
)

# Array of tests where no philosopher should die (word 'died' must NOT appear)
no_die_tests=(
  "4 410 200 200 10"
  "2 180 60 60 10"
  "4 800 390 60 10"
  "8 180 85 85 10"
  "18 180 85 85 10"
  "3 210 65 135 10"
  "3 210 60 145 10"
  "5 900 295 60 10"
  "7 300 60 60 10"
  "19 210 69 139 10"
)

pass_count=0
fail_count=0

echo -e "${BLUE}Starting tests for ./philo...${NC}"

echo -e "\n${BLUE}-- Tests where a philosopher should die (looking for 'died') --${NC}"
for i in "${!die_tests[@]}"; do
  args=${die_tests[$i]}
  echo -n "TEST $i (args: $args): "
  output=$($PHILO $args 2>&1)
  if echo "$output" | grep -q "died"; then
    echo -e "${GREEN}PASS${NC}"
    ((pass_count++))
  else
    echo -e "${RED}FAIL${NC} (no 'died' found)"
    ((fail_count++))
  fi
done

echo -e "\n${BLUE}-- Tests where no philosopher should die (no 'died' expected) --${NC}"
for i in "${!no_die_tests[@]}"; do
  args=${no_die_tests[$i]}
  echo -n "TEST $i (args: $args): "
  output=$($PHILO $args 2>&1)
  if echo "$output" | grep -q "died"; then
    echo -e "${RED}FAIL${NC} ('died' found)"
    ((fail_count++))
  else
    echo -e "${GREEN}PASS${NC}"
    ((pass_count++))
  fi
done

echo -e "\n${BLUE}Testing complete.${NC}"
echo -e "${GREEN}Passed: $pass_count${NC}"
echo -e "${RED}Failed: $fail_count${NC}"
