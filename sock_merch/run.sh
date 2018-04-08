#!/usr/bin/env bash

python sock_merchant.py < input00.txt > result && diff -q result expected && echo success || echo FAIL
rm -rf result
