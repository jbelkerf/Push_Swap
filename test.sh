#!/bin/bash
./push_swap $1 | tee 1>/dev/null >(./checker $1) >(./counter)