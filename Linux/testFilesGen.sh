#!/bin/bash
for i in `seq 1 10`; do
	for j in `seq 1 50`; do
		python3 testCaseGen.py >> ./testfiles/test$i.cpp
	done
done
