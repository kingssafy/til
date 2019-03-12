age = 5

stage = ""
pre = ""
if age < 2:
    stage = 'baby'
elif age < 4:
    stage = "toddler"
elif age < 13:
    stage = "kid"
elif age <20:
    stage = "teenager"
elif age < 65:
    stage = "adult"
else:
    stage = "elder"
if stage == "adult" or stage == "elder":
    pre = "an"
else:
    pre = "a"

print(f"The person is {pre} {stage}.")