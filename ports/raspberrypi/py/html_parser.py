# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  Raspbian Lite version February 2020
#  Python 3.7
#  Filename : html.py
# -------------------------------

# Helper function
# Input:
# Output: [String, startindex, endindex]
#   String = A complete string starting with beginning_string and all characters through end_string
#            or the null string if either beginning_string or end_string is not found.
#            beginning_string must come before end_string.
#   startindex = the index within html_as_string where the beginning of the complete string is located.
#   endindex = the index within html_as_string where the end of the complete string is located (one after the last character of String).
def find_complete_string(html_as_string, beginning_string, end_string, start_index = 0):
    
    i = html_as_string.find(str(beginning_string), start_index, len(html_as_string))
    if i == -1: #If we cannot find beginning string
        return ["",-1,-1] # only return a valid string

    j = html_as_string.find(str(end_string), i, len(html_as_string))
    if j == -1: # If we found beginning string but not end string
        return ["",i,-1] # only return a valid string
    
    j = j+len(end_string) # include end_string in the string
    return [html_as_string[i:j], i, j]


# Returns a list of strings
def get_tags(html_as_string, tag_type=None):
    tag_list = []
    i=0
    j=0
    ret_val = ["_",i,j]
    
    # look for a specific tag
    if tag_type is not None:
        while ret_val[0] != "":
            # tags that make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), "</{0}>".format(tag_type), ret_val[2] ) #start search at end of last string

            # tags that don't make up objects. ex: <a ... > there is no </a>
            # start string found
            if(ret_val[1] != -1):
                if(ret_val[2] == -1): # end string was not found
                    ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), ">", ret_val[1] )
                    tag_list.append(ret_val[0])
                else: # end string was found
                    tag_list.append(ret_val[0])

    # tag_type not specified look for all tags
    else:
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<", ">", ret_val[2] )
            tag_list.append(ret_val[0])
    
    return tag_list


# takes in string, spits out list
def breakup_tag(tag):
    tag=tag.lstrip('<')
    tag=tag.rstrip('>')
    tag=tag.strip() #beg end whitespace
        
    #time to split up elements within the tag
    #cannot just split by spaces values can have spaces between quotes
    j=0
    contents_list =[]
    
    # pull out type (ie form, html, body)
    j=tag.find(' ', 0, len(tag))
    if(j == -1): #ex: </form>
        ret=tag
    else:       #ex: <form method="POST" ... >
        ret=tag[0:j]
    
    tag=tag[j+1:] # cut out the tag_type
    ret=ret.strip()
    contents_list.append(ret) # put tag_type in list
        
    while len(tag)>0:

        #searching for key/value pair
        j=tag.find('=', 0, len(tag))
        if(j==-1):
            break # end if no keyval pairs

        key = tag[0:j] #pull out key
        tag = tag[j+1:]
        key = key.strip(' ')
        contents_list.append(key)
    
        #key found, pull val (key="val" key='val' key=val )
        #pull val inbetween quotes
        # Case: sometimes value is not wrong in quotes if it is just alphabetical characters
        # need to determine if quotes were used.
        wrapper = '"'
        j = tag.find(wrapper, 0, len(tag)) #could be wrapped in double quotes
        if(j != 0):
            wrapper = "'"
            j = tag.find(wrapper, 0, len(tag)) # could be wrapped in single quotes
            if(j != 0):
                wrapper = "" # Well crud val isnt wrapped in anything

        if wrapper == "'" or wrapper == '"':
            tag=tag[j+1:len(tag)]
            j = tag.find(wrapper, 0, len(tag)) #second quote
        
        elif wrapper == "":
            j = tag.find(' ', 0, len(tag)) #grab the end space
            if(j == -1):
                j = tag.find('>', 0, len(tag)) #grab the end space

        
        val=tag[0:j].strip()
        tag = tag[j+1:]
        contents_list.append(val)

    return contents_list

# takes list, returns dict
def tag_internals_to_dict(contents):
    tag_dict = {}

    tag_dict["tag_type"] = contents[0]

    #put in key=val pairs
    i=1
    while i+1 < len(contents):
        tag_dict[ contents[i] ] = contents[i+1]
        i += 2
    
    return tag_dict



def construct_object_from_tag_internals(tags):
    
    obj_open = False #indicates if <form ...> seen but </form> not seen yet
    obj = {}
    #From here on we have a list of the contents of a tag.
    #Decide how to handle it

    object_type = tags[0][0]

    for tag_internals in tags: # the splitup tag internals of a single tag

        #form tag: beginning of form
        if(tag_internals[0]==object_type):

            # Create a new dictionary to store info
            tag_dict = {}
            tag_dict["tag_type"]=tag_internals[0]

            # insert key="value" pairs
            j=1
            while(j<len(tag_internals)):
                key=tag_internals[j]
                val=tag_internals[j+1]
                j+=2
                tag_dict[key] = val
            
            # other tags will be inside forms
            tag_dict["inside"] = []
            obj = tag_dict
            obj_open = True

        # /form tag : end of form
        elif(tag_internals[0]=="/{}".format(object_type)):
            obj_open=False #close out the obj


        # a tag: indicates hyperlinked text
        else: # elif(tag_internals[0]=="a" or tag_internals[0]=="input"):
            # Create a new dictionary to store info
            tag_dict={}
            tag_dict["tag_type"]=tag_internals[0]

            # insert key="value" pairs
            j=1
            while(j<len(tag_internals)):
                key=tag_internals[j]
                val=tag_internals[j+1]
                j+=2
                tag_dict[key]=val
            
            #append this tag into the form
            if(obj_open):
                    inside_list=obj["inside"]   #get
                    inside_list.append(tag_dict)  #append
                    obj["inside"]=inside_list   #put back

    return obj


# TOP LEVEL FUNCTION
# Input: HTML splashpage as bytes
# Returns a list of dictionaries. Each dictionary is a form:    
#   Pick a form by indexing into the list. Each form is a dictionary.   
#   Dictionary key value pairs are keys and values within that tag line:
#        ex from html: name="formname" method="POST"
#        becomes:   dict["name"] -> "formname"
#                   dict["method"] -> "POST"
def get_forms(html):
    
    if type(html) is not str:
        html = html.decode('utf-8') # int to str

    # each entry in list is "<form ...> <...> </form>" 
    forms = get_tags(html, "form")
    if(len(forms) == 0):
        return []
    #elif(len(forms) == 1): # caused if <form...> but bad html received no </form>
    #    forms = []      # get rid of previous bad entry
    #    ret_val = find_complete_string(html, "<form", "<html", 0) #WORKAROUND: by definition
    #    if(ret_val[0] == ""):
    #        return []   #gah lee you've just hit the worst written splashpage ever. just give up already
    #    forms.append(ret_val[0])

    print(forms)

    #break forms as strings into a list of tags: [form] = ["<form ...>", "<...>", "</form>"]
    all_forms = []
    for string in forms:
        ret = get_tags(string)
        all_forms.append(ret)
        
    print(all_forms)

    # split out each tag's internals
    i = 0
    while i < len(all_forms):
        tags = all_forms[i]
        j = 0
        while j < len(tags):
            tag = tags[j]
            all_forms[i][j] = breakup_tag(tag)
            j+=1
        i+=1
    
    print(all_forms)

    parsed_forms = []
    for form in all_forms:
        parsed_forms.append(construct_object_from_tag_internals(form))
    
    print(parsed_forms)

    return parsed_forms



def get_objects(html, object_type):
    
    if type(html) is not str:
        html = html.decode('utf-8') # int to str

    # each entry in list is "<form ...> <...> </form>" 
    forms = get_tags(html, object_type)
    if(len(forms) == 0):
        return []
    #elif(len(forms) == 1): # caused if <form...> but bad html received no </form>
    #    forms = []      # get rid of previous bad entry
    #    ret_val = find_complete_string(html, "<form", "<html", 0) #WORKAROUND: by definition
    #    if(ret_val[0] == ""):
    #        return []   #gah lee you've just hit the worst written splashpage ever. just give up already
    #    forms.append(ret_val[0])

    print(forms)

    #break forms as strings into a list of tags: [form] = ["<form ...>", "<...>", "</form>"]
    all_forms = []
    for string in forms:
        ret = get_tags(string)
        all_forms.append(ret)
        
    print(all_forms)

    # split out each tag's internals
    i = 0
    while i < len(all_forms):
        tags = all_forms[i]
        j = 0
        while j < len(tags):
            tag = tags[j]
            all_forms[i][j] = breakup_tag(tag)
            j+=1
        i+=1
    
    print(all_forms)

    parsed_forms = []
    for form in all_forms:
        parsed_forms.append(construct_object_from_tag_internals(form))
    
    print(parsed_forms)

    return parsed_forms


