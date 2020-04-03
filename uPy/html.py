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
        #Sprint("DEBUG: Finding specific tag")
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), "</{0}>".format(tag_type), ret_val[2] ) #start search at end of last string
            #print("DEBUG: object search attempt= {0}".format(ret_val))

            # tags that do make up objects. ex: <a ... > there is no </a>
            # start string found
            if(ret_val[1] != -1):
                if(ret_val[2] == -1): # end string was not found
                    ret_val = find_complete_string(html_as_string, "<{0}".format(tag_type), ">", ret_val[1] )
                    tag_list.append(ret_val[0])
                    #print("DEBUG: tag search attempt= {0}".format(ret_val))
                else: # end string was found
                    tag_list.append(ret_val[0])

    # look for all tags
    else:
        #print("DEBUG: Finding all tags")
        while ret_val[0] != "":
            # tags that don't make up objects. ex: <form ...> ... </form>
            ret_val = find_complete_string(html_as_string, "<", ">", ret_val[2] )
            tag_list.append(ret_val[0])
    
    return tag_list



def breakup_tag(tag):
    tag=tag.lstrip('<')
    tag=tag.rstrip('>')
    tag=tag.strip() #beg end whitespace
    #print("tag={0}".format(tag)) #print out the complete tag < ... >
        
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
    #print("type={0}\ttag={1}".format(ret,tag))
    contents_list.append(ret)
        
    while len(tag)>0:
        #print()

        #searching for key/value pair
        j=tag.find('=', 0, len(tag))
        if(j==-1):
            break #end if no keyval pairs

        key = tag[0:j] #pull out key
        tag = tag[j+1:len(tag)]
        key = key.strip(' ')
        #print("key={0}\ttag={1}".format(key,tag))
        contents_list.append(key)
    
        #key found, pull "value"
        #pull val inbetween quotes
        j = tag.find('"', 0, len(tag)) #first quote
        tag=tag[j+1:len(tag)]
        j = tag.find('"', 0, len(tag)) #second quote
        val=tag[0:j].strip()
        tag = tag[j+1:len(tag)]
        #print("val={0}\ttag={1}".format(val,tag))
        contents_list.append(val)

    return contents_list



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
            tagDict["tag_type"]=tag_internals[0]
            #print("tagDict[tag_type]= form")

            # insert key="value" pairs
            j=1
            while(j<len(tag_internals)):
                key=tag_internals[j]
                val=tag_internals[j+1]
                j+=2
                tagDict[key] = val
                #print("\ttagDict[{0}]={1}".format(key,val))
            
            # other tags will be inside forms
            tagDict["inside"] = []
            form = tagDict
            formOpen = True

        # /form tag : end of form
        elif(tag_internals[0]=="/form"):
            #print("\ttag_type=/form")
            formOpen=False #close out the form


        # a tag: indicates hyperlinked text
        elif(tag_internals[0]=="a" or tag_internals[0]=="input"):
            # Create a new dictionary to store info
            tagDict={}
            tagDict["tag_type"]=tag_internals[0]
            #print("\ttagDict[\"tag_type\"]={0}".format(tag_internals[0]))

            # insert key="value" pairs
            j=1
            while(j<len(tag_internals)):
                key=tag_internals[j]
                val=tag_internals[j+1]
                j+=2
                tagDict[key]=val
                #print("\ttagDict[\"{0}\"]={1}".format(key,val))
            
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
    elif(len(forms) == 1): #caused if <form...> but bad html received no </form>
        forms = []      #get rid of previous bad entry
        ret_val = find_complete_string(html, "<form", "</div", 0) #WORKAROUND: try going until the end of the next div
        if(ret_val[0] == ""):
            return []   #gah lee you've just hit the worst written splashpage ever. just give up already
        forms.append(ret_val[0])
    
    #debugging
    print("All forms as complete strings:")
    i=0
    while i < len(forms):
        print( "form[{0}]=\n{1}".format(i, forms[i]) )
        i+=1


    #break forms as strings into a list of tags: [form] = ["<form ...>", "<...>", "</form>"]
    all_forms = []
    for string in forms:
        print("Before pulling out tags: {0}".format(string))
        ret = get_tags(string)
        all_forms.append(ret)
        print("After pulling out tags: {0}".format(ret))

    #debugging
    print("\nEach form broken into a list of strings:")
    i=0
    while i < len(all_forms):
        print( "form[{0}]=".format(i) )
        for tag in all_forms[i]:
            print(tag)
        i+=1

    # split out each tag's internals
    print("\nSplitting up tag internals:")
    i = 0
    while i < len(all_forms):
        tags = all_forms[i]
        j = 0
        while j < len(tags):
            tag = tags[j]
            print("Tag before breakup: {0}".format(tag))
            all_forms[i][j] = breakup_tag(tag)
            print("After Breakup Form[{0}] tag[{1}]: {2}".format(i, j, all_forms[i][j]) )
            j+=1
        i+=1
    

    parsed_forms = []
    for form in all_forms:
        parsed_forms.append(construct_form_from_tag_internals(form))
        print("Complete forms as structures:")
        print(parsed_forms)
    
    return parsed_forms



def get_internal_form_data(form):
    return form["inside"]
