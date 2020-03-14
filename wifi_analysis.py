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

    """
    " the following for loops are represented by the one liners below them
    """
    # for line in contents:
    #     if r.match(line):
    #         matches.append(line)

    # for match in matches:
    #     if r_true.match(match):
    #         trues.append(match)

    list(matches.append(line) if r.match(line) else None for line in contents)

    list(trues.append(match) if r_true.match(match) else None for match in matches)

    print("WiFi Connection Analysis:\n|")
    print(f"| --> Number of Posts Attemped - {len(matches)}")
    print(f"| --> Number of Posts Successful - {len(trues)}")
    print(f"|\n| --> Percentage of Successful Posts  - {(len(trues)/len(matches)*100):.2f}%")

if __name__ == main():
    main()