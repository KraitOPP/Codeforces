import json

memory_limit = 10000
packet_ops = 10000
count_ops = 1

methods = ["Router"] + ["addPacket"] * packet_ops + ["getCount"] * count_ops

arguments = [[memory_limit]]

for i in range(1, packet_ops + 1):
    source = i
    destination = i + 1 
    timestamp = i * 10   
    arguments.append([source, destination, timestamp])

for _ in range(count_ops):
    arguments.append([12346, 1, 1_000_000_000])  

with open("tle_testcase_final.json", "w") as f:
    json.dump(methods, f, separators=(",", ":"))
    f.write("\n")
    json.dump(arguments, f, separators=(",", ":"))

print("✅ Final valid test case saved as 'tle_testcase_final.json'")
