# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#  Version 1.0
#  microPython Firmware esp32spiram-idf3-20191220-v1.12
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
    if i == -1:
        return ["",-1,-1] # only return a valid string
    j = html_as_string.find(str(end_string), i, len(html_as_string))
    if j == -1:
        return ["",i,-1] # only return a valid string
    
    j = j+len(end_string) # include end_string in the string
    return [html_as_string[i:j], i, j]



def get_tags(html_as_string, tag_type=None):
    tag_list = []
    i=0
    j=0
    ret_val = ["_",i,j]
    
    # look for a specific tag
    if tag_type is not None:
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), "</{0}>".format(tag_type), ret_val[2] ) #start search at end of last string

            # tags that do make up objects. ex: <a ... > there is no </a>
            # start string found
            if(ret_val[1] != -1):
                if(ret_val[2] == -1): # end string was not found
                    ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), ">", ret_val[1] )
                    tag_list.append(ret_val[0])
                else: # end string was found
                    tag_list.append(ret_val[0])

    # look for all tags
    else:
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<", ">", ret_val[2] )
            tag_list.append(ret_val[0])
    
    return tag_list



def breakup_tag(tag):
    tag=tag.lstrip('<')
    tag=tag.rstrip('>')
    tag=tag.strip() #beg end whitespace
        
    #time to split up elements within the tag
    #cannot just split by spaces values can have spaces between quotes
    j=0
    contents_list =[]
    
    # pull out type
    j=tag.find(' ', 0, len(tag))
    if(j == -1): #ex: </form>
        ret=tag
    else:       #ex: <form method="POST" ... >
        ret=tag[0:j]
    
    tag=tag[j+1:len(tag)]
    ret=ret.strip()
    contents_list.append(ret)
        
    while len(tag)>0:

        #searching for key/value pair
        j=tag.find('=', 0, len(tag))
        if(j==-1):
            break #end if no keyval pairs

        key = tag[0:j] #pull out key
        tag = tag[j+1:len(tag)]
        key = key.strip(' ')
        contents_list.append(key)
    
        #key found, pull "value"
        #pull val inbetween quotes
        j = tag.find('"', 0, len(tag)) #first quote
        tag=tag[j+1:len(tag)]
        j = tag.find('"', 0, len(tag)) #second quote
        val=tag[0:j].strip()
        tag = tag[j+1:len(tag)]
        contents_list.append(val)

    return contents_list



def construct_form_from_tag_internals(tags):
    
    form_open = False #indicates if <form ...> seen but </form> not seen yet
    form = {}
    #From here on we have a list of the contents of a tag.
    #Decide how to handle it

    for tag_internals in tags: # the splitup tag internals of a single tag

        #form tag: beginning of form
        if(tag_internals[0]=="form"):

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
            form = tag_dict
            form_open = True

        # /form tag : end of form
        elif(tag_internals[0]=="/form"):
            form_open=False #close out the form


        # a tag: indicates hyperlinked text
        elif(tag_internals[0]=="a" or tag_internals[0]=="input"):
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
            if(form_open):
                    inside_list=form["inside"]   #get
                    inside_list.append(tag_dict)  #append
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
    
    if html is not str:
        html = html.decode('utf-8') # int to str

    # each entry in list is "<form ...> <...> </form>" 
    forms = get_tags(html, "form")
    if(len(forms) == 0):
        return []
    elif(len(forms) == 1): #caused if <form...> but bad html received no </form>
        forms = []      #get rid of previous bad entry
        ret_val = find_complete_string(html, "<form", "</div", 0) #WORKAROUND: try going until the end of the next div
        if(ret_val[0] == ""):
            return []   #gah lee you've just hit the worst written splashpage ever. just give up already
        forms.append(ret_val[0])


    #break forms as strings into a list of tags: [form] = ["<form ...>", "<...>", "</form>"]
    all_forms = []
    for string in forms:
        ret = get_tags(string)
        all_forms.append(ret)
        

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
    

    parsed_forms = []
    for form in all_forms:
        parsed_forms.append(construct_form_from_tag_internals(form))
    
    return parsed_forms
