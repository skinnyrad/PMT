# Automated Tester for raspberrypi python code

import sys
from os import path


# Default
if len(sys.argv) == 1:
    print("Try using: python3 test.py [-h | --help]")
    exit(0)


# Help menu
elif len(sys.argv) > 1 and ( sys.argv[1] == '-h' or sys.argv[1] == '--help' ):
    print("Supported tests:")
    print("--html_parser\t\tVerify the functionality of html_parser.py")


# html_parser tests
elif len(sys.argv) >= 1 and sys.argv[1] == '--html_parser':
    print("\n\nTesting html_parser...")

    sys.path.append( path.join('..','py') ) # code modules
    sys.path.append( path.join('..','..','..','test_cases') ) # test data
    import html_parser
    

    # Buffalo Wild Wings ------------------------------
    print("\n--Buffalo Wild Wings-- ")
    import data_bww
    
    # Test <head> redirects
    print("Testing <head> redirects...")
    for combo in data_bww.head_redirs:
        page = combo[0]
        correct_url = combo[1]
        ret = html_parser.get_head_redir_url(page)

        if correct_url == ret:
            print("---PASS---\n")
        else:
            print("---FAIL--- html_parser.get_head_redir_url returned:")
            print(ret)
            print("given:")
            print(page)
            print("instead of:")
            print(correct_url)
            print("\n")

    # Test form gathering
    print("Testing form gathering...")
    print("NOT IMPLIMENTED")
    for combo in data_bww.forms:
        page = combo[0]
        correct_form = combo[1]
        ret = html_parser.get_objects(page, 'form')

        # We're only using the first form
        if len(ret) > 0 and correct_form == ret[0]:
            print("---PASS---\n")
        else:
            print("---FAIL--- html_parser.get_forms returned:")
            #print(ret)
            print("given:")
            print(page)
            print("instead of:")
            print(correct_form)
            print("\n")

    print("Testing response generation...")
    print("NOT IMPLIMENTED")
