
import random
import string

addedStrings = set()
duplicateCount = 0

f = open("length45.txt", "w")

i = 0

while i < 2**16:
	
	if i % 655 == 0:
		nr = i / 655
		print(nr)

	# length = 1 + random.choice(range(300))
	str = "".join(random.choice(string.ascii_lowercase) for _ in range(45))

	if str not in addedStrings:
		f.write(str + "\n")
		addedStrings.add(str)
		i += 1
	else:
		duplicateCount += 1

print("\ndone")
print("nr of duplicates:")
print(duplicateCount)

f.close()