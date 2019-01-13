major_rivers = {
    'nile': 'egypt',
    'han': 'korea',
    'ganges': 'india',
}

for river, nation in major_rivers.items():
    print(f"{river} runs through {nation}.")
for river in major_rivers.keys():
    print(river)
for nation in major_rivers.values():
    print(nation)