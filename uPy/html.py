# ---------------------------------------
#  _____  __  __ _______        __   ___  
# |  __ \|  \/  |__   __|      /_ | / _ \ 
# | |__) | \  / |  | |    __   _| || | | |
# |  ___/| |\/| |  | |    \ \ / / || | | |
# | |    | |  | |  | |     \ V /| || |_| |
# |_|    |_|  |_|  |_|      \_/ |_(_)___/ 
# ----------------------------------------
#
#   Returns a list of dictionaries. Each dictionary is a form:
#       
#   Pick a form by indexing into the list. Each form is a dictionary.
#      
#   Dictionary key value pairs are keys and values within that tag line:
#        ex from html: name="formname" method="POST"
#        becomes:   dict["name"] -> "formname"
#                   dict["method"] -> "POST"

def get_forms(html):
    # NEEDS TESTING
    currentForm = -1
    forms = []
    formOpen = False #indicates if <form ...> seen but </form> not seen yet

    #int to str
    html = html.decode('utf-8')

    # empty condition: give back empty dict
    if(html == ''):
        return []
    
    # Note: Tags can end on same line they were created on

    i = html.find('<form', 0, len(html)-1)
    print("Entering Form parse loop")
    while i != -1:
        
        #debugging
        print("Tag Detected: <")

        # find postion of b'>' starting after b'<' 
        endpos=html.find('>', i, len(html)-1 )
        print("endpos={0}".format(endpos))

        # '>' not found in html. tag starts but does not terminate
        if(endpos==-1):
            print("\tError: Tag does not terminate. No >")
            print(html[i:len(html)]) #print out the rest of the html for debugging
            return []
        
        # complete tag found '<' and '>'
        else:
            # pull out '<' up to '>'
            tag=html[ i:endpos ]

            # catch <>
            if(len(tag) < 1):
                print("\tError: Zero length after split. Skipping")
                continue
            
            tag=tag.lstrip('<')
            #tag=tag.rstrip('>')
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

            tag = tag_list
            print("\tTag split:{0}\n".format(tag))
            
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
            
            #end of this tag, what to get next?
            if formOpen: # this form has not closed yet
                i = html.find('<', i, len(html)-1)
            else: #end of form, look for next one
                i = html.find('<form', i, len(html)-1)

    return forms


def get_form_data(form):
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

                tag = tag_list
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
