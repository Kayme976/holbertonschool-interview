#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics:
  - Total file size
  - Count of each status code (from a predefined set)
Prints metrics every 10 lines or on keyboard interruption (CTRL + C).
"""

import sys
import re
from collections import defaultdict


VALID_STATUS_CODES = {'200', '301', '400', '401', '403', '404', '405', '500'}


total_size = 0
status_counts = defaultdict(int)
line_count = 0

log_pattern = re.compile(
    r'^\S+ - \[[^\]]+\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
)

def print_stats():
    """Print the collected metrics."""
    print(f"File size: {total_size}")
    for code in sorted(VALID_STATUS_CODES):
        if status_counts[code]:
            print(f"{code}: {status_counts[code]}")

try:
    for line in sys.stdin:
        line = line.strip()
        match = log_pattern.match(line)
        if match:
            status_code, file_size = match.groups()
            try:
                total_size += int(file_size)
                if status_code in VALID_STATUS_CODES:
                    status_counts[status_code] += 1
            except ValueError:
                pass
        line_count += 1

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise
finally:
    if line_count % 10 != 0:
        print_stats()
