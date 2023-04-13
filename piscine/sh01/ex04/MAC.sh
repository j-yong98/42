#!/bin/bash
ifconfig -a | grep '..:..:..:..:..:..' | awk '{print $2}'
