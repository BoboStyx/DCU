import random, time

class Athlete:
    def __init__(self, number):
        self.number = number
        self.metres_travelled = 0

    def __repr__(self):
        return f"{self.number} {self.metres_travelled}"

    def move(self):
        self.metres_travelled += 1

registered_athletes = {}

num_athletes = 10000
combined_total_distance_metres = 100000

# Generate the Athletes
print(f"Generating {num_athletes:,} Athletes")
for i in range(num_athletes):
    registered_athletes[Athlete(i+1).number] = 0

print(f"Generating {combined_total_distance_metres:,} Random Athlete Moves")
for i in range(combined_total_distance_metres):
    registered_athletes[random.randint(1, num_athletes)] += 1

# Run Simulation
# Each randomly selected Athlete will travel a portion of the total distance
print(f"Simulating {combined_total_distance_metres:,} meters travelled across all Athletes...")

start_time = time.perf_counter()

for athlete in registered_athletes:
	for i in range(registered_athletes[athlete]):
            Athlete(athlete).move()

print(f'Simulation Time Taken: {round((time.perf_counter() - start_time) * 1000):,} milliseconds.')
