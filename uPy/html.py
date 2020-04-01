# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#

# Helper function
# Input:
# Output: [String, startindex, endindex]
#   String = A complete string starting with beginning_string and all characters through end_string
#            or the null string if either beginning_string or end_string is not found.
#            beginning_string must come before end_string.
#   startindex = the index within html_as_string where the beginning of the complete string is located.
#   endindex = the index within html_as_string where the end of the complete string is located (one after the last character of String).
def find_complete_string(html_as_string, beginning_string, end_string, start_index = 0):
    i = html_string.find(str(beginning_string), start_index, len(html_string))
    if i == -1:
        return ["",-1,-1] # only return a valid string
    j = html_string.find(str(end_string), i, len(html_string))
    if j == -1:
        return ["",i,-1] # only return a valid string
    
    j = j+len(end_string) # include end_string in the string
    return [html_string[i:j], i, j]



def get_tags(html_as_string, tag_type=None):
    tag_list = []
    i=0
    j=0
    ret_val = ["_",i,j]
    
    # look for a specific tag
    if tag_type is not None:
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html, "<{0}".format(tag_type), "</{1}".format(tag_type), ret_val[2] )
            
            # tags that do make up objects. ex: <a ... > there is no </a>
            if(ret_val[1] != -1): # start string found
                if(ret_val[2] == -1): # end string was not found
                    ret_val = find_complete_string(html, "<{0}".format(tag_type), ">".
                    tag_list.append(ret_val[0])
                else: # end string was found
                    tag_list.append(ret_val[0])

    # look for all tags
    else:
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html, "<", ">", ret_val[2] )
            tag_list.append(ret_val[0])
    
    return tag_list



def breakup_tag(tag):
    tag=tag.lstrip('<')
    tag=tag.rstrip('>')
    tag=tag.strip() #beg end whitespace
    print("tag={0}".format(tag)) #print out the complete tag < ... >
        
    #time to split up elements within the tag
    #cannot just split by spaces values can have spaces between quotes
    j=0
    tag_state = 0
    tag_list =[]
    while len(tag)>0:
        
        # searching for type
        if(tag_state == 0):
            j=tag.find(' ', 0, len(tag))
            if(j == -1):
                ret=tag
            else:
                ret=tag[0:j]
            
            tag=tag[j+1:len(tag)]
            ret=ret.strip()
            #print("type={0}\ttag={1}".format(ret,tag))
            tag_list.append(ret)
            
            tag_state=1
        
        #searching for key/value pair
        elif(tag_state == 1):
            j=tag.find('=', 0, len(tag))
            if(j==-1):
                break #end if no keyval pairs

            key = tag[0:j]
            tag = tag[j+1:len(tag)]
            key = key.strip(' ')
            print("key={0}\ttag={1}".format(key,tag))
            tag_list.append(key)
        
            #key found, pull "value"
            #pull val inbetween quotes
            j = tag.find('"', 0, len(tag)) #first quote
            tag=tag[j+1:len(tag)]
            j = tag.find('"', 0, len(tag)) #second quote
            val=tag[0:j].strip()
            tag = tag[j+1:len(tag)]
            print("val={0}\ttag={1}".format(val,tag))
            tag_list.append(val)

        #debugging
        print("\tTag split:{0}\n".format(tag))

        return tag_list



def construct_form_from_tag_internals(tags):
    
    formOpen = False #indicates if <form ...> seen but </form> not seen yet
    form = {}
    #From here on we have a list of the contents of a tag.
    #Decide how to handle it

    for tag_internals in tags: # the splitup tag internals of a single tag

        #form tag: beginning of form
        if(tag_internals[0]=="form"):

            # Create a new dictionary to store info
            tagDict = {}
            tagDict["tag_type"]=tag[0]
            print("tagDict[tag_type]= form")

            # insert key="value" pairs
            j=1
            while(j<len(tag)):
                key=tag[j]
                val=tag[j+1]
                j+=2
                tagDict[key] = val
                print("\ttagDict[{0}]={1}".format(key,val))
            
            # other tags will be inside forms
            tagDict["inside"] = []
            currentForm = tagDict

        # /form tag : end of form
        elif(tag[0]=="/form"):
            print("\ttag_type=/form")
            formOpen=0 #close out the form


        # a tag: indicates hyperlinked text
        elif(tag[0]=="a" or tag[0]=="input"):
            # Create a new dictionary to store info
            tagDict={}
            tagDict["tag_type"]=tag[0]
            print("\ttagDict[\"tag_type\"]={0}".format(tag[0]))

            # insert key="value" pairs
            j=1
            while(j<len(tag)):
                key=tag[j]
                val=tag[j+1]
                j+=2
                tagDict[key]=val
                print("\ttagDict[\"{0}\"]={1}".format(key,val))
            
            #append this tag into the form
            if(formOpen):
                    inside_list=form["inside"]   #get
                    inside_list.append(tagDict)  #append
                    form["inside"]=inside_list   #put back

    return form


# TOP LEVEL FUNCTION
# Input: HTML splashpage as bytes
# Returns a list of dictionaries. Each dictionary is a form:    
#   Pick a form by indexing into the list. Each form is a dictionary.   
#   Dictionary key value pairs are keys and values within that tag line:
#        ex from html: name="formname" method="POST"
#        becomes:   dict["name"] -> "formname"
#                   dict["method"] -> "POST"
def get_forms(html):
    
    html = html.decode('utf-8') # int to str

    # each entry in list is "<form ...> <...> </form>" 
    forms = get_tags(html, "form")
    if(len(forms) == 0):
        return []
    
    #debugging
    i=0
    while i < len(forms)
        print( "form[{0}]=\n{1}".format(i, forms[i]) )


    #break forms as strings into a list of tags: [form] = ["<form ...>", "<...>", "</form>"]
    all_forms = []
    for string in forms:
        all_forms.append( get_tags(forms) )
    
    #debugging
    i=0
    while i < len(all_forms)
        print( "form[{0}]=\n".format(i) )
        for tag in all_forms[i]:
            print(tag)

    # split out each tag's internals
    i = 0
    while i < len(all_forms)
        tags = all_forms[i]
        j = 0
        while j < len(tags)
            tag = tags[j]
            all_forms[i][j] = breakup_tag(tag)
    
    parsed_forms = []
    for form in all_forms:
        parsed_forms.append(construct_form_from_tag_internals(form))
    
    return parsed_forms



def get_internal_form_data(form):
    return form["inside"]



def legacy_parse_forms(html):
    currentForm = -1
    forms = []
    formOpen = 0 #indicates if <form ...> seen but </form> not seen yet

    #int to str
    html = html.decode('utf-8')

    # empty condition: give back empty dict
    if(html == ''):
        return []
    
    # Note: Tags can end on same line they were created on

    # State List
    # NOT_IN_TAG = 0  # 0 = not in a tag. b'<' not seen yet
    # IN_TAG = 1      # 1 = inside a tag. b'<' seen but b'>' not seen

    state = 0
    i = 0
    print("Entering Form parse loop")
    while i < len(html):
        byte = html[i]

        # STATE 0 searching ..
        if(state==0):
            if(byte != '<' ):
                i=i+1
                continue
            else:
                state=1
                #print("Tag Detected: <")
                
        # STATE 1 in a tag
        if(state==1):
            # find postion of b'>' starting after b'<' 
            endpos=html.find('>', i, len(html)-1 )
            #print("endpos={0}".format(endpos))

           # '>' not found in html. tag starts but does not terminate
            if(endpos==-1):
                print("\tError: Tag does not terminate. No >")
                #print(html[i:len(html)]) #print out the rest of the html for debugging
                return []
            
            # complete tag found '<' and '>'
            else:
                # pull out '<' through '>'
                tag=html[ i:endpos+1 ]

                # catch <>
                if(len(tag) < 1):
                    print("\tError: Zero length after split. Skipping")
                    continue
                
                #print out the complete tag < ... >
                #print("tag={0}".format(tag))
                tag=tag.lstrip('<')
                tag=tag.rstrip('>')
                tag=tag.strip() #beg end whitespace
                
                #time to split up elements within the tag
                #cannot just split by spaces values can have spaces between quotes
                j=0
                tag_state = 0
                tag_list =[]
                while len(tag)>0:
                    
                    # searching for type
                    if(tag_state == 0):
                        j=tag.find(' ', 0, len(tag))
                        if(j == -1):
                            ret=tag
                        else:
                            ret=tag[0:j]
                        
                        tag=tag[j+1:len(tag)]
                        ret=ret.strip()
                        #print("type={0}\ttag={1}".format(ret,tag))
                        tag_list.append(ret)
                        
                        tag_state=1
                    
                    #searching for key/value pair
                    elif(tag_state == 1):
                        j=tag.find('=', 0, len(tag))
                        if(j==-1):
                            break #end if no keyval pairs

                        key = tag[0:j]
                        tag = tag[j+1:len(tag)]
                        key = key.strip(' ')
                        #print("key={0}\ttag={1}".format(key,tag))
                        tag_list.append(key)
                    
                        #key found, pull "value"
                        #pull val inbetween quotes
                        j = tag.find('"', 0, len(tag))
                        tag=tag[j+1:len(tag)]
                        j = tag.find('"', 0, len(tag))
                        val=tag[0:j]
                        tag = tag[j+1:len(tag)]
                        val = val.strip()
                        print("val={0}\ttag={1}".format(val,tag))
                        tag_list.append(val)

                #print("\tTag split:{0}\n".format(tag))
                
                #From here on we have a list of the contents of a tag.
                #Decide how to handle it

                #form tag: beginning of form
                if(tag[0]=="form"):

                    #Error: new form but old one not finished:
                    if(formOpen):
                        print("\tError: Form within a form")
                    else:
                        formOpen=1

                    # Create a new dictionary to store info
                    tagDict = {}
                    tagDict["tag_type"]=tag[0]
                    print("tagDict[tag_type]= form")

                    # insert key="value" pairs
                    i=1
                    while(i<len(tag)):
                        key=tag[i]
                        val=tag[i+1]
                        i+=2
                        tagDict[key] = val
                        print("\ttagDict[{0}]={1}".format(key,val))
                    
                    # other tags will be inside forms
                    tagDict["inside"] = []
                    # add this form to the overall structure
                    forms.append(tagDict)
                    currentForm+=1

                # /form tag : end of form
                elif(tag[0]=="/form"):
                    print("\ttag_type=/form")
                    formOpen=0 #close out the form


                # a tag: indicates hyperlinked text
                elif(tag[0]=="a" or tag[0]=="input"):
                    # Create a new dictionary to store info
                    tagDict={}
                    tagDict["tag_type"]=tag[0]
                    print("\ttagDict[\"tag_type\"]={0}".format(tag[0]))

                    # insert key="value" pairs
                    i=1
                    while(i<len(tag)):
                        key=tag[i]
                        val=tag[i+1]
                        i+=2
                        tagDict[key]=val
                        print("\ttagDict[\"{0}\"]={1}".format(key,val))
                    
                    #append this tag into the form
                    if(formOpen):
                            form=forms[currentForm]      #get
                            inside_list=form["inside"]   #get
                            inside_list.append(tagDict)    #append
                            form["inside"]=inside_list   #put back
                            forms[currentForm]=form      #put back
                
            # update for future loop
            i=endpos+1
            state=0
        # end of state 1 (IN_TAG)

    return forms
