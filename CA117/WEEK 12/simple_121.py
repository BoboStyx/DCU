import sys
 
lines = [line.strip() for line in sys.stdin]
for line in lines:
    letters = sorted([line.count(item) for item in set(line)])
    print(sum(letters[:-2]) if len(letters) > 2 else 0)
