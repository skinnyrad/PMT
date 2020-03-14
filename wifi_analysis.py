import re
import sys

def main():
    if len(sys.argv) != 2:
        print("invalid command line arguments")
        print("valid format: python wifi_analysis.py <filename>")

    with open(sys.argv[1]) as fp:
        contents = fp.read().split('\n')

    # print(contents)

    matches = []
    trues = []
    r = re.compile(r"^SSID: ([\w\W])+ Connected, POST: (True|False)$")
    r_true = re.compile(r"([\w\W])+(True)$")

    for line in contents:
        if r.match(line):
            matches.append(line)

    for match in matches:
        if r_true.match(match):
            trues.append(match)

    print("WiFi Connection Analysis:\n|")
    print(f"| --> Number of Posts Attemped - {len(matches)}")
    print(f"| --> Number of Posts Successful - {len(trues)}")
    print(f"|\n| --> Percentage of Successful Posts  - {(len(trues)/len(matches)*100):.2f}%")

if __name__ == main():
    main()