#!/bin/bash
./push_swap $1 | tee >(./checker $1) >(./counter)